#include "CanadianMoney.h"


double CanadianMoney::USExchangeRate = 1.334560;

// CONSTRUCTORS

CanadianMoney::CanadianMoney():CanadianMoney(0, 0)
{
} //default constructor

CanadianMoney::CanadianMoney(const int dollars, const int cents)
{
    set(dollars, cents);
} // constructor

CanadianMoney::CanadianMoney(const double amount)
{
    set(amount);
} // constructor

CanadianMoney::CanadianMoney(const Money &m) : CanadianMoney(m.total() / USExchangeRate)
{
} // copy constructor



// MEMBER FUNCTIONS

void CanadianMoney::set(const int dollars, const int cents)
{
    this->dollars = dollars;
    this->cents = cents;
    recalculate();
}  //set total amount

void CanadianMoney::set(const double amount)
{
    dollars = (int)amount;
    cents = (int)((amount - dollars)*100);
    recalculate();
} // set total amount with double

void CanadianMoney::recalculate()
{
    div_t divmod = div(cents, 100);
    dollars += divmod.quot;
    cents = divmod.rem;
	// @@ Bug. When dollars = 1 and cents = -1, we expect 99 cents.
    if (divmod.rem < 0) {
        dollars -=1;
        cents *= -1;
    }
} // check that cents value is between 0 & 100

double CanadianMoney::total() const
{
    return dollars+(cents/100.0);
} // return total $

double CanadianMoney::toUSDollars() const
{
    double amount = total() / USExchangeRate;
    return amount;
}

void CanadianMoney::setExchangeRate(const double rate)
{
    USExchangeRate = rate;
}

double CanadianMoney::getExchangeRate() const
{
    return USExchangeRate;
}



// OVERLOADED OPERATORS

CanadianMoney::operator Money() const
{
    Money m = toUSDollars();
    return m;
} // conversion operator to convert to US Dollars

ostream & operator << (ostream &out, const CanadianMoney &m)
{
	// @@ Formatted output would be nice!
    out << m.total();
    return out;
} // Override << to display a Money object