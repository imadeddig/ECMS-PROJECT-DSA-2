#include "YearWeather.h"
#include "fstream"
using namespace std;
#include <iostream>

HashWeather::HashWeather()
{
    currentSize = 10;
    yearsweather.resize(currentSize);
    for (int i = 0; i < currentSize;i++)
    {
        yearsweather[i].yearNum = 0; //to avoid confusion
    }
    fstream weatherFile;
    weatherFile.open("weathers.txt");
    string line;
    getline(weatherFile,line);
    while (getline(weatherFile,line))
    {
        string year = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        int index = hashFunction(stoi(year));
        if(yearsweather[index].yearNum==0)
        {
            yearsweather[index].yearNum = stoi(year);
        }
        string month = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        string day = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        string maxtemp = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        string mintemp = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        string sunnyhours = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        string daytype = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);

        DayWeather dayweather(stoi(month), stoi(day), stod(maxtemp), stod(mintemp), stoi(sunnyhours), daytype);
        yearsweather[index].days.push_back(dayweather);

        if(isFull)

        {
            YearWeather a;
            a.yearNum = 0;
            yearsweather.push_back(a);
        }
    }

    weatherFile.close();
}




bool HashWeather::isFull()
{
    return (yearsweather.size() / currentSize)>=1;
    
}

int HashWeather::hashFunction(const int &key)
{
    return (key - 2020);
}
