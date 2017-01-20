#include <string>
#include "Money.h"


double Money::canadianExchangeRate = 0.7488;

// CONSTRUCTORS

Money::Money():Money(0, 0)
{
} //default constructor

Money::Money(const int dollars, const int cents)
{
    set(dollars, cents);
} // constructor

Money::Money(const double amount)
{
    set(amount);
} // constructor

Money::Money(const Money& m)
{
    set(m.total());
} // copy constructor

Money::Money(const CanadianMoney &m) : Money(m.toUSDollars())
{
} // conversion constructor from Canadian Money.

Money::~Money()
{
    cout << "My wallet is now empty" << endl;
} // destructor



// MEMBER FUNCTIONS

void Money::set(const int dollars, const int cents)
{
    this->dollars = dollars;
    this->cents = cents;
    recalculate();
}  //set total amount

void Money::set(const double amount)
{
    dollars = (int)amount;
    cents = (int)((amount - dollars) * 100);
    recalculate();
} // set total amount with double

void Money::increase(const int dollars, const int cents)
{
    this->dollars += dollars;
    this->cents += cents;
    recalculate();
} // add by given amount

void Money::increase(const double amount)
{
    int dollars = (int)amount;
    int cents = (int)((amount - dollars)*100);
    increase(dollars, cents);
} // add by given double

void Money::increase(const Money &m)
{
    increase(m.total());
} // add from money class

void Money::decrease(const int dollars, const int cents)
{
    this->dollars -= dollars;
    this->cents -= cents;
    recalculate();
} // decrease by given ints

void Money::decrease(const double amount)
{
    int dollars = (int)amount;
    int cents = (int)((amount - dollars)*100);
    decrease(dollars, cents);
} // decrease by given double

void Money::decrease(const Money &m)
{
    decrease(m.total());
} // remove from money class

void Money::recalculate()
{
    div_t divmod = div(cents, 100);
    dollars += divmod.quot;
    cents = divmod.rem;
	// @@ Note quite right. When dollars is 1 and cents is -1, we expect 0 dollars and 99 cents.
    if (divmod.rem < 0) {
        dollars -=1;
        cents *= -1;
    }
} // check that cents value is between 0 & 100

double Money::total() const
{
    return dollars+(cents/100.0);
} // return total $

void Money::setExchangeRate(const double rate)
{
    canadianExchangeRate = rate;
}

double Money::getExchangeRate() const
{
    return canadianExchangeRate;
}



// OVERLOADED CONVERSION OPERATORSe

void Money::operator() (const double d)
{
    set(d);
} // function call operator sets amount using a double

void Money::operator() (const int dollars, const int cents)
{
    set(dollars, cents);
} // function call operator sets amount using two ints

Money::operator double() const
{
    return total();
}// convert this value to a double

Money::operator string() const
{
    double t = total();
    string s = to_string(t);
	// @@ Could also use formatted ostrstream
    s.erase ( s.find_last_not_of('0') + 1, string::npos );
    return s;
}// convert this value to a string

Money::operator CanadianMoney() const
{
    CanadianMoney m =  total() * canadianExchangeRate;
    return m;
}



// OVERLOADED ARITHMETIC OPERATORS

Money Money::operator + (const Money &m) const
{
    Money money;
    money.set(dollars, cents);
    money.increase(m);
    return money;
} // adds two Money objects and returns a money object

Money Money::operator - (const Money &m) const
{
    Money money;
    money.set(dollars, cents);
    money.decrease(m);
    return money;
} // subtracts two Money objects and returns a money object

Money& Money::operator += (const Money &m)
{
    increase(m.total());
    return *this;
} // operator += : to increase this Money object with the value of another Money object // myWallet += m;

Money& Money::operator += (const double d)
{
    increase(d);
    return *this;
} // increase this Money object with a double

Money& Money::operator -= (const Money &m)
{
    decrease(m.total());
    return *this;
} // decrease by the value of another Money object // myWallet -= m;

Money& Money::operator -= (const double d)
{
    decrease(d);
    return *this;
} // decrease by the amount of a double // myWallet -= 10.65;



// OVERLOADED COMPARISON OPERATORS

bool Money::operator > (const Money &m) const
{
    return total() > m.total();
} // return true if m1 value is more than m2 value

bool Money::operator >= (const Money &m) const
{
    return total() >= m.total();
} // return true if m1 value is more than m2 value

bool Money::operator < (const Money &m) const
{
    return total() < m.total();
} // return true if m1 value is less than m2 value

bool Money::operator <= (const Money &m) const
{
    return total() <= m.total();
} // return true if m1 value is more than m2 value

bool Money::operator == (const Money &m) const
{
    return total() == m.total();
} // return true if m1 & m2 totals are equal

bool Money::operator != (const Money &m) const
{
    return total() != m.total();
} // return true if m1 & m2 totals are not equal



// OVERLOADED STREAM OPERATORS

ostream & operator << (ostream &out, const Money &m)
{
	// @@ Formatted output might be nice!
    out << m.total();
    return out;
} // Override << to display a Money object

istream & operator >> (istream &in, Money &m)
{
    double amt;
    in >> amt;
    m.set(amt);
    return in;
} // Override >> to store a Money object
