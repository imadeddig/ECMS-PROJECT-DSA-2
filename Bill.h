#ifndef BILL_H
#define BILL_H
#include"Customer.h"
class Bill
{
private:
int billMonth;
    double EnergyConsumption;
    double EnergyInjection;
    double PriceTotalConsumption;
    double PriceTotalInjection;
    double TotalDifference;
    void setEnergyConsumption(const double &);
    void setEnergyInjection(const double &);
    void setTotalDifference();

public:
    Bill(const double&, const double&);
    void setBill(const double &, const double &);
    void getBill();
    double getEnergyInjection();
    double getEnergyConsumption();
    double getPriceTotalConsumption();
    double getPriceTotalInjection();
    double getTotalDifference();
    void print();
};



#endif