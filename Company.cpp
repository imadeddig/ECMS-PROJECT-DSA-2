#include "Company.h"
#include "District.h"
#include "ctime"
#include "chrono"
#include "Bill.h"
#include "BinarySearchTree.h"
#include "fstream"
#include "Country.h"

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
      string spent = line.substr(0, line.find_first_of(','));
      line = line.substr(line.find_first_of(','));

      a.push_back(Department(depid, depname, stod(depbudget),stod(spent)));

    } while (line != "/n");

    departmentsStored.push_back(a);
  }
}
void Company::addCustomer(const string &name, vector<int> ages, double amount, int day, int mouth, int year, string adress, string districtID)
{
  istringstream ss(districtID);
  string part;
  int numbers[4], i = 0;

  while (getline(ss, part, '-'))
  {
    int number = stoi(part);
    numbers[i] = number;
    i++;
  }
    Customer customerMax =countries[numbers[0]].getCountryRegions()[numbers[1]].getRegionCities()[numbers[2]].getDistricts()[numbers[3]].getCustomers()->findMax();
    int newid=customerMax.getID()+1;
    Customer newCostumer(name,to_string(newid),ages,amount,day,mouth,year,adress) ;
    countries[numbers[0]].getCountryRegions()[numbers[1]].getRegionCities()[numbers[2]].getDistricts()[numbers[3]].getCustomers()->insert(newCostumer);
}

void Company::setBillFile()
{
            auto now = std::chrono::system_clock::now();

  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  std::tm *timeInfo = std::localtime(&currentTime);
    //i have a new file fih customers last month bills, lazem ndkhel jded
    //lzm i get this date month!


    //function can be only called first of the month
    if(timeInfo->tm_mday==1)
   { fstream monthlyBill;
    //we'll be comparing this to that
    Customer* winTemp = nullptr;
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




  int monthNow = timeInfo->tm_mon+1;
  int yearNow = timeInfo->tm_year;

  a->getCustomerBills()[yearNow-2020][monthNow] = billToBeInserted;
            //we update the customer's cmltv thingie, the new one
          a->updateAmount(stod(injectionAmount));

          if(a->getComulativeAmount()>winTemp->getComulativeAmount() || !winTemp)
          {
            //idk if that is possible
            winTemp = a;
          }
         // i still need to update customer cumulative thingie + keep track of winner
          
          
    }
    monthlyBill.close();
}
else
{
  cout<<"mazal l7al hh";
}
    

}


vector<Department> Company::orderAlldepartement()
{
  // get it from stackoverflow
  auto now = chrono::system_clock::now();

  time_t currentTime = chrono::system_clock::to_time_t(now);

  tm *timeInfo = localtime(&currentTime);

  if (timeInfo->tm_mon + 1 == 12 && timeInfo->tm_mday == 17)
  {
    // creat a vector to store all the departement .
    vector<Department> AllDepartement;
    // a loops to get into all the departement and store them into the vector
    for (int i = 0; i < countries.size(); i++)
    {
      for (int j = 0; j < countries[i].getCountryRegions().size(); j++)
      {
        for (int c = 0; c < countries[i].getCountryRegions()[j].getRegionCities().size(); c++)
        {
          AllDepartement.push_back(countries[i].getCountryRegions()[j].getRegionCities()[c].getDepartment());
        }
      }
    }
    // sort the vector depends on the function comparedep (see its implimentation )
    sort(AllDepartement.begin(), AllDepartement.end(), comparedep);

    for (int i = 0; i < 10; i++)
    {
      // add +15% to the best departement
      if (i == 0)
      {
        AllDepartement[i].updateBudget(0.15);
      }
      // add +10% to the next 9 departement
      else
      {
        AllDepartement[i].updateBudget(0.1);
      }
    }

    // remove 15% to the ten last ones

    int length = AllDepartement.size() - 1;

    for (int j = length; j > length - 10; j--)
    {
      // sub -15% to the last departement
      if (j == length)
      {
        AllDepartement[j].updateBudget(-0.15);
      }
      else
      {
        // sub -10% to the next 9 departement (the 9 before the last one)
        AllDepartement[j].updateBudget(-0.1);
      }
    }

    storeNewDepartment(AllDepartement);
    return AllDepartement;
  }

  else
  {
    cout << "You can't call the function because you are not in the right day !" << endl;
  }
}

void Company::storeNewDepartment(vector<Department> newdprtmnt)
{

  departmentsStored.push_back(newdprtmnt);
}


Customer Company::getWinnerCustomer()
{
  return winner;
}

// compare between the deparetemnt depends on the budget
bool Company::comparedep(Department a, Department b)
{
  return a.getBudget() > b.getBudget();
}


void Company::storeNewDepartment(vector<Department> newdprtmnt)
{

  departmentsStored.push_back(newdprtmnt);
}

void Company::getDepartmentPerformance(int startYear, int startMonth, int endYear, int endMonth)
{

  vector<depart> AllDepPer;

  for (int i = 0; i < countries.size(); i++)
  {
    for (int j = 0; j < countries[i].getCountryRegions().size(); j++)
    {
      for (int c = 0; c < countries[i].getCountryRegions()[j].getRegionCities().size(); c++)
      {
        depart dep1;
        dep1.namedep = countries[i].getCountryRegions()[j].getRegionCities()[c].getDepartment().getDepartmentName();
        dep1.IDdep = countries[i].getCountryRegions()[j].getRegionCities()[c].getDepartment().getDepartmentid();

        for (size_t d = 0; d < countries[i].getCountryRegions()[j].getRegionCities()[c].getDistricts().size(); d++)
        {
          dep1.performence += countries[i].getCountryRegions()[j].getRegionCities()[c].getDistricts()[d].OneDestrictPerf(startYear, startMonth, endYear, endMonth);
        }
        AllDepPer.push_back(dep1);
        dep1.performence = 0;
      }
    }
  }

  // sort the vector depends on the performence

  sort(AllDepPer.begin(), AllDepPer.end(), compardep2);

  // print the vector

  for (int i = 0; i < AllDepPer.size(); i++)
  {
    cout << "Departement ID : " << AllDepPer[i].IDdep << ", Departement Name : " << AllDepPer[i].namedep << ", its performence : " << AllDepPer[i].performence << " . " << endl;
  }
}

bool Company::compardep2(depart a, depart b)
{
  return a.performence > b.performence;
}

Customer* Company::getWinnerCustomer()
{
  return winner;
}



void Company::printBillForOneCustomer(BinarySearchTree *root, int idcust, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  auto now = std::chrono::system_clock::now();

  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  std::tm *timeInfo = std::localtime(&currentTime);
  int todayMonth = timeInfo->tm_mon + 1;    // Adding 1 to make it human-readable
  int todayYear = timeInfo->tm_year + 1900; // Adding 1900 to get the actual year

 

  // now neqsm my id for fast access :

  BinarySearchTree *customerTreeRoot = root;
  // remember that a customer should exist, donc do checkings
  Customer *a = customerTreeRoot->contains(idcust);

  // remember rak triyeh tmed choix to the customer in the main, i.e nta tqolo wsh hab ydkhl or wsh hab ychof, tsma yk 3amar 3la qisek
  if (yearStart != 0 && yearEnd == 0 && monthEnd == 0 && monthStart == 0)
  {
    // print based on a specific year
    if (yearStart == todayYear)
      for (int i = 0; i <  todayMonth ; i++)
      {
        a->getCustomerBills()[a->hashyear(yearStart)][i].print();
      }
    else
    {
      for (int i = 0; i < 12; i++)
      {
        a->getCustomerBills()[a->hashyear(yearStart)][i].print();
      }
    }
  }
  else if ((monthStart-1 )!= 0 && (monthEnd-1) == 0)
  {
    // print for a specific month
    // if year given
    if (a->hashyear( yearStart) != 0)
    {
      // make sure that fel main ndiro logical checkings
      a->getCustomerBills()[a->hashyear(yearStart)][monthStart-1].print();
    }
    else
    {
      a->getCustomerBills()[a->hashyear(todayYear)][monthStart-1].print();
    }
  }
  else if ((monthStart - 1) != 0 && (monthEnd - 1) != 0 && a->hashyear(yearStart) != 0)
  {
    // a period was given
    // check ida kayn an interval for year
    if (!a->hashyear(yearEnd))
    {
      // mkch
      for (int i = monthStart - 1; i < monthEnd - 1; i++)
      {
        a->getCustomerBills()[a->hashyear(yearStart)][i];
      }
    }
    else
    {
      // interval given..
      for (int i = a->hashyear(yearStart) ; i < a->hashyear(yearEnd) ; i++)
      {
        for (int j = monthStart - 1; i < monthEnd - 1; j++)
        {
          a->getCustomerBills()[i][j].print();
        }
      }
    }
  }
  // what we could do instead, f default args n7ato current month, will be discussed with the girls
}

void Company::inOrderTraversal(BinaryNode *root, BinarySearchTree *rot, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  if (root == nullptr)
  {
    return;
  }

  inOrderTraversal(root->left, rot,yearStart, yearEnd, monthStart, monthEnd);

  printBillForOneCustomer(rot, root->element.getID(), yearStart, yearEnd, monthStart, monthEnd);

  inOrderTraversal(root->right,rot,yearStart, yearEnd, monthStart, monthEnd);
}

void Company::printBillCountry(string countryID, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  string countryPart = countryID.substr(0, countryID.find_first_of("-"));
  countryID = countryID.substr(countryID.find_first_of("-") + 1);
  Country countr = countries[stoi(countryPart)];

  for (size_t i = 0; i <countr.getCountryRegions().size(); i++)
  {
    printBillCity(countr.getCountryRegions().at(i).getRegionID(), yearStart, yearEnd, monthStart, monthEnd);
  }
}

void Company::printBillRegion(string regionID, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  string countryPart = regionID.substr(0, regionID.find_first_of("-"));
  regionID = regionID.substr(regionID.find_first_of("-") + 1);
  string RegionPart = regionID.substr(0, regionID.find_first_of("-"));
  regionID = regionID.substr(regionID.find_first_of("-") + 1);
  Region region = countries[stoi(countryPart)].getCountryRegions()[stoi(RegionPart)];

for (size_t i = 0; i < region.getRegionCities().size() ; i++)
{
  printBillCity(region.getRegionCities().at(i).getCityID(), yearStart, yearEnd, monthStart, monthEnd);
}

}

void Company::printBillCity(string cityID, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
    string countryPart = cityID.substr(0, cityID.find_first_of("-"));
    cityID = cityID.substr(cityID.find_first_of("-") + 1);
    string RegionPart = cityID.substr(0, cityID.find_first_of("-"));
    cityID = cityID.substr(cityID.find_first_of("-") + 1);
    string CityPart = cityID.substr(0, cityID.find_first_of("-"));
    cityID = cityID.substr(cityID.find_first_of("-") + 1);
    City cit = countries[stoi(countryPart)].getCountryRegions()[stoi(RegionPart)].getRegionCities()[stoi(CityPart)];

    for (size_t i = 0; i < cit.getDistricts().size(); i++)
    {
      printBillDistrict(cit.getDistricts().at(i).getDistrictID(), yearStart, yearEnd, monthStart, monthEnd);
    }
    

  }

  void Company::printBillDistrict(string ditrictID, int yearStart, int yearEnd, int monthStart, int monthEnd)
  {
    string countryPart = ditrictID.substr(0, ditrictID.find_first_of("-"));
    ditrictID = ditrictID.substr(ditrictID.find_first_of("-") + 1);
    string RegionPart = ditrictID.substr(0, ditrictID.find_first_of("-"));
    ditrictID = ditrictID.substr(ditrictID.find_first_of("-") + 1);
    string CityPart = ditrictID.substr(0, ditrictID.find_first_of("-"));
    ditrictID = ditrictID.substr(ditrictID.find_first_of("-") + 1);
    string DistrictPart = ditrictID.substr(0, ditrictID.find_first_of("-"));
    ditrictID = ditrictID.substr(ditrictID.find_first_of("-") + 1);
    // this part is for separting the regionId ,cityId,districtId,countryId and convert them to integers

    inOrderTraversal(countries[stoi(countryPart)].getCountryRegions()[stoi(RegionPart)].getRegionCities()[stoi(CityPart)].getDistricts()[stoi(DistrictPart)].getCustomers()->getroot(), countries[stoi(countryPart)].getCountryRegions()[stoi(RegionPart)].getRegionCities()[stoi(CityPart)].getDistricts()[stoi(DistrictPart)].getCustomers(), yearStart, yearEnd, monthStart, monthEnd); // print the bills for a period of a customer
  }




void Company::callprint(string id, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  
  size_t count =0;
  
  for (size_t i = 0; i <id.length(); i++)
  {
    if ( &id[i] == "-")
    {
      count++;
    }
    
  }
  

  switch (count)
  {
  case 0:
    printbillcountry( id,  yearStart,  yearEnd,  monthStart,  monthEnd);

        break;
  case 1:
   printbillregion( id,  yearStart,  yearEnd,  monthStart,  monthEnd);
    break;
    case 2 :
    printBillCity( id,  yearStart,  yearEnd,  monthStart,  monthEnd);
    break;
    case 3:
    printBillDistrict( id,  yearStart,  yearEnd,  monthStart,  monthEnd);
    break;
    case 4:
    printBillForOneCustomer(id, yearStart, yearEnd, monthStart, monthEnd);
    break;

        default :cout<<"not valid";
         break;
  } 
}
