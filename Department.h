
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
    string getDepartmentid();
    void updateBudget(float);
    int getBudget();
    float getperformance();
    float getspent();
    void setspent(float );
    
    
    string getDepartmentName();
    ~Department();
   
};
