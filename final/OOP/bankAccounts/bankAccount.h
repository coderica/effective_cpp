//
// Created by prenga on 10/2/16.
//
#pragma once

#ifndef PROBLEM_1_BANKACCOUNT_H
#define PROBLEM_1_BANKACCOUNT_H

#include "accountHolder.h"
#include "money.h"

class bankAccount
{
private:
    int id;
    vector<accountHolder*> accountHolders;
    money amount;
    date creationDate;
public:
    bankAccount(vector<accountHolder*>, money, date);
    void addAccountHolder(accountHolder*); // add an account holder
    void deposit(int, int); // deposit (dollars and cents)
    void withdraw(int, int); // withdraw(dollars and cents)
    void transfer(double, bankAccount*); // transfer money to another account
    void display(); // display account (to display all account data)
};


#endif //PROBLEM_1_BANKACCOUNT_H
