#include "MustGoRaspi.h"
#include <math.h>

void getVector(struct moveInfo *movementList, char **latitudeList, char**longitudeList, int listSize)
{
    double latiPrev = convertStrToDouble(latitudeList[0]);
    double longiPrev = convertStrToDouble(longitudeList[0]);
    double latiNext = 0.0;
    double longiNext = 0.0;
    for ( int i = 1 ; i <= listSize ; i++)
    {
        latiNext = convertStrToDouble(latitudeList[i]);
        longiNext = convertStrToDouble(longitudeList[i]);
        
        // distance
        double dlat = (latiPrev - latiNext) * M_PI / 180.0;
        double dlon = (longiPrev - longiNext) * M_PI / 180.0;
        double a = sin(dlat/2) * sin(dlat/2) + 
            cos(latiPrev*M_PI/180.0) * cos(latiNext*M_PI/180.0) * sin(dlon/2) * sin(dlon/2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        double distance_ = 6371000 * c;


        // direction
        /*
        double x = cos(latiPrev * M_PI / 180.0) * sin(dlon);
        double y = cos(latiPrev * M_PI / 180.0) * sin(latiNext * M_PI / 180.0) -
            sin(latiPrev * M_PI / 180.0) * cos(latiNext * M_PI / 180.0) * cos(dlon);
        double direction_ = fmod((atan2(x,y) * 180.0 / M_PI + 360.0), 360.0);
        */
        double x = cos(latiNext * M_PI / 180.0) * sin(dlon);
        double y = cos(latiPrev * M_PI / 180.0) * sin(latiNext * M_PI / 180.0) -
            sin(latiPrev * M_PI / 180.0) * cos(latiNext * M_PI / 180.0) * cos(dlon);
        double direction_ = fmod((atan2(y,x) * 180.0 / M_PI + 360.0), 360.0);

        movementList[i-1].distance = distance_;
        movementList[i-1].direction = direction_;
        latiPrev = latiNext;
        longiPrev = longiNext;
    }
    /*
    for ( int i = 1 ; i < listSize ; i++)
        movementList[i].direction -= movementList[0].direction;
    movementList[0].direction = 0;
    */
    
    for ( int i = listSize-1 ; i > 0 ; i-- )
        movementList[i].direction -= movementList[i-1].direction;
    movementList[0].direction = 0;
    

}

double convertStrToDouble(char* value)
{
    double ret = 0;
    int idx = 0;
    double digit = 10;
    while (value[idx] != '.')
    {
        ret = ret*digit + (value[idx]-'0');
        idx++;
    }
    digit = 10;
    idx++;
    while (value[idx] != '\0')
    {
        ret += (value[idx]-'0')/digit;
        digit *= 10;
        idx++;
    }

    return ret;
}
