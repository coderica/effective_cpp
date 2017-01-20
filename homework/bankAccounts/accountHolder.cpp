//
// Created by prenga on 10/2/16.
//
#include "accountHolder.h"

accountHolder::accountHolder(string name, date joinDate)// : name(name), joinDate(joinDate)
{
    this->name = name;
    this->joinDate = joinDate;
    static int id = 0;
    this->id = ++id;
}

void accountHolder::display()
{
    cout << "Account Holder: " << name << '(' << id << "), " << "Joined ";
    joinDate.display();
    cout << endl;
}