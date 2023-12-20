#include "Company.h"
#include "ctime"
#include "chrono"
#include "fstream"
#include <sstream>

using namespace std;

vector<Country> Company::getCountry()
{
    return countries;
}

Company::Company()
{
  cout<<"start company"<<endl;

  ifstream countrie;
  countrie.open("country.txt");
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
    
    
    string countriename = line.substr(line.find_first_of(',') + 1);
    countries.push_back(Country(countriename, countrieid));
   
  }
  countrie.close();
  cout<<"end company";
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


          Customer* a = customerTreeRoot->contain(stoi(UniquePart));

          auto now = std::chrono::system_clock::now();

  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  std::tm *timeInfo = std::localtime(&currentTime);
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

void Company::orderAlldepartement()
{
  // get it from stackoverflow
  auto now = std::chrono::system_clock::now();

    // Convert it to time_t format
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert time_t to tm structure for local time
    tm *timeInfo = localtime(&currentTime);

    // Extract the year from the timeInfo structure
    int yearr = 1900 + timeInfo->tm_year;

    // Print the year
   
  if (timeInfo->tm_mon + 1 == 12 && timeInfo->tm_mday == 17)
  {
    


  

 vector<depart> AllDepPer;


  for (int i = 0; i < countries.size(); i++)
  {
    for (int j = 0; j < countries[i].getCountryRegions().size(); j++)
    {
      for (int c = 0; c < countries[i].getCountryRegions()[j].getRegionCities().size(); c++)
      {
        depart dep1;
        dep1.dep = countries[i].getCountryRegions()[j].getRegionCities()[c].getDepartment();
        

        for (size_t d = 0; d < countries[i].getCountryRegions()[j].getRegionCities()[c].getDistricts().size(); d++)
        {
          dep1.performence += countries[i].getCountryRegions()[j].getRegionCities()[c].getDistricts()[d].OneDestrictPerf(yearr, 1, yearr, 12);
        }
        AllDepPer.push_back(dep1);
        dep1.performence = 0;
      }
    }
  }

  // sort the vector depends on the performence

  sort(AllDepPer.begin(), AllDepPer.end(), compardep2);


    for (int i = 0; i < 10; i++)
    {
      
      // add +15% to the best departement
      if (i == 0)
      {
        AllDepPer[i].dep.updateBudget(0.15);
      }
      // add +10% to the next 9 departement
      else
      {
        AllDepPer[i].dep.updateBudget(0.1);
      }
    }
    // remove 15% to the ten last ones
    int length = AllDepPer.size() - 1;
    for (int j = length; j > length - 10; j--)
    {
      // sub -15% to the last departement
      if (j == length)
      {
       AllDepPer[j].dep.updateBudget(-0.15);
      }
      else
      {
        // sub -10% to the next 9 departement (the 9 before the last one)
        AllDepPer[j].dep.updateBudget(-0.1);
      }
    }
    
  }
  else
  {
    cout << "You can't call the function because you are not in the right day !" << endl;
  }
}



// compare between the deparetemnt depends on the budget
bool Company::comparedep( Department a,  Department b)
{
  
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
        dep1.dep = countries[i].getCountryRegions()[j].getRegionCities()[c].getDepartment();
        

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
    cout << "Departement ID : " << AllDepPer[i].dep.getDepartmentid() << ", Departement Name : " << AllDepPer[i].dep.getDepartmentName() << ", its performence : " << AllDepPer[i].performence << " . " << endl;
  }
  
  
}

 

Customer Company::getWinnerCustomer()
{
  return winner;
}

void Company::printBillForOneCustome(BinarySearchTree *root, int idcust, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  auto now = std::chrono::system_clock::now();

  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
  std::tm *timeInfo = std::localtime(&currentTime);
  int todayMonth = timeInfo->tm_mon + 1;    // Adding 1 to make it human-readable
  int todayYear = timeInfo->tm_year + 1900; // Adding 1900 to get the actual year
 
  // now neqsm my id for fast access :

  BinarySearchTree *customerTreeRoot = root;
  // remember that a customer should exist, donc do checkings
  Customer *a = customerTreeRoot->contain(idcust);
yearStart= a->hashyear(yearStart);
yearEnd=a->hashyear(yearEnd);
monthStart--;
monthEnd-- ;

  // remember rak triyeh tmed choix to the customer in the main, i.e nta tqolo wsh hab ydkhl or wsh hab ychof, tsma yk 3amar 3la qisek
   
  //!print when given only a year, we get all year's bills
  if (yearStart != -1 && yearEnd == -1 && monthEnd == -1 && monthStart == -1)
  {
      for (int i = 0; i < 12; i++)
      {
         cout<<"month"<<i+1<<endl;
        a->getCustomerBills()[yearStart ][i].print();
      }
    
  }
  //! for a given month and year
  else if (yearStart != -1 && yearEnd == -1 &&monthStart != -1 && monthEnd == -1)
  {
    a->getCustomerBills()[yearStart][monthStart].print();
  }

  //?given start year and end year
  else if (yearStart != -1 && yearEnd != -1 && monthStart == -1&&monthEnd==-1)
  {
    if (yearEnd==a->hashyear(todayYear))
    {
    
     for (size_t i = yearStart; i < yearEnd ; i++)
    {
      for (size_t j = 0; j < 12; j++)
      {
         cout<<"BILL FOR YEAR "<<i+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[i][j].print();
      }
      
    }
    for (size_t i = 0; i < todayMonth-1; i++)
    {
       cout<<"BILL FOR YEAR "<<todayYear+2020<<"AND FOR MONTH "<<i+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
     a->getCustomerBills()[yearEnd][i].print();
    }
    
    }
    else
    {
      for (size_t i = yearStart; i < yearEnd+1 ; i++)
    {
      for (size_t j = 0; j < 12; j++)
      {
        cout<<"BILL FOR YEAR "<<i+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[i][j].print();
      }
      
    }
    }
    
    
    
    
  
  }
  //! given all arguments
  else if ( yearStart!=-1 && yearEnd != -1 && monthStart!=-1 && monthEnd!=-1)
  {


    if (yearEnd==yearStart)
    {
    
     
     
      for (size_t j = monthStart; j < monthEnd+1; j++)
      {
         cout<<"BILL FOR YEAR "<<j+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[yearStart][j].print();
      }
      
    
   
    }
    else
    {
for (size_t i = monthStart; i < 12 ; i++)
{
   cout<<"BILL FOR YEAR "<<yearStart+2020<<"AND FOR MONTH "<<i+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
  a->getCustomerBills()[yearStart][i].print(); 
}


      for (size_t i = yearStart+1; i < yearEnd ; i++)
    {

      for (size_t j = 0; j < 12; j++)
      {
        cout<<"BILL FOR YEAR "<<yearStart+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[i][j].print();
      }
      
    }

    for (size_t j = 0; j < monthEnd+1; j++)
      {
        cout<<"BILL FOR YEAR "<<yearEnd+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[yearEnd][j].print();
      }
    }
    
    
   
  }
  
  
}
void Company::inOrderTraversal(BinaryNode *root, BinarySearchTree *rot, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  if (root == nullptr)
  {
    return;
  }

  inOrderTraversal(root->left, rot,yearStart, yearEnd, monthStart, monthEnd);

   {
    cout<<"CUSTOMER DETAILS :"<<endl;

    root->element.print();
    cout<<endl<<"----------"<<endl;
    printBillForOneCustome(rot, root->element.getID(), yearStart, yearEnd, monthStart, monthEnd);
   cout<<endl<<endl;
   }

  inOrderTraversal(root->right,rot,yearStart, yearEnd, monthStart, monthEnd);
}
void Company::printBillCountry(string countryID, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  
  Country countr = countries[stoi(countryID)-1];
  for (size_t i = 0; i <countr.getCountryRegions().size(); i++)
  {
    // cout<<"country id is "<<countryID<<endl;
    printBillRegion(countr.getCountryRegions().at(i).getRegionID(), yearStart, yearEnd, monthStart, monthEnd);
  }
}
void Company::printBillRegion(string regionID, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
  string countryPart = regionID.substr(0, regionID.find_first_of("-"));
  regionID = regionID.substr(regionID.find_first_of("-") + 1);
  string RegionPart = regionID;
  Region region = countries[stoi(countryPart)-1].getCountryRegions()[stoi(RegionPart)-1];
for (size_t i = 0; i < region.getRegionCities().size() ; i++)
{
 // cout<<"countryPart is"<<countryPart<<endl<<"citypart is"<<regionID<<endl;
  printBillCity(region.getRegionCities().at(i).getCityID(), yearStart, yearEnd, monthStart, monthEnd);
}
}
void Company::printBillCity(string cityID, int yearStart, int yearEnd, int monthStart, int monthEnd)
{
    string countryPart = cityID.substr(0, cityID.find_first_of("-"));
    cityID = cityID.substr(cityID.find_first_of("-") + 1);
    string RegionPart = cityID.substr(0, cityID.find_first_of("-"));
    cityID = cityID.substr(cityID.find_first_of("-") + 1);
    string CityPart = cityID;
  
    City cit = countries[stoi(countryPart)-1].getCountryRegions()[stoi(RegionPart)-1].getRegionCities()[stoi(CityPart)-1];
    cout<<"country part is "<<countryPart<<"region part is"<<RegionPart<<"city part is"<<CityPart<<endl;
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
    string DistrictPart = ditrictID;
    
    //ditrictID = ditrictID.substr(ditrictID.find_first_of("-") + 1);
    // this part is for separting the regionId ,cityId,districtId,countryId and convert them to integers
    inOrderTraversal(countries[stoi(countryPart)-1].getCountryRegions()[stoi(RegionPart)-1].getRegionCities()[stoi(CityPart)-1].getDistricts()[stoi(DistrictPart)-1].getCustomers()->getroot(), countries[stoi(countryPart)-1].getCountryRegions()[stoi(RegionPart)-1].getRegionCities()[stoi(CityPart)-1].getDistricts()[stoi(DistrictPart)-1].getCustomers(), yearStart, yearEnd, monthStart, monthEnd); // print the bills for a period of a customer
  }




void Company::callprint(string id, int yearStart=0, int yearEnd=0, int monthStart=0, int monthEnd=0)
{

  size_t count =0;

   

  for (size_t i = 0; i <id.length()-1; i++)
  {
    if ( id[i] == '-')
    {
      count++;
    }

  }

 


  switch (count)
  {
  case 0:
    printBillCountry( id,  yearStart,  yearEnd,  monthStart,  monthEnd);

        break;
  case 1:
   printBillRegion( id,  yearStart,  yearEnd,  monthStart,  monthEnd);
    break;
    case 2 :
    printBillCity( id,  yearStart,  yearEnd,  monthStart,  monthEnd);
    break;
    case 3:
    printBillDistrict(id,  yearStart,  yearEnd,  monthStart,  monthEnd);
    break;
    case 4:
    printBillForOneCustomer(id, yearStart, yearEnd, monthStart, monthEnd);
    break;

        default :cout<<"not valid";
         break;
  } 
}

Company::~Company()
{
}

void Company::printBillForOneCustomer(string givenID, int yearStart=-1, int yearEnd=-1, int monthStart=-1, int monthEnd=-1)
{
   //cout<<"YANIIIIIIIIIIII"<<endl<<endl<<monthStart<<endl<<monthEnd<<endl;
  auto now = std::chrono::system_clock::now();

  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  std::tm *timeInfo = std::localtime(&currentTime);
  int todayMonth = timeInfo->tm_mon + 1;    // Adding 1 to make it human-readable
  int todayYear = timeInfo->tm_year + 1900; // Adding 1900 to get the actual year

cout<<"blaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<todayMonth<<"year          "<<todayYear;


  string customerID = givenID;

  // now neqsm my id for fast access :

  string countryPart = customerID.substr(0, customerID.find_first_of("-"));
  cout<<countryPart<<endl;
  customerID = customerID.substr(customerID.find_first_of("-") + 1);
  string RegionPart = customerID.substr(0, customerID.find_first_of("-"));
  cout<<RegionPart<<endl;
  customerID = customerID.substr(customerID.find_first_of("-") + 1);
  string CityPart = customerID.substr(0, customerID.find_first_of("-"));
  cout<<CityPart<<endl;
  customerID = customerID.substr(customerID.find_first_of("-") + 1);
  string DistrictPart = customerID.substr(0, customerID.find_first_of("-"));
  cout<<DistrictPart<<endl;
  customerID = customerID.substr(customerID.find_first_of("-") + 1);
  string UniquePart = customerID.substr(0, customerID.find_first_of("-"));
  cout<<UniquePart<<endl;
 // customerID = customerID.substr(customerID.find_first_of("-") + 1);
//cout<<"hello world hh"<<endl;
  BinarySearchTree *customerTreeRoot = countries[stoi(countryPart)-1].getCountryRegions()[stoi(RegionPart)-1].getRegionCities()[stoi(CityPart)-1].getDistricts()[stoi(DistrictPart)-1].getCustomers();
 
  // remember that a customer should exist, donc do checkings
  
  Customer * a = customerTreeRoot->contain(stoi(UniquePart));
 
  
yearStart=a->hashyear(yearStart);
yearEnd=a->hashyear(yearEnd);
monthStart = a->hashmouth(monthStart);
monthEnd = a->hashmouth(monthEnd);
//cout<<"YANIIIIIIIIIIII"<<endl<<endl<<monthStart<<endl<<monthEnd<<endl;
cout<<"customer's details : "<<endl<<"------------"<<endl;
a->print();
cout<<endl<<"-------------"<<endl;
cout<<"customer bills : "<<endl;

//cout<<"ezdxszecaezc"<<yearStart<<"zcaaaaaaaaaaaaaa"<<yearEnd;
  // remember rak triyeh tmed choix to the customer in the main, i.e nta tqolo wsh hab ydkhl or wsh hab ychof, tsma yk 3amar 3la qisek
  
  //!print when given only a year, we get all year's bills
  if (yearStart != -1 && yearEnd == -1 && monthEnd == -1 && monthStart == -1)
  {
      for (int i = 0; i < 12; i++)
      {
         cout<<"month"<<i+1<<endl;
        a->getCustomerBills()[yearStart ][i].print();
      }
    
  }
  //! for a given month and year
  else if (yearStart != -1 && yearEnd == -1 &&monthStart != -1 && monthEnd == -1)
  {
    a->getCustomerBills()[yearStart][monthStart].print();
  }

  //?given start year and end year
  else if (yearStart != -1 && yearEnd != -1 && monthStart == -1&&monthEnd==-1)
  {
    if (yearEnd==a->hashyear(todayYear))
    {
    
     for (size_t i = yearStart; i < yearEnd ; i++)
    {
      for (size_t j = 0; j < 12; j++)
      {
         cout<<"BILL FOR YEAR "<<i+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[i][j].print();
      }
      
    }
    for (size_t i = 0; i < todayMonth-1; i++)
    {
       cout<<"BILL FOR YEAR "<<todayYear+2020<<"AND FOR MONTH "<<i+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
     a->getCustomerBills()[yearEnd][i].print();
    }
    
    }
    else
    {
      for (size_t i = yearStart; i < yearEnd+1 ; i++)
    {
      for (size_t j = 0; j < 12; j++)
      {
        cout<<"BILL FOR YEAR "<<i+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[i][j].print();
      }
      
    }
    }
    
    
    
    
  
  }
  //! given all arguments
  else if ( yearStart!=-1 && yearEnd != -1 && monthStart!=-1 && monthEnd!=-1)
  {


    if (yearEnd==yearStart)
    {
    
     
     
      for (size_t j = monthStart; j < monthEnd+1; j++)
      {
         cout<<"BILL FOR YEAR "<<j+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[yearStart][j].print();
      }
      
    
   
    }
    else
    {
for (size_t i = monthStart; i < 12 ; i++)
{
   cout<<"BILL FOR YEAR "<<yearStart+2020<<"AND FOR MONTH "<<i+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
  a->getCustomerBills()[yearStart][i].print(); 
}


      for (size_t i = yearStart+1; i < yearEnd ; i++)
    {

      for (size_t j = 0; j < 12; j++)
      {
        cout<<"BILL FOR YEAR "<<yearStart+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[i][j].print();
      }
      
    }

    for (size_t j = 0; j < monthEnd+1; j++)
      {
        cout<<"BILL FOR YEAR "<<yearEnd+2020<<"AND FOR MONTH "<<j+1<<" :"<<endl;
        cout<<"-----------------------"<<endl;
        a->getCustomerBills()[yearEnd][j].print();
      }
    }
    
    
   
  }
  
  
  
 
  //what we could do instead, f default args n7ato current month, will be discussed with the girls
}
/*
  // a period was given
    // check ida kayn an interval for year
    if (!yearEnd)
    {
      // mkch
      for (int i = monthStart - 1; i < monthEnd - 1; i++)
      {
        a->getCustomerBills()[yearStart][i];
      }
    }
    else
    {
      // interval given..
      for (int i = yearStart - 1; i < yearEnd - 1; i++)
      {
        for (int j = monthStart - 1; i < monthEnd - 1; j++)
        {
          a->getCustomerBills()[i][j].print();
        }
      }
    }*/
