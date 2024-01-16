#include <curl/curl.h>
#include "MustGoRaspi.h"

void convertUuidToJsonBody(struct HttpRequest *request)
{
    uuid_t uuid;
    char uuid_str[37];
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);

    char dynamicJson[60];

    printf("Generated UUID : %s\n", uuid_str);

    snprintf(dynamicJson, sizeof(dynamicJson), "{\"UUID\":\"%s\"}", uuid_str);
    request->jsonBody = strdup(dynamicJson);
}

void sendHttpRequset(const struct HttpRequest *request)
{
    CURL *curl;
    CURLcode res;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        // dest URL
        char url[30];
        snprintf(url, sizeof(url), "http://52.78.159.10%s", request->path);
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // POST
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request->method);

        // headers
        struct curl_slist *headers = NULL;
        for (int i = 0 ; request->headers[i] != 0 ; i += 2)
        {
            char header[30];
            snprintf(header, sizeof(header), "%s:%s", request->headers[i], request->headers[i+1]);
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // json body
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request->jsonBody);

        res = curl_easy_perform(curl);
        printf("HTTP request res : %d\n", (int)res);

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        curl_global_cleanup();
    }
}

