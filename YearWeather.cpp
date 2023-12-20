#include "YearWeather.h"
#include "fstream"
using namespace std;
#include <iostream>

HashWeather::HashWeather()
{
    cout<<"star yeather";
   
    currentSize = 10;
    yearsweather.resize(currentSize);
    for (int i = 0; i < currentSize;i++)
    {
        yearsweather[i].yearNum = 0; 
    }
     cout<<"end yeather";
}




bool HashWeather::isFull()
{
    return (yearsweather.size() / currentSize)>=1;
    
}

int HashWeather::hashFunction(const int &key)
{
    return (key - 2020);
}
