#include "Customer.h"

void Customer::setFamilyAges(vector<int> ages)
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

int Customer::getID()
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


