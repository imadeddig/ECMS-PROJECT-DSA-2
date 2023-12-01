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
  int ID;
  static int countID;
  string customer_name;
  string miniadress;
  int family_number;
  vector<int> ages;
  double amount_cmltv = 0;
  string adress;

  struct Date
  { // this struct is for the registration date .
    int year_regist;
    int month_regist;
    int day_regist;
  } date_regist;

  Region rgn;
  District dstrct;
  city ct;

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
  string getMiniAdress();
  // setters function

  void setCustomerName(const string &);
  void setFamilyNumber(int);
  void setFamilyAges(const vector<int> &);
  void setRegistrationDate(int, int, int);
  void setComulativeAmount(double);
  void setMiniAdress(string);
  void setAdress(Region, District, city);

  //
  void updateAmount(double);

  void print();
};

#endif