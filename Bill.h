#include <iostream>
using namespace std;

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
    Bill(const double &, const double &);
    Bill();
    void setBill(const double &, const double &);
    double getEnergyInjection();
    double getEnergyConsumption();
    double getPriceTotalConsumption();
    double getPriceTotalInjection();
    double getTotalDifference();
    void print();
};
