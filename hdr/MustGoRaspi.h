#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <uuid/uuid.h>
#include <stdbool.h>

#define CHUNK_SIZE 2048

struct HttpRequest 
{
    char *method;
    char *path;
    char **headers;
    char *jsonBody;
};

struct returnRequest
{
    unsigned char *buffer;
    size_t len;
    size_t bufLen;
};

extern char *httpRequestHeaders[];
extern bool connectFlag;
extern bool destFlag;
extern bool videoStartFlag;
extern bool videoStatusFlag;
extern char currentPosLatitude[];
extern char currentPosLongitude[];
extern char jsonData[];

void convertUuidToJsonBody(struct HttpRequest *request);
struct returnRequest sendHttpRequest(const struct HttpRequest *request);
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
