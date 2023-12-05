#include "City.h"
#include "District.h"
#include <iostream>
#include<fstream>
#include<string>
#include "Customer"

#include <vector>

using namespace std;

City::City(string name, string id)
{
    setcityname(name);
    cityID = id;

    ifstream districtsFile;
    districtsFile.open("districts.text");
    if (!districtsFile)
    {
        cerr << "File could not be open" << endl;
        exit(1);
    }
    string line;
    getline(districtsFile, line);
    while (getline(districtsFile, line))
    {
        string districtid = line.substr(0, line.find_first_of(','));
        if (districtid.substr(0, districtid.find_last_of('-')) == getCityID())
        {
            string cityName = line.substr(line.find_first_of(',') + 1, line.length() - 1);
            Districts.push_back(District(districtid, districtName));
        }
    }
    districtsFile.close();
    ifstream departementfile ;
    departementfile.open("departement.text")
    if (!departementfile)
    {
        cerr << "change the path name of your departement file to departement.text "
        exit(1);
    }
    string line ;
    // the departement are store id,name,budget
    getline(departementfile,line);
    while (getline(departementfile, line);)
    {
        string depid = line.substr(0, line.find_first_of(','));
        if (depid == cityID)
        {
            string name = line.substr(line.find_first_of(','), line.find_last_of(','));
            string budg = line.substr(line.find_last_of(','),line.length()-1);

            cityDepartement = Department(depid,name,budg);
            break;
            
        }
        
    }
    
    


}

Department City::getDepartment()
{
    return cityDepartement;
}

void City::setcityname(string name)
{
    if (name !='')
    {
        cityname = name;
    }
}

string City::getCityName()
{
    return cityName;
}

string City::getCityID()
{
    return cityID;
}

vector<District> City::getDistricts()
{
    return Districts;
}

City::~City()
{
}

