//Ground Rules: Do not create the method functions inline.  Separate code into separate .h and .cpp files as was described in class.
//Deliverable:  Submit code files as a zip file.  Please include a makefile if you used one.

#include <iostream>
#include <vector>
#include "date.h"
#include "money.h"
#include "accountHolder.h"
#include "bankAccount.h"

using namespace std;

int main() {
    vector<bankAccount> accounts = { // create an array of 3 accounts with all fields populated.
            bankAccount(
                    {new accountHolder("Erica Prenga", date()), // One of the accounts should have two account holders.
                     new accountHolder("Gjoneto Prenga", date())},
                    money(),
                    date()
            ),
            bankAccount(
                    {new accountHolder("Renee Marroquin", date())},
                    money(),
                    date()
            ),
            bankAccount(
                    {new accountHolder("Juliana Casey", date())},
                    money(),
                    date()
            )
    };

    for (int i=0; i<accounts.size(); i++) { // Display all account information.
        cout << "Account " << i+1 << ':' << endl;
        accounts[i].display();
        cout << endl;
    }

    accounts[0].deposit(30, 23);
    accounts[2].deposit(342, 90); // deposit money into 2 of the accounts
    accounts[1].transfer(400.32, &(accounts[0])); // transfer money from one account to another.

    for (int i=0; i<accounts.size(); i++) { // Display all account information.
        cout << "Account " << i+1 << ':' << endl;
        accounts[i].display();
        cout << endl;
    }

    return 0;
}