#ifndef CITY_H
#define CITY_H
#include <iostream>
#include "Department.h"
#include "District.h"
#include <string>
#include<vector>
using namespace std;

class City
{
private:
    string cityID;
    string cityName;
    vector<District> Districts;
    Department cityDepartement;
   

public:
    City(string, string);
    Department getDepartment();
    void setcityname(string) ;
    string getCityName();
    string getCityID();
    vector<District> getDistricts();
    ~City();

    
};

#endif
