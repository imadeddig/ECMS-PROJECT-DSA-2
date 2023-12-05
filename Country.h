#ifndef COUNTRY_H
#define COUNTRY_H
#include "Region.h"
#include "Customer.h"
#include <iostream>
#include <vector>
using namespace std;

class Country
{
private:
    string countryName;
    string countryID;
    vector<Region> regions;

public:
    // open a region file, regions id should be "countryid-regionid", search for regions that has the same countryID as this instance, if so, call region constructor and insert the new object into the region vector
    Country(string, string);
    string getCountryName();
    string getCountryID();
    vector<Region> getCountryRegions();
   
};
#endif
