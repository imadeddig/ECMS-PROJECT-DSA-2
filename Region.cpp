#include "Region.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// here we have to immeditely open the file, and search for all cities that matches that region, need to be initilaized
Region::Region(string regionNam = "", string regionI = 0)
{
    cout<<"start Region"<<endl;
    // lazem hna neqsem id tae cities bch ymatchi li raho f region

    
    // csv file reference: https://iq.opengenus.org/read-and-write-in-csv-in-cpp/#google_vignette
    //textbook of last year was also took as reference
    regionName = regionNam;
    regionID = regionI;
    ifstream citiesFile;
    citiesFile.open("city.txt");
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
          
            string cityName = line.substr(line.find_first_of(',') + 1 );
           
            cities.push_back(City(cityName,cityID));
        }
    }
    citiesFile.close();
    cout<<"end region";
}

string Region::getRegionName()
{
    cout<<regionName;
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

