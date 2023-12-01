#include"city.h"
#include <iostream>

using namespace std ;

int city::idcity=0 ;

city::city()
{
    cityid=idcity;
    idcity++;
}

inline void city::setname(string name)
{
    if (name!='')
    {
        cityname =name ;
    }
    
}

dipartement city::getdipartement()
{
    return dipartement;
}

inline string city::getname()
{
    return cityname;
}

inline void city::setcityid()
{

    idcity = cityid ;
    idcity++ ;
}

inline string city::getcityid()
{
    return cityid;
}

inline vector city::getdistrict()
{
    return districts;
}

city::~city()
{
}
