//
// Created by prenga on 11/6/16.
//

// Decide what elements should be placed in the Money class, which should be virtual methods, etc.  You should be able to include a much richer set of functionality for CanadianMoney than in the original implementation.

#ifndef INHERITANCE_CANADIANMONEY_H
#define INHERITANCE_CANADIANMONEY_H

#include "Money.h"
#include "USMoney.h"

class USMoney;

class CanadianMoney final : public Money {
private:
    string symbol = "C$";
    double exchangeRate = 1.334560;
public:
    CanadianMoney() : Money(0, 0) {};
    CanadianMoney(const int dollars, const int cents) : Money(dollars, cents) {};
    CanadianMoney(const double amount) : Money(amount) {};
    CanadianMoney(const Money& m) : Money(m) {};

    CanadianMoney(const USMoney &m);
    void display() const;
    operator USMoney() const;
};


#endif //INHERITANCE_CANADIANMONEY_H
