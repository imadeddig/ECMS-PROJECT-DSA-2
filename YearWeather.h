#ifndef WEATHERH
#define WEATHER_H
#include<list>
#include<vector>
#include<iostream>
using namespace std;
//The District class should contain this HashWeather table instaid of climate
//this hash table contains years, 
//and each year conatains the year number(the data) and a pointer to a list of days, 
//and each day contains the number of the day and month and informations about the weather in that specific day(temp,type of weather..)
 struct DayWeather // start of the DayWeather struct
    {
        enum TypeDay // the weather takes only one of the following values
        {
            SUNNY,
            SNOWY,
            CLOUDY,
            RAINY
        };
        int DayNum;   // we can use the approach of enum on the dayNum since it's always between 1 and 31 same goes for month(should we do it or ignore it????)
        int MonthNum; // helps to avoid confusion and better organising of the daynum
        double MaxTemp;
        double MinTemp;
        int SunnyHours;
        TypeDay Weather; // to indicate whether the day is sunny,rainy...
        bool isValidWeather(TypeDay w)
        { // a function to check whether the value of typeday is correct in the constructor
            return (w == SUNNY || w == SNOWY || w == CLOUDY || w == RAINY);
        }
        DayWeather(const int& DN,const int& MN,const double& MT,const double& MIT,const int& SH,const TypeDay& W):MaxTemp(MT),MinTemp(MIT)
        {
            DayNum = (DN > 0 && DN < 32) ? DN : 0;
            MonthNum = (MN > 0 && MN < 13) ? MN : 0;
            SunnyHours = (SH > 0 )? SH : 0;
            Weather = isValidWeather(W) ? W : SUNNY;//set sunny as a default value to be discussed!!!!
        }//constructor for lvalue
        //should we add a constructor for rvaluee??
}; // end of the DayWeather struct

class HashWeather
{
private:
   
struct YearWeather // start of the YearWeather struct
{ 
    int YearNum;
    list<DayWeather> Days;//should be initialized according to the year because the number of days is different from one year to another(should we take in consideration????)
    YearWeather(const int& YN,const int& s):YearNum(YN)//I didn't figure out how to put a condition on the year according to the exsiting years in our system
    {
        Days.resize(s);//the number of day in a year is the value of s(the size)should be add it to the entities
    }

};// end of the YearWeather struct

int CurrentSize;//the maximum size of the hash table
vector<YearWeather> YearsWeather;

public:
    explicit HashWeather(const int &CS);
    bool addYear(const YearWeather &);//to add a new year lvalue
    bool addYear(const YearWeather &&);// to add a new year rvalue
    bool contains(const YearWeather &);
    bool isFull();//cjheck using the load factor when will be equal to 1 since we don't have collisions
    int hashFunction(const int &);//the hash function that takes the yearNUm and returns its index in the hash table
    void rehash();//to resize the hash table when it becomes full
};


#endif
