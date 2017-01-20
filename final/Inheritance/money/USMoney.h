//
// Created by prenga on 11/6/16.
//

// Decide what elements should be placed in the Money class, which should be virtual methods, etc.  You should be able to include a much richer set of functionality for CanadianMoney than in the original implementation.

#ifndef INHERITANCE_USMONEY_H
#define INHERITANCE_USMONEY_H

#include "Money.h"
#include "CanadianMoney.h"

class CanadianMoney;

class USMoney final : public Money {
private:
    char symbol = '$';
    double exchangeRate = 0.7488;
public:
    USMoney() : Money(0, 0) {};
    USMoney(const int dollars, const int cents) : Money(dollars, cents) {};
    USMoney(const double amount) : Money(amount) {};
    USMoney(const Money& m) : Money(m) {};

    USMoney(const CanadianMoney &m);
    void display() const;
    operator CanadianMoney() const;
};


#endif //INHERITANCE_USMONEY_H
