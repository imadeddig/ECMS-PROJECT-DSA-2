#ifndef CITY_H
#define CITY_H
#include<iostream>
#include "Department.h"
#include "District.h"
#include<string>
using namespace std;
#include<vector>

class City
{
private:
string cityID;
string cityName ;
vector<District> Districts;
Department cityDepartement;

public:
    City(string,int);
    Department getDepartment();
    string getCityName();
     int getCityID();
    vector<District> getDistricts();   
    ~City();

    Customer getCityWinner();
};

#endif
