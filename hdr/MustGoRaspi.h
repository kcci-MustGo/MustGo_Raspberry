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

struct HttpRequest 
{
    const char *method;
    const char *path;
    char *headers[10];
    char *jsonBody;
};
extern const char *httpRequestHeaders[];
extern bool destFlag;
extern bool videoStartFlag;
extern bool videoStatusFlag;
extern char currentPosLatitude[];
extern char currentPosLongitude[];
extern char jsonData[];

void convertUuidToJsonBody(struct HttpRequest *request);
void sendHttpRequset(const struct HttpRequest *request);
