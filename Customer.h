#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Region.h"
#include "District.h"
#include"Bill.h"
#include <string>
#include <vector>
using namespace std;

class Customer
{
private:
    // implement a hash function that hashes 2022 to 0..
    vector<vector<Bill>> customerBills;
    string ID;
    string customerName;
    string address;
   
    vector<int> familyNumberAges;
    double amount_mltv = 0;
   

    struct Date
    { // this struct is for the registration date .
        int year_regist;
        int month_regist;
        int day_regist;

    } date_regist;

public:
    Customer(const string &, const string &, vector<int>, double, int, int, int,string);
    // getters function 
    // will transforme the string to integer and return just the last part
    int getID();
    string getCustomerName() const;
    int getFamilyNumber() const;
    vector<int> getFamilyAges() const;
    Date getRegistrationDate() const;
    double getComulativeAmount() const;
    string getAdress();

    // setters function

    void setCustomerName(const string &);

    

    void setFamilyAges(const vector<int> &);

    void setRegistrationDate(int, int, int);

   
   
    void setAdress(string);

    //
    void updateAmount(double);
// take a year and return it position
    int hashyear(int);
    int hashmouth (int) ;

    void print();
};

#endif
