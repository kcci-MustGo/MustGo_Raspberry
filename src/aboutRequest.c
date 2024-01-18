#include <curl/curl.h>
#include "uuid/uuid.h"
#include "MustGoRaspi.h"

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t realsize = size * nmemb;
    struct returnRequest *req = (struct returnRequest *) userdata;

    printf("receive chunks of %zu bytes\n", realsize);

    while (req->bufLen < (req->len + realsize + 1))
    {
        req->buffer = realloc(req->buffer, req->bufLen + CHUNK_SIZE);
        req->bufLen += CHUNK_SIZE;
    }
    memcpy(&req->buffer[req->len], ptr, realsize);
    req->len += realsize;
    req->buffer[req->len] = 0;

    return realsize;
}

void convertDataToJsonBody(struct HttpRequest *request)
{
    uuid_t uuid;
    char uuid_str[37];
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);

    char dynamicJson[100];

    snprintf(dynamicJson, sizeof(dynamicJson), "{\"UUID\":\"%s\",\"LATITUDE\":\"%s\",\"LONGITUDE\":\"%s\"}", uuid_str, currentPosLatitude, currentPosLongitude);
    request->jsonBody = strdup(dynamicJson);
    //printf("jsonBody in convert func : %s\n", request->jsonBody);
}

struct returnRequest sendHttpRequest(const struct HttpRequest *request)
{
    CURL *curl;
    CURLcode res;
    struct returnRequest returnReq =
    {
        .buffer = NULL,
        .len = 0,
        .bufLen = 0
    };
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        // dest URL
        char url[35];
        snprintf(url, sizeof(url), "http://52.78.159.10%s", request->path);
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // POST
        //curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request->method);
        curl_easy_setopt(curl, CURLOPT_POST, 1);

        // headers
        struct curl_slist *headers = NULL;
        char tmp7[5];
        sprintf(tmp7, "%ld", strlen(request->jsonBody));
        //printf("strlen: %ld\n", strlen(request->jsonBody));
        //printf("headers[6] : %s\n", request->headers[6]);
        //printf("headers[7] : %s\n", request->headers[7]);
        request->headers[7] = strdup(tmp7);
        for (int i = 0 ; request->headers[i] != NULL ; i += 2)
        {
            char header[40];
            snprintf(header, sizeof(header), "%s:%s", request->headers[i], request->headers[i+1]);
            headers = curl_slist_append(headers, header);
        }
        /*
        for (struct curl_slist *header = headers ; header != NULL ; header = header->next)
            printf("header : %s\n", header->data);
        */
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // json body
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request->jsonBody);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(request->jsonBody));


        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&returnReq);
        printf("curl_perform\n");
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            returnReq.err = 1;
        if (connectFlag==false && res==CURLE_OK)
            connectFlag = true;

        //fprintf(stderr, "res msg : %d %s\n", (int)res, curl_easy_strerror(res));
        //
        

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        curl_global_cleanup();

        return returnReq;
    }
    return returnReq;
}

