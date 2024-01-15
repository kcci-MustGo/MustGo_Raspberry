#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <uuid/uuid.h>
#include <stdbool.h>

extern const char *currentPosHeaders[] = 
{
    "Connection", "close",
    "Content-type", "application/json",
    "Accept", "application/json",
    "Content-Length", "",
    0
};

extern const char *currentVideoHeaders[] = 
{
    "Connection", "close",
    "Content-type", "application/json",
    "Accept", "application/json",
    "Content-Length", "",
    0
};

extern bool destFlag;
extern bool videoStartFlag;
extern bool videoStatusFlag;
extern char currentPosLatitude[];
extern char currentPosLongitude[];
extern char jsonData[]

