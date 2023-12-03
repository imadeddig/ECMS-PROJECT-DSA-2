#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Region.h"
#include "District.h"
#include <string>
#include <vector>
using namespace std;

class Customer
{
private:
//implement a hash function that hashes 2022 to 0.. 
  vector<vector<Bill>> customerBills;
  string ID;
  string customerName;
  string address;
  int familyNumber;
  vector <int> familyNumberAges;
  double amount_mltv = 0;

  struct Date
  { // this struct is for the registration date .
    int year_regist;
    int month_regist;
    int day_regist;
  } date_regist;

public:
  Customer(const string &, const string &, int, vector<int>, double, int, int, int, Region, District, city);
  // getters function
  int getID();
  string getCustomerName() const;
  int getFamilyNumber() const;
  vector<int> getFamilyAges() const;
  Date getRegistrationDate() const;
  double getComulativeAmount() const;
  string getAdress();
  // setters function

  void setCustomerName(const string &);
  void setFamilyNumber(int);
  void setFamilyAges(const vector<int> &);
  void setRegistrationDate(int, int, int);
  void setComulativeAmount(double);
  void setMiniAdress(string);
  void setAdress(Region, District, City);

  //
  void updateAmount(double);

  void print();
};

#endif
