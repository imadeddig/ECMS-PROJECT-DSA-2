#ifndef DISTRICT_H
#define DISTRICT_H
#include <string>
#include <iostream>
using namespace std;
#include <vector>
class District
{
    private:
    string districtName;
    int districtID;
    BinarySearchTree* customersTree; //is it pointer?
    vector <year> climate;//linked list of weather day
    //got confused between different years
    //each year should have 12months array, each mon,th should have at max 31array of days, each day should have a specific weather
    static int districtIDCounter; //a counter in order to set our ids
//for ids, there should be a counter globally in order to set the id

    public:
    District(const string& DistrictNameDef);
    int getDistrictID();
    string getDistrictName();
    BinarySearchTree getCustomers();
    void addCustomer(const Customer& cusToBeAdded);
    void deleteCustomer(const Customer& cusToBeDeleted);
    Customer searchCustomer(int customerID);
    vector <weather> getClimate();
    weather getDayWeather(const day&, const month&, const year&);
};
#endif