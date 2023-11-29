#ifndef REGION_H
#define REGION_H
#include <string>
#include <iostream>
using namespace std;
#include <vector>


class Region
{
    private:
    string regionName;
    int regionID;
    vector <city> cities;
    static int regionIDCounter;

    public:
    Region(const string&regionNameDef);
    ~Region();
    string getRegionName();
    int getRegionID();
    vector <city> getCities();
};
#endif