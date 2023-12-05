#include "Region.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// here we have to immeditely open the file, and search for all cities that matches that region, need to be initilaized
Region::Region(string regionName = "", string regionID = 0)
{
    // lazem hna neqsem id tae cities bch ymatchi li raho f region

    // csv file reference: https://iq.opengenus.org/read-and-write-in-csv-in-cpp/#google_vignette
    //textbook of last year was also took as reference
    regionName = regionName;
    regionID = regionID;
    ifstream citiesFile;
    citiesFile.open("cities.csv");
    if (!citiesFile)
    {
        cerr << "File could not be created." << endl;
        exit(1);
    }
    string line;
    getline(citiesFile, line);
    while (getline(citiesFile, line))
    {
        string cityID = line.substr(0, line.find_first_of(','));
        if (cityID.substr(0, cityID.find_last_of('-')) == regionID)
        {
            string cityName = line.substr(line.find_first_of(',') + 1, line.length() - 1);
            cities.push_back(City(cityID, cityName));
        }
    }
    citiesFile.close();
}

string Region::getRegionName()
{
    return regionName;
}

string Region::getRegionID()
{
    return regionID;
}

vector<City> Region::getRegionCities()
{
    return cities;
}
