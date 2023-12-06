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
    float spent ;
    

public:
    Department();
    Department(string,string,float,float);
    void updateBudget(float);
    int getBudget();
    float getperformance();
    float getspent();
    voidsetspent(float );
    
    
    string getDepartmentName();
    ~Department();
};
#endif
