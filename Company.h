
#include "Country.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include<string>

using namespace std;
class Company
{
private:
    // saving the sorted departments in a hash table
    
    vector<Country> countries;
    
    struct depart
    {
        Department dep ;
        double performence =0;
    };

    Customer winner;

    public:
    vector<Country> getCountry();
    Company();
    // order departments for the current year, give conditions to a specific date that departments should be inserted and sorted in that date, if not, show an error to the user
    void orderAlldepartement();
    // storing the new stored department into the all sorted departmentf of the last year
    
    


    
    void getDepartmentPerformance(int startYear , int endYear ,int,int);
           // return customer with most injection
    Customer getWinnerCustomer();
   

    void printBillCountry(string countryID, int yearStart , int yearEnd , int monthStart , int monthEnd );
    void printBillRegion(string regionID, int yearStart , int yearEnd , int monthStart , int monthEnd );
    void printBillCity(string cityID, int yearStart , int yearEnd , int monthStart , int monthEnd );
    void printBillDistrict(string ditrictID, int yearStart , int yearEnd , int monthStart , int monthEnd );
void callprint(string id, int yearStart , int yearEnd , int monthStart , int monthEnd );
    ~Company();
      
    static bool compardep2(depart a, depart b)
{
  return a.performence > b.performence;
}
       void addCustomer(const string &name, vector<int> ages, double amount, int day, int mouth, int year, string adress, string districtID);
    void setBillFile();
    bool comparedep(Department, Department);
    void inOrderTraversal(BinaryNode *root, BinarySearchTree*,int yearStart, int yearEnd, int monthStart, int monthEnd);
    void printBillForOneCustome(BinarySearchTree *root, int idcust, int yearStart, int yearEnd, int monthStart, int monthEnd);
 void  printBillForOneCustomer(string givenID, int yearStart, int yearEnd, int monthStart, int monthEnd);
};


