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
