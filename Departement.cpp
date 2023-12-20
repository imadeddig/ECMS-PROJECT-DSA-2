#include"Departement.h"


Department::Department()
{

}

Department::Department(string name="", string id="", float bud=0, float spent=0)
{

    if (name != "")
    {
        DepartmentName = name;
    }

    Departmentid = id;
    
       budget=bud;
    
    cout<<endl<<"department"<<endl;
}

string Department::getDepartmentid()
{
  return Departmentid;
}


void Department::updateBudget(float percentage)
{
    
    

    
       budget+=budget*percentage;
    
    
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

float Department::getperformance()
{
    return spent;
}

float Department::getspent()
{
return spent;
}

void Department::setspent(float amount)
{
    if (spent-amount)
    {
       spent = spent - amount;
    }
}

