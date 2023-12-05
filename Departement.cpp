#include "Department.h"
#include"City.h"
#include "Company.h"

Department::Department(string name, string id, int bud)
{

    if (name != "")
    {
        DepartmentName = name;
    }

    Departmentid = id;
    if (bud!=0)
    {
       budget=bud;
    }
    
}



void Department::updateBudget(float percentage)
{
    
    

    if (percentage>0&& percentage<1)
    {
       budget+=budget*percentage;
    }
    
}

int Department::getBudget()
{
    return budget;
}


string Department::getDepartmentName()
{
    return DepartmentName;
}

Department::~Department()
{
}
