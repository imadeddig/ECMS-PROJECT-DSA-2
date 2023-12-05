#ifndef CITY_H
#define CITY_H
#include <iostream>
#include "Department.h"
#include "./District.h"
#include <string>
using namespace std;
#include<vector>

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
