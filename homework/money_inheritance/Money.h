// Created by prenga on 11/4/16.

//Use appropriate modifiers (public, private, protected, virtual, override, final)

#ifndef INHERITANCE_MONEY_H
#define INHERITANCE_MONEY_H

#include <iostream>
using namespace std;

class Money {
protected:
    int dollars;
    int cents;
    double exchangeRate;
public:
// CONSTRUCTORS

    Money():Money(0, 0)
    {
    } //default constructor

    Money(const int dollars, const int cents)
    {
        set(dollars, cents);
    } // constructor

    Money(const double amount)
    {
        set(amount);
    } // constructor

    Money(const Money& m)
    {
        set(m.total());
    } // copy constructor

    ~Money()
    {
        cout << "My wallet is now empty" << endl;
    } // destructor



// MEMBER FUNCTIONS

    void set(const int dollars, const int cents)
    {
        this->dollars = dollars;
        this->cents = cents;
        recalculate();
    }  //set total amount

    void set(const double amount)
    {
        dollars = (int)amount;
        cents = (int)((amount - dollars) * 100);
        recalculate();
    } // set total amount with double

    void increase(const int dollars, const int cents)
    {
        this->dollars += dollars;
        this->cents += cents;
        recalculate();
    } // add by given amount

    void increase(const double amount)
    {
        int dollars = (int)amount;
        int cents = (int)((amount - dollars)*100);
        increase(dollars, cents);
    } // add by given double

    void increase(const Money &m)
    {
        increase(m.total());
    } // add from money class

    void decrease(const int dollars, const int cents)
    {
        this->dollars -= dollars;
        this->cents -= cents;
        recalculate();
    } // decrease by given ints

    void decrease(const double amount)
    {
        int dollars = (int)amount;
        int cents = (int)((amount - dollars)*100);
        decrease(dollars, cents);
    } // decrease by given double

    void decrease(const Money &m)
    {
        decrease(m.total());
    } // remove from money class

    void recalculate()
    {
        div_t divmod = div(cents, 100);
        dollars += divmod.quot;
        cents = divmod.rem;
        if (divmod.rem < 0) {
            dollars -=1;
            cents *= -1;
        }
    } // check that cents value is between 0 & 100

    double total() const
    {
        return dollars+(cents/100.0);
    } // return total $

    void setExchangeRate(const double rate)
    {
        exchangeRate = rate;
    }

    double getExchangeRate() const
    {
        return exchangeRate;
    }

    void display() const
    {
        cout << total();
    }



// OVERLOADED CONVERSION OPERATORS

    void operator() (const double d)
    {
        set(d);
    } // function call operator sets amount using a double

    void operator() (const int dollars, const int cents)
    {
        set(dollars, cents);
    } // function call operator sets amount using two ints

    operator double() const
    {
        return total();
    }// convert this value to a double

    operator string() const
    {
        double t = total();
        string s = to_string(t);
        s.erase ( s.find_last_not_of('0') + 1, string::npos );
        return s;
    }// convert this value to a string



// OVERLOADED ARITHMETIC OPERATORS

    Money operator + (const Money &m) const
    {
        Money money;
        money.set(dollars, cents);
        money.increase(m);
        return money;
    } // adds two Money objects and returns a money object

    Money operator - (const Money &m) const
    {
        Money money;
        money.set(dollars, cents);
        money.decrease(m);
        return money;
    } // subtracts two Money objects and returns a money object

    Money& operator += (const Money &m)
    {
        increase(m.total());
        return *this;
    } // operator += : to increase this Money object with the value of another Money object // myWallet += m;

    Money& operator += (const double d)
    {
        increase(d);
        return *this;
    } // increase this Money object with a double

    Money& operator -= (const Money &m)
    {
        decrease(m.total());
        return *this;
    } // decrease by the value of another Money object // myWallet -= m;

    Money& operator -= (const double d)
    {
        decrease(d);
        return *this;
    } // decrease by the amount of a double // myWallet -= 10.65;



// OVERLOADED COMPARISON OPERATORS

    bool operator > (const Money &m) const
    {
        return total() > m.total();
    } // return true if m1 value is more than m2 value

    bool operator >= (const Money &m) const
    {
        return total() >= m.total();
    } // return true if m1 value is more than m2 value

    bool operator < (const Money &m) const
    {
        return total() < m.total();
    } // return true if m1 value is less than m2 value

    bool operator <= (const Money &m) const
    {
        return total() <= m.total();
    } // return true if m1 value is more than m2 value

    bool operator == (const Money &m) const
    {
        return total() == m.total();
    } // return true if m1 & m2 totals are equal

    bool operator != (const Money &m) const
    {
        return total() != m.total();
    } // return true if m1 & m2 totals are not equal


    // OVERLOADED STREAM OPERATORS

    friend ostream & operator << (ostream &out, const Money &m)
    {
        m.display();
        return out;
    } // Override << to display a Money object

    friend istream & operator >> (istream &in, Money &m)
    {
        double amt;
        in >> amt;
        m.set(amt);
        return in;
    } // Override >> to store a Money object
};


#endif //INHERITANCE_MONEY_H
