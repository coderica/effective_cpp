//
// Created by prenga on 10/2/16.
//
#pragma once

#ifndef PROBLEM_1_ACCOUNTHOLDER_H
#define PROBLEM_1_ACCOUNTHOLDER_H

#include "date.h"

class accountHolder
{
private:
    string name;
    date joinDate;
    int id;
public:
    accountHolder(string, date);
    void display();
};

#endif //PROBLEM_1_ACCOUNTHOLDER_H
