#include "District.h"
int District::districtIDCounter=0;
District::District(const string &DistrictNameDef="")
{
    districtID = DistrictNameDef;
    districtID=districtIDCounter;
    districtIDCounter++;
    //ID will be generated here
}

int District::getDistrictID()
{
    return districtID;
}

string District::getDistrictName()
{
    return districtName;
}

BinarySearchTree District::getCustomers()
{
    return customersTree;
}

vector<weather> District::getClimate()
{
    return climate;
}
