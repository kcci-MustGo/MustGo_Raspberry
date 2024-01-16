#include "MustGoRaspi.h"

bool videoStartFlag;
bool videoStatusFlag;
const char *currentPosHeaders[] = 
{
    "Connection", "close",
    "Content-type", "application/json",
    "Accept", "application/json",
    "Content-Length", "",
    0
};

const char *currentVideoHeaders[] = 
{
    "Connection", "close",
    "Content-type", "application/json",
    "Accept", "application/json",
    "Content-Length", "",
    0
};

int main(void)
{
    uuid_t uuid;
    char uuid_str[37];

    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);

    printf("Generated UUID : %s\n", uuid_str);

    return 0;
}
