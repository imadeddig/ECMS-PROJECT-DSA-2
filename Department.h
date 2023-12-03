#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include <iostream>
using namespace std;

class Department
{
private:
   int budget = 1000000;
   string DepartmentName;

public:
   Department();
   void setBudget(int);
   int getBudget();
   void setDepartmentName(string);
   string getDepartmentName();
   ~Department();
};
#endif
