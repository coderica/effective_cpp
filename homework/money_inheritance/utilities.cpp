//
// Created by prenga on 11/5/16.
//

#include "utilities.h"
#include "Money.h"
#include "USMoney.h"
#include "CanadianMoney.h"

string trueOrFalse(bool b)
{
    string s = b ? "true" : "false";
    return s;
}

void moneyTests()
{

    Money* m1 = new Money(); // Money()
    cout << "1: " << *m1 << endl; // operator << overload

    Money* m2 = new Money(7, 4); // Money(const int dollars, const int cents = 0)
    cout << "2: " << *m2 << endl;

    USMoney m3 = 332.21;    // Money(const double amount)
// NOTE: Construction appears to warp floats - debugged but not sure the cause / how to adjust for it (seems like a c++ issue - not caused directly by my functions)
    cout << "3: " << m3 << endl;

    Money m4 = m3; //    Money(const Money &)
    cout << "4: " << m4 << endl;

    CanadianMoney cm = 1;
    Money m6 = cm;
    cout << "6: " << m6 << endl;

    m1->set(2); // void set(const int dollars, const int cents=0);
    cout << "1: " << *m1 << endl;

    m3.set(55.24); // void set(const double amount);
    cout << "3: " << m3 << endl;

    cout << "3: " << static_cast<CanadianMoney>(m3) << endl; // operator Money() const;

    cout << "Rate: " << m2->getExchangeRate() << endl; // void getExchangeRate(const double rate);
    m3.setExchangeRate(.892); // void setExchangeRate(double rate);
    cout << "Rate: " << m2->getExchangeRate() << endl;

    m1->increase(44, 39); // void increase(const int dollars, const int cents=0)
    cout << "1: " << *m1 << endl;
    m1->decrease(44, 39); // void decrease(const int dollars, const int cents=0)
    cout << "1: " << *m1 << endl;
    m1->increase(44.39); // void increase(const double)
    cout << "1: " << *m1 << endl;
    m1->decrease(44.39); // void decrease(const double)
    cout << "1: " << *m1 << endl;
    m1->increase(*m2); // void increase(const Money &m)
    cout << "1: " << *m1 << endl;
    m1->decrease(*m2); // void decrease(const Money &m)
    cout << "1: " << *m1 << endl;

    m3(3.2);// void operator() (const double d)
    cout << "3: " << m3 << endl;
    m3(33, 25);// void operator() (const int dollars, const int cents)
    cout << "3: " << m3 << endl;

    double d = m3;// operator double() const
    string s = m3;// operator string() const
    cout << "3: " << d << ' ' << s << endl;

    Money m5 = *m2 + m3; // Money operator + (const Money &m) const
    cout << "5: " << m5 << endl;
    cout << "2: " << *m2 << endl;
    m5 = m3 - *m2; // Money operator - (const Money &m) const
    cout << "5: " << m5 << endl;
    m5 += *m1; // Money & operator += (const Money &m)
    cout << "5: " << m5 << endl;
    m5 += 3.3; // Money & operator += (const double d)
    cout << "5: " << m5 << endl;
    m5 -= *m1; // Money & operator -= (const Money &m)
    cout << "5: " << m5 << endl;
    m5 -= 3.3; // Money & operator -= (const double d)
    cout << "5: " << m5 << endl;

    cout << endl << "1: " << *m1 << endl;
    cout << "2: " << *m2 << endl;
    cout << "3: " << m3 << endl;
    cout << "4: " << m4 << endl;
    cout << "5: " << m5 << endl << endl;

    bool b = m5 > *m1; // bool operator > (const Money &m) const
    cout << trueOrFalse(b) << endl;
    b = m5 < *m1; // bool operator < (const Money &m) const
    cout << trueOrFalse(b) << endl;
    b = m5 >= *m1; // bool operator >= (const Money &m) const
    cout << trueOrFalse(b) << endl;
    b = m5 <= *m1; // bool operator <= (const Money &m) const
    cout << trueOrFalse(b) << endl;
    b = m5 == *m1; // bool operator == (const Money &m) const
    cout << trueOrFalse(b) << endl;
    b = m5 != *m1; // bool operator != (const Money &m) const
    cout << trueOrFalse(b) << endl;

    cout << endl << "Enter dollars and cents (separate by a period) : ";
    cin >> *m2; // istream & operator >> (istream & in, Money &m)
    cout << *m2 << endl;

    cout << endl;
    delete m1;
    delete m2;
}

void canadianMoneyTests()
{
    CanadianMoney* cm1 = new CanadianMoney(); // CanadianMoney();
    cout << "1: " << *cm1 << endl; // ostream & operator << (ostream & out) const;

    CanadianMoney* cm2 = new CanadianMoney(7, 4);// CanadianMoney(int dol, int cent = 0);
    cout << "2: " << *cm2 << endl;

    CanadianMoney cm3 = 332.21; // CanadianMoney(const double amount);
    cout << "3: " << cm3 << endl;

    USMoney m = 1;
    CanadianMoney* cm4 = new CanadianMoney(m); // CanadianMoney(const Money &m);
    cout << "4: " << *cm4 << endl;

    cm1->set(2); // void set(const int dollars, const int cents=0);
    cout << "1: " << *cm1 << endl;

    cm3.set(55.24); // void set(const double amount);
    cout << "3: " << cm3 << endl;
    cout << "3: " << static_cast<Money>(cm3) << endl; // operator Money() const;
/*    NOTE: This line is the sister test to line 38.
 *    If I remove 'const' from the << operators in both classes,
 *    this line will still function,
 *    while line 38 will throw the compiler error
 *    "invalid operands to binary expression".
 *    Any ideas why? */

    cout << "Rate: " << cm2->getExchangeRate() << endl;
    cm3.setExchangeRate(.892); // void setExchangeRate(double rate);
    cout << "Rate: " << cm2->getExchangeRate() << endl;

    cout << endl;
    delete cm1;
    delete cm2;
}
