//
// Created by prenga on 10/2/16.
//
#include <iostream>
#include <sstream>
#include "date.h"

using namespace std;

date::date(): date(1,1,2016)
{ //generate random date
}

date::date(string strDate)
{

    istringstream s1(strDate);
    s1 >> month;
    s1.get();
    s1 >> day;
    s1.get();
    s1 >> year;
}

date::date(int month, int day, int year) : month(month), day(day), year(year)
{  }

void date::set(int month, int day, int year)
{
    if (month > 12 || day > 31)
        throw(bad_date(month, day));
    this->month = month;
    this->day = day;
    this->year = year;
}

void date::display()
{
    cout << month << '/' << day << '/' << year;
}