#include "MustGoRaspi.h"

bool videoStartFlag;
bool videoStatusFlag;

int main(void)
{
    uuid_t uuid;
    char uuid_str[37];

    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);

    printf("Generated UUID : %s\n", uuid_str);

    return 0;
}
