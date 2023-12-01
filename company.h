
#include "dipartement.h"

#include <vetor>


class company
{
private:
    vector<departement> alldepartement;

public:
    company();
    void orderalldepartement();
    friend void dipartement::setbudget(int );
    
     ~company();
};

inline void company::orderalldepartement()
{

}
company::company(/* args */)
{
}

company::~company()
{
}
