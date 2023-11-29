#include "Region.h"
int Region::regionIDCounter=0;
Region::Region(const string &regionNameDef="")
{
    regionName=regionNameDef;
    regionID=regionIDCounter;
    regionIDCounter++;
}

string Region::getRegionName()
{
    return regionName;
}

int Region::getRegionID()
{
    return regionID;
}

vector<city> Region::getCities()
{
    return cities;
}
