#include "MustGoRaspi.h"

bool videoStartFlag;
bool videoStatusFlag;
bool connectFlag;
bool currentPosFlag;
char currentPosLatitude[20];
char currentPosLongitude[20];
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
    struct returnRequest req =
    {
        .buffer = NULL,
        .len = 0,
        .bufLen = 0,
        .err = 0
    };
    struct HttpRequest request_ = {
        .method = "POST",
        .path = NULL,
        .headers = httpRequestHeaders,
        .jsonBody = NULL
    };
    request_.path = strdup("/db/addUser");


    // TEMPORARY CURRENT POSITION ALLOC
    strcpy(currentPosLatitude, "126.841016");
    strcpy(currentPosLongitude, "37.542496");

    convertDataToJsonBody(&request_);
    while ( !currentPosFlag)
    {
        if (strlen(currentPosLatitude) != 0)
        {
            printf("currentPosLatitude length %ld\n", strlen(currentPosLatitude));
            currentPosFlag = true;
            break;
        }
        printf("no currentPosLatitude\n");
        usleep(5000000);
    }


    req = sendHttpRequest(&request_);
    if (connectFlag)
    {
        while (1)
        {
            request_.path = strdup("/db/getRoute");
            req = sendHttpRequest(&request_);
            if (req.err != 1)
            {
                char *pathTotal = (char*)malloc(strlen((char*)req.buffer)+1);
                memcpy(pathTotal, req.buffer, strlen((char*)req.buffer)+1);
                strcpy(pathTotal, (char*)req.buffer);
                //printf("req len : %ld\n", req.len);

                if (*(pathTotal+8) != 'X')
                    {
                    size_t numOfPos = 0;
                    int tempDelForPathTotal = 0;
                    while (*(pathTotal+tempDelForPathTotal) != '\0')
                    {
                        if (*(pathTotal+tempDelForPathTotal) == ',')
                            numOfPos++;
                        tempDelForPathTotal++;
                    }
                    numOfPos = (numOfPos+1)/2;
                    printf("numOfPos : %ld\n", numOfPos);

                    char **latitudeList = (char**)malloc((numOfPos+1)*sizeof(char*));
                    char **longitudeList = (char**)malloc((numOfPos+1)*sizeof(char*));
                    for ( int i = 0 ; i <= numOfPos ; i++)
                    {
                        latitudeList[i] = (char*)malloc(15*sizeof(char));
                        longitudeList[i] = (char*)malloc(15*sizeof(char));
                        if (longitudeList[i] == NULL || latitudeList[i] == NULL)
                            printf("err in malloc lati logi ELEMNT\n");
                    }
                    strcpy(latitudeList[0], currentPosLatitude);
                    latitudeList[0][strlen(currentPosLatitude)] = '\0';
                    strcpy(longitudeList[0], currentPosLongitude);
                    longitudeList[0][strlen(currentPosLongitude)] = '\0';
    
                    const char *idxStart = strstr(pathTotal, "\"[[");
                    const char *idxEnd = strstr(pathTotal, "]]\"");
                    size_t lenProcessed = idxEnd - (idxStart+3);
                    char *processedPath1 = (char*)malloc(sizeof(char)*(lenProcessed+1));
                    strncpy(processedPath1, idxStart+3, lenProcessed);
                    processedPath1[lenProcessed] = '\0';
                    //printf("processedPath1 : %s\n", processedPath1);
    
                    const char *del1 = "], [";
                    bool toggleForStrtokParsing = false;
                    int idxForMakeList = 1;
                    char *subStr1 = strtok(processedPath1, del1);
                    while (subStr1 != NULL)
                    {
                        if (toggleForStrtokParsing)
                        {
                            strcpy(longitudeList[idxForMakeList], subStr1);
                            longitudeList[idxForMakeList][strlen(subStr1)] = '\0';
                            idxForMakeList++;
                        }
                        else 
                        {
                            strcpy(latitudeList[idxForMakeList], subStr1);
                            latitudeList[idxForMakeList][strlen(subStr1)] = '\0';
                        }
                        toggleForStrtokParsing = !toggleForStrtokParsing;
                        subStr1 = strtok(NULL, del1);
                    }

                    struct moveInfo *movementList = (struct moveInfo*)malloc(sizeof(struct moveInfo)*numOfPos);
                    // get Vector List!
                    printf("start\n");
                    getVector(movementList, latitudeList, longitudeList, numOfPos);
                    for ( int i = 0 ; i < numOfPos ; i++)
                    {
                        printf("movementList[%d] : direction(%f), distance(%f)",
                                i, movementList[i].direction, movementList[i].distance);
                        putchar('\n');
                    }
    
                    free(processedPath1);
                    free(pathTotal);
                    for ( int i = 0 ; i <= numOfPos ; i++)
                    {
                        free(latitudeList[i]);
                        free(longitudeList[i]);
                    }
                    free(movementList);
                    free(latitudeList);
                    free(longitudeList);

                }
                else
                    printf("still NO destination was entered\n");
            }
            // strtok to get pos
            // IF pos is x => while
            // ELSE calculate movement and write
            usleep(5000000);
        }
    }
    

    return 0;
}
