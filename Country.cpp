#include "Country.h"
#include <fstream>
#include <sstream>

Country::Country(string name, string id)
{
   cout<<"start Country"<<endl;
  countryID=id;
  countryName=name;

  ifstream file("region.txt");
  vector<string> idRegions;
  vector<string> nameRegions;

  if (file.is_open())
  {
    string Idregion, NameRegion;
    getline(file,Idregion,',');
    getline(file, NameRegion);

    while (getline(file, Idregion, ','))
    {
      getline(file, NameRegion);
      
      idRegions.push_back(Idregion);
     cout<<"AKAKAKAKAKAKAKAKAAK AK"<<Idregion ; 
      nameRegions.push_back(NameRegion);
      cout<<"AKAKAKAKAKAKAKAKAAK AK"<<NameRegion ;
    }

    file.close();
  }

  else
  {
    cout << "there is a probleme in the opening of your file" << endl;
  }

  for (int i = 0; i < idRegions.size(); i++)
  {
cout<<"csj"<<countryID<<endl;
if(idRegions[i].substr(0,idRegions[i].find_first_of('-')) == countryID){

 
  regions.push_back(Region(nameRegions[i],idRegions[i]));
  cout<<"YANI"<<regions[i].getRegionName()<<endl;
}

  }
  cout<<"end country";
}


string Country::getCountryName()
{
  return countryName;
}

string Country::getCountryID()
{
  return countryID;
}

vector<Region> Country::getCountryRegions()
{
  return regions;
}
