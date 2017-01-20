//
// Created by prenga on 10/2/16.
//

#include <iostream>
#include "money.h"
using namespace std;

money::money():money(1530, 22)
{ //generate random dollars and cents and call money(dollars, cents)
}

money::money(int dollars, int cents) : dollars(dollars), cents(cents=0) //money(int dollars, int cents=0);
{
}

void money::set(int dollars, int cents)
{ //set the amount of dollars and cents using individual integer values
    this->dollars = dollars;
    this->cents = cents;
    check();
}

void money::set(double amount)
{ //set the amount of dollars and cents using a double
    this->dollars = (int)amount;
    this->cents = (int)((amount - this->dollars)*100);
    check();
}

void money::increase(int dollars, int cents)
{ //add to the amount of dollars and cents using individual integer values
    this->dollars += dollars;
    this->cents += cents;
    check();
}

void money::increase(double amount)
{
    int dollars = (int)amount;
    int cents = (int)((amount - dollars)*100);
    increase(dollars, cents);
    check();
}

void money::decrease(int dollars, int cents)
{ //add to the amount of dollars and cents using individual integer values
    this->dollars -= dollars;
    this->cents -= cents;
    check();
}

void money::decrease(double amount)
{
    int dollars = (int)amount;
    int cents = (int)((amount - dollars)*100);
    decrease(dollars, cents);
    check();
}


void money::display()
{ //display the monetary value represented by the object
    cout << '$' << dollars << '.' << cents;
}

void money::check()
{
    div_t divmod = div(this->cents, 100);
    this->dollars += divmod.quot;
    this->cents = divmod.rem;
    if (divmod.rem < 0) {
        this->dollars -=1;
        this->cents *= -1;
    }
}