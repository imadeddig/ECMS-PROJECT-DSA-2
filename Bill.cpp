#include "Bill.h"
#include <cmath>
Bill::Bill(const double &c = 0, const double &i = 0)
{
    setEnergyConsumption(c);
    setEnergyInjection(i);
    setTotalDifference();
}

Bill::Bill()
{
}

void Bill::setBill(const double &c, const double &i)
{
    setEnergyConsumption(c);
    setEnergyInjection(i);
    setTotalDifference();
}

void Bill::setEnergyConsumption(const double &c)
{
    EnergyConsumption = c > 0 ? c : 0;
    PriceTotalConsumption = 5 * EnergyConsumption;
}

void Bill::setEnergyInjection(const double &i)
{
    EnergyInjection = i > 0 ? i : 0;
    PriceTotalInjection = 3 * EnergyInjection;
}

void Bill::setTotalDifference()
{
    TotalDifference = PriceTotalConsumption - PriceTotalInjection;
}

double Bill::getEnergyInjection()
{
    return EnergyInjection;
}

double Bill::getEnergyConsumption()
{
    return EnergyConsumption;
}

double Bill::getPriceTotalConsumption()
{
    return PriceTotalConsumption;
}

double Bill::getPriceTotalInjection()
{
    return PriceTotalInjection;
}

double Bill::getTotalDifference()
{
    return TotalDifference;
}

void Bill::print()
{
    cout << "The Energy Consumed: " << getEnergyConsumption() << endl;
    cout << "The Energy Injected: " << getEnergyInjection() << endl;
    cout << "The Price of The Energy Consumed: " << getEnergyConsumption() << endl;
    cout << "The Price of The Energy Injected: " << getEnergyConsumption() << endl;
    if (TotalDifference < 0)
        cout << "The Customer will be payed : " << abs(getTotalDifference()) << " DA" << endl;
    else
        cout << "The Customer will  pay : " << getTotalDifference() << "DA" << endl;
}
