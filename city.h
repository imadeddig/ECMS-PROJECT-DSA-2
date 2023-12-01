#ifndef city_h
#define city_h

#include<iostream>

#include<string>

#include<vector>

#include"dipartement.h"



class city
{
private:

int cityid ;
string cityname ;
static idcity ;
vector<district>districts;

dipartement cityDepartement;

public:
    city();
    void setname(string name); 
    dipartement getdipartement();
    string getname();
     void setcityid();
    string getcityid();
    vector getdistrict();
   

    ~city();
};


#endif