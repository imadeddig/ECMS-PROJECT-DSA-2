

#include"company.h"



class dipartement
{
private:
   int budget = 1000000 ;
   int IDdepartement ;
   static departementid ;

       public : dipartement();
   int gettotalpaid();
   int gettotalpaid(int beganyear, int endmouth);
   int gettotalpaid(int beganyear, int beganmouth, int endyear, int endmouth);
   void setbudget(int);
   int getbudget();
   void setiddepartement();
   int getiddepartement();

   ~dipartement();
};
