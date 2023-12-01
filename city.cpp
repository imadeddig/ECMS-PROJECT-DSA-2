#include"city.h"
#include <iostream>

using namespace std ;



city::city(string name , int id)
{
    setnamecity(name);
   
}

inline void city::setnamecity(string name, )
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

inline string city::getnamecity()
{
    return cityname;
}

inline void city::setcityid(int id)
{

    cityid=id ;
   
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
