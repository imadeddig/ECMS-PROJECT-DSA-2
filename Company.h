#ifndef COMPANY_H
#define COMPANY_H

#include "Country.h"
#include "Department.h"
#include "Company.h"
#include "Customer.h"
#include "Region.h"
#include "City.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>

using namespace std;
class Company
{
private:
    // saving the sorted departments in a hash table
    vector<vector<Department>> departmentsStored;
    vector<Country> countries;
    Customer winner;

public:
    Company();
    // order departments for the current year, give conditions to a specific date that departments should be inserted and sorted in that date, if not, show an error to the user
    vector<Department> orderAlldepartement();
    // storing the new stored department into the all sorted departmentf of the last year
    void storeNewDepartment(vector<Department>);
    // get performance of departments
    void getDepartmentPerformance(int startYear = 0, int endYear = 0);
    // return customer with most injection
    Customer getWinnerCustomer();
    // printing customers bills based on user choice
    void printBillCompany(int countryID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    void printBillCompany(int regionID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    void printBillCompany(int cityID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    void printBillCompany(int ditrictID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    ~Company();

    // inserting a customer (additonal function) this is a whole new customer
      void addCustomer(const string &name, vector<int> ages, double amount, int day, int mouth, int year, string adress, string districtID);
    void setBillFile();
     bool comparedep(Department, Department);
 
};
#endif
