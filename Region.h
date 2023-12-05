#ifndef REGION_H
#define REGION_H
#include <iostream>
#include "City.h"
#include "Customer.h"
#include <vector>
using namespace std;
class Region{
    private:
    string regionName;
    string regionID;
    vector <City> cities;
    public:
    //open a region file, regions id should be "countryid-regionid", search for regions that has the same countryID as this instance, if so, call region constructor and insert the new object into the region vector
    Region(string,string);
    string getRegionName();
    //transform string to int
    string getRegionID();
    vector<City> getRegionCities();
};
#endif
