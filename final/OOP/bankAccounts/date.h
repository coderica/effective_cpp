//
// Created by prenga on 10/2/16.
//
#pragma once

#ifndef PROBLEM_1_DATE_H
#define PROBLEM_1_DATE_H

#include <iostream>
#include <sstream>
using namespace std;

class date
{
private:
    int month;
    int day;
    int year;
public:
    date();
    date(string strDate);
    date(int month, int day, int year);
    void set(int month = 1, int day = 1, int year = 2016);
    void display();
};

class bad_date
{
    int month; int day;
public:
    bad_date(int month, int day) :month(month), day(day)
    { }
    void error() {
        cout << "Invalid date: " << endl
             << "Month: " << month << "  Day: " << day << endl;
    }
};

#endif //PROBLEM_1_DATE_H
