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


double District::OneDestrictPerf(int startYear = 0, int startMonth = 0, int endYear = 0, int endMonth = 0)
{

    return getcumulativeofallcust(customersTree->getroot(), startYear, startMonth, endYear, endMonth);
}

double District::getcumulativeofallcust(BinaryNode *t, int min = 0, int minmou = 0, int max = 0, int maxmouth = 0)
{

    if (t == nullptr)
    {
        return 0;
    }

    for (size_t i = t->element.hashyear(min); i <= t->element.hashyear(max); i++)
    {

        if (t->element.hashyear(min) == t->element.hashyear(max)) // the same year
        {
            for (size_t j = t->element.hashyear(minmou); j <= t->element.hashyear(maxmouth); j++)
            {
                cd += t->element.getCustomerBills()[i][j].getTotalDifference();
            }
        }

        else // t->element.hashyear(min) < t->element.hashyear(max) like 2023 to 2024
        {
            if (t->element.hashyear(min) == i)
            {
                for (size_t d = t->element.hashmouth(minmou); d < 12; d++)
                {
                    cd += t->element.getCustomerBills()[i][d].getTotalDifference();
                }
            }

            else if (t->element.hashyear(max) == i)
            {
                for (size_t f = 0; f <= t->element.hashyear(max); f++)
                {
                    cd += t->element.getCustomerBills()[i][f].getTotalDifference();
                }
            }

            else //  (t->element.hashyear(min) != i && t->element.hashyear(max) != i)
            {
                for (size_t e = 0; e < 12; e++)
                {
                    cd += t->element.getCustomerBills()[i][e].getTotalDifference();
                }
            }
        }
    }

    return cd + getcumulativeofallcust(t->left) + getcumulativeofallcust(t->right);
}
