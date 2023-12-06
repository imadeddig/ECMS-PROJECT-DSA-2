#include "District.h"
#include "fstream"
using namespace std;

District::District(const string &a, const string &b)
{
    districtID = a;
    districtName = b;
    fstream customerFile;
    HashWeather();
    customerFile.open("customers.txt");
    string line;
    getline(customerFile, line);
    while (getline(customerFile, line))
    {
        string cusID = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        if (cusID == districtID)
        {
            string name = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            string familyNum = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            vector<int> ages;
            for (int i = 0; i < stoi(familyNum); i++)
            {
                string num = line.substr(0, line.find_first_of(","));
                ages.push_back(stoi(num));
                line = line.substr(line.find_first_of(",") + 1);
            }

            string cumultive = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            string dateDay = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            string dateMonth = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            string dateYear = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            string address = line.substr(0, line.find_first_of(","));
            line = line.substr(line.find_first_of(",") + 1);

            Customer customer(name, cusID, ages, stod(cumultive), stoi(dateDay), stoi(dateMonth), stoi(dateYear), address);
            customersTree->insert(customer);
        }
    }
    customerFile.close();
}

string District::getDistrictID()
{
    return districtID;
}

string District::getDistrictName()
{
    return districtName;
}

BinarySearchTree* District::getCustomers()
{
    return customersTree;
}

void District::getDayWeather(int &day, int &month, int &year)
{
    YearWeather temp = climate.yearsweather[climate.hashFunction(year)];
    for (int i = 0; i < temp.days.size(); i++)
    {
        if (temp.days[i].monthNum == month && temp.days[i].dayNum == day)
        {
            temp.days[i].printWeatherDay();
            break;
        }
    }
}

HashWeather District::getWeather()
{
}
