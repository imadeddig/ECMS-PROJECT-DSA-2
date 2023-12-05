#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include <iostream>
using namespace std;

class Department
{
private:
    int budget ;
    string DepartmentName;
    string Departmentid;

public:
    Department(string,string,int);
    void updateBudget(float);
    int getBudget();
    
    string getDepartmentName();
    ~Department();
};
#endif
