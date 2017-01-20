// @@ Use #pragma once instead of guard macros
#ifndef INHERITANCE_MONEY_H
#define INHERITANCE_MONEY_H

#include <iostream>
#include "CanadianMoney.h"
using namespace std;
class CanadianMoney;

class Money {
private:
    int dollars;
    int cents;
    static double canadianExchangeRate;
public:
    Money();
    Money(const int dollars, const int cents = 0);
    Money(const Money &);
    Money(const double amount);
	// @@ grader's note. Erica's compiler didn't like it when this was const,
	// but Visual Studio seems fine with it, so I've added the const as per
	// Erica's original intentions.
    Money(const CanadianMoney &m); 
    ~Money();

    void set(const int dollars, const int cents=0);
    void set(const double amount);
    void increase(const int dollars, const int cents=0);
    void increase(const double);
    void increase(const Money &m);
    void decrease(const int dollars, const int cents=0);
    void decrease(const double);
    void decrease(const Money &m);
    double total() const;
    void recalculate();
    void setExchangeRate(const double rate);
    double getExchangeRate() const;

    void operator() (const double d);
    void operator() (const int dollars, const int cents);
    operator double() const;
    operator string() const;
    operator CanadianMoney() const;

    Money operator + (const Money &m) const;
    Money operator - (const Money &m) const;
    Money & operator += (const Money &m);
    Money & operator += (const double d);
    Money & operator -= (const Money &m);
    Money & operator -= (const double d);

    bool operator > (const Money &m) const;
    bool operator < (const Money &m) const;
    bool operator >= (const Money &m) const;
    bool operator <= (const Money &m) const;
    bool operator == (const Money &m) const;
    bool operator != (const Money &m) const;

    friend ostream & operator << (ostream & out, const Money &m);
    friend istream & operator >> (istream & in, Money &m);
};

#endif //INHERITANCE_MONEY_H
