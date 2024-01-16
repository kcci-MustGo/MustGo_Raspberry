#include "MustGoRaspi.h"

bool videoStartFlag;
bool videoStatusFlag;
const char *httpRequestHeaders[] = 
{
    "Connection", "close",
    "Content-type", "application/json",
    "Accept", "application/json",
    "Content-Length", "",
    0
};

int main(void)
{
    struct HttpRequest addUserRequest = {
        .method = "POST",
        .path = "/db/addUser",
        .headers = httpRequestHeaders,
        .jsonBody = NULL
    };
    convertUuidToJsonBody(&addUserRequest);
    sendHttpRequset(&addUserRequest);
    

    return 0;
}
