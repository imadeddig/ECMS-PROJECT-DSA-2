#ifndef DISTRICT_H
#define DISTRICT_H
#include <string>
#include "YearWeather.h"
#include <iostream>
using namespace std;
#include <vector>
class District
{
    private:
    string districtName;
    string districtID;
    int numOfCustomers;
    //customers that are in that region
    BinarySearchTree* customersTree; //is it pointer?
    HashWeather  climate;//linked list of weather day
    //got confused between different years
    //each year should have 12months array, each mon,th should have at max 31array of days, each day should have a specific weather
//for ids, there should be a counter globally in order to set the id

    public:
    District(const string& DistrictNameDef);
    int getDistrictID();
    string getDistrictName();
    BinarySearchTree* getCustomers();
    DayWeather getDayWeather(int day&, int month&, int year&);
    HashWeather getWeather();
};
#endif
