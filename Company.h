#ifndef COMPANY_H
#define COMPANY_H

#include "Department.h"
#include "Company.h"
#include "Customer.h"

#include <vector>
#include <iostream>
using namespace std;
class Company
{
private:
    // saving the sorted departments in a hash table
    vector <vector<Department>> departmentsStored;
    vector<Country> countries;

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
    void printBillCompay(int countryID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    void printBillCompay(int regionID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    void printBillCompay(int cityID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    void printBillCompay(int ditrictID, int yearStart = 0, int yearEnd = 0, int monthStart = 0, int monthEnd = 0);
    ~Company();

    // inserting a customer (additonal function) this is a whole new customer
    void addCustomer(string address, int familyMembers, vector<int> familyMemberAges, string customerName, int countryID, int regionID, int cityID, int districtID);
    //this one is for the already existed customers in our files (additional function)
    void insertCustomer();
    // setting the new month's bill from a file for each customer (additional function), give conditions to a specific date that departments should be inserted and sorted in that date, if not, show an error to the user
    void setBillFile();

    //company now needs to sort all its data in a format that we could then search, we need to implement hash of countries goes to regions goes to cities goes to districts goes to a tree of customer
    void setPlan();
    //this function is going to enter a file, and then keep on calling the instances's constructors

    void setWeather();
};
#endif
