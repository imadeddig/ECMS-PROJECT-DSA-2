#include "dipartement.h"
#include "company.h"
#include <iostream>

using namespace std;

int dipartement::departementid = 0;

dipartement::dipartement()
{
    IDdepartement= departementid ;
    departementid++ ;
}

int dipartement::gettotalpaid()
{
    return 0;
}

int dipartement::gettotalpaid(int beganyear, int endmouth)
{
    return 0;
}

int dipartement::gettotalpaid(int beganyear, int beganmouth, int endyear, int endmouth)
{
    return 0;
}

inline void dipartement::setbudget( int place )
{

    if (place ==1)
    {
             budget+=budget*0.15;

}    

else  if ( place <= 10 && place > 1)
{
             budget += budget *0.1 ;
}

else if (place == alldepartement.size())
{
             budget -= budget * 0.15;
           }
           else if (place < alldepartement.size() && place >= alldepartement.size()-10)
           {
            budget -= budget *0.1 ;
           }
           




}

inline int dipartement::getbudget()
{
    return 0;
}

inline void dipartement::setiddepartement()
{


}

inline int dipartement::getiddepartement()
{
    return 0;
}


dipartement::~dipartement()
{
}
