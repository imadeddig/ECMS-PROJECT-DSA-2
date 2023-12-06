#include "Company.h"
#include "District.h"
#include "ctime"
#include "chrono"
#include "Bill.h"
#include "BinarySearchTree.h"
#include "fstream"
#include "Country.h"

void Company::addCustomer(string address, int familyMembers, vector<int> familyMemberAges, string customerName, int countryID, int regionID, int cityID, int districtID)
{
    
}


Company::Company()
{

    ifstream countrie;
    countrie.open("countrie.text");
    if (!countrie)
    {
        cerr << "File could not be open" << endl;
        exit(1);
    }
    string line;
    getline(countrie, line);
    while (getline(countrie, line))
    {
        string countrieid = line.substr(0, line.find_first_of(','));

        string countriename = line.substr(line.find_first_of(',') + 1, line.length() - 1);
        countries.push_back(Country(countrieid, countriename));
    }
    countrie.close();

    fstream departementorder;
    departementorder.open("departementorder.text");
    if (!departementorder)
    {
        cerr << "change the path name of your departement file to departement.text ";
        exit(1);
    }

    string line;
    // the departement are store id,name,budget
    getline(departementorder, line);
    while (getline(departementorder, line))
    {
        vector<Department> a;
        do
        {

            // i twill be like that dep1id,DepartmentName,ped1budget,performance , dep2  ;

            string depid = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string depname = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string depbudget = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string depperformance = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));

            a.push_back(Department(depid, depname, stoi(depbudget)));

        } while (line != "/n");

        departmentsStored.push_back(a);
    }
}

void Company::setBillFile()
{
    //i have a new file fih customers last month bills, lazem ndkhel jded
    //lzm i get this date month!
    fstream monthlyBill;
    monthlyBill.open("monthlybill.txt");
    string line;
    getline(monthlyBill,line);
    while (getline(monthlyBill,line))
    {
        //customerid , consumption , injection
        //00-00-00-00-00
        string customerIDs = line.substr(0,line.find_first_of(","));
        string customerID = customerIDs;
        line = line.substr(line.find_first_of(",")+1);
        string consumptionAmount = line.substr(0,line.find_first_of(","));
        line = line.substr(line.find_first_of(",")+1);
        string injectionAmount = line.substr(0,line.find_first_of(","));
        line = line.substr(line.find_first_of(",")+1);
        //now neqsm my id for fast access : 

            string countryPart = customerID.substr(0,customerID.find_first_of("-"));
        customerID = customerID.substr(customerID.find_first_of("-")+1);
                string RegionPart = customerID.substr(0,customerID.find_first_of("-"));
        customerID = customerID.substr(customerID.find_first_of("-")+1);
                string CityPart = customerID.substr(0,customerID.find_first_of("-"));
        customerID = customerID.substr(customerID.find_first_of("-")+1);
                string DistrictPart = customerID.substr(0,customerID.find_first_of("-"));
        customerID = customerID.substr(customerID.find_first_of("-")+1);
        string UniquePart = customerID.substr(0,customerID.find_first_of("-"));
        customerID = customerID.substr(customerID.find_first_of("-")+1);
        auto billToBeInserted = Bill(stod(injectionAmount),stod(consumptionAmount));
          BinarySearchTree* customerTreeRoot = countries[stoi(countryPart)].getCountryRegions()[stoi(RegionPart)].getRegionCities()[stoi(CityPart)].getDistricts()[stoi(DistrictPart)].getCustomers();

          Customer* a = customerTreeRoot->contains(stoi(UniquePart));

          auto now = std::chrono::system_clock::now();

  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  std::tm *timeInfo = std::localtime(&currentTime);
  int monthNow = timeInfo->tm_mon+1;
  int yearNow = timeInfo->tm_year;

  a->getCustomerBills()[yearNow-2020][monthNow] = billToBeInserted;
         
          
          
    }
    monthlyBill.close();
    

}
