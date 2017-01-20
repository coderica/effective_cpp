//
// Created by prenga on 10/2/16.
//
#include <vector>
#include "bankAccount.h"

bankAccount::bankAccount(vector<accountHolder*> accountHolders, money amount, date creationDate) : accountHolders(accountHolders), amount(amount), creationDate(creationDate)
{
    static int id = 100;
    this->id = id++;
}

void bankAccount::addAccountHolder(accountHolder* holder)
{ // add an account holder
    accountHolders.push_back(holder);
}
void bankAccount::deposit(int dollars, int cents)
{ // deposit (dollars and cents)
    amount.increase(dollars, cents);
}

void bankAccount::withdraw(int dollars, int cents)
{ // withdraw(dollars and cents)
    amount.decrease(dollars, cents);
}

void bankAccount::transfer(double cash, bankAccount* account)
{ // transfer money to another account
    amount.decrease(cash);
    account->amount.increase(cash);
}

void bankAccount::display()
{ // display account (to display all account data)

    int index = (int)accountHolders.size()-1;
    while (index > 0) {
        accountHolders[index]->display();
        index --;
    }
    accountHolders[index]->display();
    cout << "Current holdings: ";
    amount.display();
    cout << endl << "Created ";
    creationDate.display();
    cout << endl;
}