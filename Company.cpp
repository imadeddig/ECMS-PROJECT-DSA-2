#include "Company.h"
#include "Country.h"

Company::Company()
{

    ifstream countrie;
    countrie.open("countrie.text");
    if (!countrie)
    {
        cerr << "File could not be open" << endl;
        exit(1);
    }
    string line;
    getline(countrie, line);
    while (getline(countrie, line))
    {
        string countrieid = line.substr(0, line.find_first_of(','));

        string countriename = line.substr(line.find_first_of(',') + 1, line.length() - 1);
        countries.push_back(District(countrieid, countriename));
    }
    countrie.close();
    
    fstream departementorder;
    departementorder.open("departementorder.text") if (!departementorder)
    {
        cerr << "change the path name of your departement file to departement.text " exit(1);
    }

    string line;
    // the departement are store id,name,budget
    getline(departementorder, line);
    while (getline(departementorder, line);)
    {
        vector<Department> a;
        do
        {

            
            // i twill be like that dep1id,DepartmentName,ped1budget,performance , dep2  ;

            string depid = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string depname = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string depbudget = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
            string depperformance = line.substr(0, line.find_first_of(','));
            line = line.substr(line.find_first_of(','));
           
           

            a.push_back( Department(depid, depname, stoi(depbudget)));


        } while (line !='/n');

        departmentsStored.push_back(a);
       
        }
}








