#ifndef INHERITANCE_CANADIANMONEY_H
#define INHERITANCE_CANADIANMONEY_H

#include <iostream>
#include "Money.h"
using namespace std;
class Money;

class CanadianMoney {
private:
    static double USExchangeRate;
    int dollars;
    int cents;
public:
    CanadianMoney();
    CanadianMoney(int dollars, int cents = 0);
    CanadianMoney(const double amount);
    CanadianMoney(const Money &m);

    void set(const int dollars, const int cents=0);
    void set(const double amount);
    void recalculate();
    double total() const;
    double toUSDollars() const;
    void setExchangeRate(const double rate);
    double getExchangeRate() const;

    operator Money() const;
    friend ostream & operator << (ostream &out, const CanadianMoney &m);
};

#endif //INHERITANCE_CANADIANMONEY_H
