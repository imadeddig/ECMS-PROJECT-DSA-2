#include "City.h"

#include <iostream>
#include <fstream>
#include <string>


#include <vector>

using namespace std;

City::City(string name, string id)
{
    cout<<"start City"<<endl;
    setcityname(name);
    cityID = id;

    ifstream districtsFile;
    districtsFile.open("districts.txt");
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
            // cout<<"hi girl"<<districtid.substr(0, districtid.find_last_of('-'))<<"gggggg"<<getCityID()<<endl;
            string districtName = line.substr(line.find_first_of(',') + 1, line.length() - 1);
            Districts.push_back(District(districtid, districtName));
        }
    }
    districtsFile.close();
  ifstream departementfile;
    departementfile.open("department.txt");
    if (!departementfile)
    {
        cerr << "change the path name of your departement file to departement.text ";
        exit(1);
    }
     line = "";
    // the departement are store id,name,budget,spent
    getline(departementfile, line);
    while (getline(departementfile, line))
    {
        string depid = line.substr(0, line.find_first_of(','));
        string deppid = depid.substr(0, depid.find_last_not_of('-'));
       
        if (deppid == cityID)
        {
           // cout<<"hello"<<deppid<<"kjf"<<cityID<<endl;
            line = line.substr(line.find_first_of(',') + 1);

            string name = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(',') + 1);

            string budg = line.substr(0, line.find_first_of(','));
            string spent = line.substr(line.find_first_of(',') + 1);
            
            cityDepartement = Department(depid, name, stod(budg), stod(spent));
            
            break;
        }
    }
  cout<<"end City"<<endl;
}

Department City::getDepartment()
{
    return cityDepartement;
}

void City::setcityname(string name)
{
    if (name != "")
    {
        cityName = name;
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




