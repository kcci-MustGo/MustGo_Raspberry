#include "MustGoRaspi.h"

bool videoStartFlag;
bool videoStatusFlag;
bool connectFlag;
char *httpRequestHeaders[] = 
{
    "Connection", "close",
    "Content-type", "application/json",
    "Accept", "application/json",
    "Content-Length", "",
    NULL
};

int main(void)
{
    struct HttpRequest request_ = {
        .method = "POST",
        .path = NULL,
        .headers = httpRequestHeaders,
        .jsonBody = NULL
    };
    request_.path = strdup("/db/addUser");

    struct returnRequest req =
    {
        .buffer = NULL,
        .len = 0,
        .bufLen = 0
    };

    convertUuidToJsonBody(&request_);
    req = sendHttpRequest(&request_);

    if (connectFlag)
    {
        request_.path = strdup("/db/getRoute");
        printf("pass first\n");
        req = sendHttpRequest(&request_);
        printf("pass second\n");
        printf("req len : %ld\n", req.len);
        printf("req data : %s\n", req.buffer);
    }
    

    return 0;
}
