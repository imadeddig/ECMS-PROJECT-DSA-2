

#include"company.h"

#include<string>

class dipartement
{
private:
   int budget = 1000000 ;
   int IDdepartement ;
   string namedipartement ;
   

       public : dipartement();
   int gettotalpaid();
   int gettotalpaid(int beganyear, int endmouth);
   int gettotalpaid(int beganyear, int beganmouth, int endyear, int endmouth);
   void setbudget(int);
   int getbudget();
   void setiddepartement();
   void setnamedep(string a);
   string getnamedep();
   int getiddepartement();

   ~dipartement();
};
