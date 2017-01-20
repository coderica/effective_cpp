//
// Created by prenga on 11/6/16.
//

#include "CanadianMoney.h"

CanadianMoney::CanadianMoney(const USMoney &m)
{
    set(m.total() / exchangeRate);
} // copy constructor

void CanadianMoney::display() const
{
    cout << "C$" << total();
} // Override to display symbol

CanadianMoney::operator USMoney() const
{
    USMoney m = total() / exchangeRate;
    return m;
} // conversion operator to convert to US Dollars
