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

vector<district>districts;

dipartement cityDepartement;

public:
    city(string);
    void setnamecity(string name); 
    dipartement getdipartement();
    string getnamecity();
     void setcityid(int);
    string getcityid();
    vector getdistrict();
   

    ~city();
};


#endif
