#ifndef weatherH
#define weather_H
#include <list>
#include <vector>
#include <iostream>
using namespace std;
// The District class should contain this HashWeather table
// this hash table contains years,
// and each year conatains the year number(the data) and a pointer to a list of days,
// and each day contains the number of the day and month and informations about the weather in that specific day(temp,type of weather..)
struct DayWeather // start of the DayWeather struct
{
    enum TypeDay // the weather takes only one of the following values
    {
        SUNNY,
        SNOWY,
        CLOUDY,
        RAINY
    };
    int dayNum;   // we can use the approach of enum on the dayNum since it's always between 1 and 31 same goes for month(should we do it or ignore it????)
    int monthNum; // helps to avoid confusion and better organising of the dayNum
    double maxTemp;
    double minTemp;
    int sunnyHours;
    TypeDay weather; // to indicate whether the day is sunny,rainy...
    DayWeather(const int &DN, const int &MN, const double &MT, const double &MIT, const int &SH, const string &W) : maxTemp(MT), minTemp(MIT)
    {
        dayNum = (DN > 0 && DN < 32) ? DN : 0;
        monthNum = (MN > 0 && MN < 13) ? MN : 0;
        sunnyHours = (SH > 0) ? SH : 0;
        if(W=="S")
        {
            weather = SUNNY;
        } 
        else if(W=="SN"){
            weather = SNOWY;
        }
        else if(W=="C"){
            weather = CLOUDY;
        }
        else{
            weather = RAINY;
        }
        // set sunny as a default value to be discussed!!!!
    }      
    void printWeatherDay()
    {
        cout << "Day: " << dayNum << " , Month: " << monthNum << endl;
        cout << "The Maximum Temperature: " << maxTemp << endl;
        cout << "The Minimum Temperature: " << minTemp << endl;
        cout << "The  Number of Sunny Hours: " << sunnyHours << endl;
        cout << "The Type of The Weather: " << weather << endl;
    }
    
}; // end of the DayWeather struct
struct YearWeather // start of the YearWeather struct
{
public:
    int yearNum;
    vector<DayWeather> days; // should be initialized according to the year because the number of days is different from one year to another(should we take in consideration????)
};

    class HashWeather
{





public:
    explicit HashWeather();
    bool isFull();                 // chech if the size of the vector equal to the current size
    int hashFunction(const int &);
    int currentSize; // the maximum size of the hash table
    vector<YearWeather> yearsweather;
    // the hash function that takes the yearNUm and returns its index in the hash table
};

#endif

// problems

// 1: the default value of the weather(from the file )
// 2: the default value of the size of the dayweather list(according to the year or not)  (from the file)
// 4: putting the struct day weather outside the class will ruin the encapsulation law unless we set the weatherday as a class with setters and getters
// 5: should we add a constructor for rvaluee in all of our classes
// 6: what is the starting year and what about the size of our "hash table"