#include "Department.h"
#include"City.h"
#include "Company.h"

Department::Department(string name, string id, float bud, float spent)
{

    if (name != "")
    {
        DepartmentName = name;
    }

    Departmentid = id;
    
       budget=bud;
    
    
}



void Department::updateBudget(float percentage)
{
    
    

    
       budget+=budget*percentage;
    
    
}

int Department::getBudget()
{
    return budget;
}

Department::Department()
{
}

Department::Department(int)
{
}

string Department::getDepartmentName()
{
    return DepartmentName;
}

Department::~Department()
{
}

float Department::getperformance()
{
    return performance;
}

float Department::getspent()
{
return spent;
}

Department::voidsetspent(float amount)
{
    if (spent-amount)
    {
       spent = spent - amount;
    }
}
