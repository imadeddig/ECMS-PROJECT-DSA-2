
#include "Customer.h"
#include"Bill.h"
#include<fstream>

        
Customer::Customer(const string &name, const string &id, vector<int> ages, double amount , int day, int mouth, int year, string adress)
{

customerBills.resize(3);
    for (size_t i = 0; i < 3; i++)
    {
       customerBills[i].resize(12);
    }
    


    setCustomerName(name);
    setAdress(adress);
    ID=id;
    setFamilyAges(ages);
    updateAmount(amount);
   setRegistrationDate(year,mouth,day);

    ifstream Bil ;
    Bil.open("bill.txt");
    string line ;
    getline(Bil,line);

    while (getline(Bil , line))
    {
        string custid = line.substr(0, line.find_first_of(','));
        line=line.substr(line.find_first_of(','));
        if (custid == ID)
        {
            string billyear = line.substr(0,line.find_first_of(','));
            line = line.substr( line.find_first_of(','));
            string billmouth = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string injaction = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string consumption = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string cumulative = line.substr(0, line.find_first_of(','));

            Bill billl = Bill(stoi(injaction), stoi(consumption));

            if (hashyear(stoi(billyear)) >= customerBills.size())
            {
                vector<Bill> bbill;
                customerBills.push_back(bbill);
                customerBills[customerBills.size()].resize(12);        
            }
            

            customerBills[hashyear(stoi(billyear))][hashmouth(stoi(billmouth))]=billl;

                }
        
        
    }
    
    
    
}
int Customer::hashyear(int y)
{
    return y-2020 ;
}

int Customer::hashmouth(int a)
{
    return a-1;
}

















void Customer::setFamilyAges(const vector<int>& ages )
{
    int size = ages.size();
    familyNumberAges.resize(size);
    for(int i=0;i<size;i++)
    {
        familyNumberAges[i] = ages[i];
    }
}

void Customer::setAdress(string a)
{
    address=a;
}

vector<vector<Bill>> Customer::getCustomerBills()
{
    return customerBills;
}

void Customer::updateAmount(double a)
{
    amount_mltv+=a;
}

void Customer::print()
{
    //will print only user infos, l billing tdiro l company
    cout<<"NAME :"<<customerName;
    cout<<"NUMBER OF FAMILY MEMBERS :"<<getFamilyNumber();
    cout<<"AGE OF FAMILY MEMBERS :"<<endl;
    for(int i=0;i<familyNumberAges.size();i++)
    {
        cout<<"AGE OF FAMILY MEMBER NUMBER "<<i+1<<": "<<familyNumberAges[i]<<endl;
    }
    cout<<"REGISTRATION DATE : "<<date_regist.day_regist<<"-"<<date_regist.month_regist<<"-"<<date_regist.year_regist<<endl;
    cout<<"CUSTOMER ADDRESS :"<<address;
}

int Customer::getFamilyNumber() const
{
    return familyNumberAges.size();
} 

int Customer::getID() const
{
  int index = ID.find_last_of('-');
  string last_part = ID.substr(index + 1);

  int id_number = stoi(last_part);

  return id_number;
}

Customer::Date Customer::getRegistrationDate() const
{
  return date_regist;
}

double Customer::getComulativeAmount() const
{
  return amount_mltv;
}

void Customer::setRegistrationDate(int year, int month, int day)
{
  date_regist.year_regist = year;
  date_regist.month_regist = month;
  date_regist.day_regist = day;
}

string Customer::getCustomerName() const
{
  return customerName;
}

vector<int> Customer::getFamilyAges() const
{
  return familyNumberAges;
}

string Customer::getAdress()
{
  return address;
}
