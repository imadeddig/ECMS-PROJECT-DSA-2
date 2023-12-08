#ifndef DISTRICT_H
#define DISTRICT_H
#include <string>
#include "YearWeather.h"
#include "BinarySearchTree.h"
#include "Customer.h"
#include <iostream>
using namespace std;
#include <vector>
class District
{
    private:
    string districtName;
    string districtID;
    int numOfCustomers=0;
    BinarySearchTree *customersTree; // customers that are in that region
    HashWeather  climate;
    double cd=0;
    //for ids, there should be a counter globally in order to set the id

    public:
    District(const string&, const string&);
    string getDistrictID();
    string getDistrictName();
    BinarySearchTree* getCustomers(); // return a pointer to the root of a binary tree that contains all the customers in the district
    void getDayWeather(int& day, int& month,int&year);
    HashWeather getWeather();

// new functions
    double OneDestrictPerf(int startYear = 0,int startMonth = 0, int endYear = 0, int endMonth = 0);

    double getcumulativeofallcust(BinaryNode *,int startYear = 0,int startMonth = 0, int endYear = 0, int endMonth = 0);
};
#endif

// Sugesstion
// 1: the get Dayweather isn't neccessary since the district class contains the hashweather which conatains the years and the waether of each day so it has the complete access wheter to have the information or set it (so we have to reset the day struct as a data member of the class hashweather)  
// 2: the global counter should be just in customer or we should add another counter for the district 
// problems
// 1:for the getweather is it returning the dayweather or all the hashweather content
//suggestions
// 1:we should have two functions one takes the start date and end date if the user wants to dispaly the weather from a specific date to another
// and the second if he want's a specific day(this functions is called in the first one)
//a third one for displaying all the weathers (this will call the first function inside it) .
