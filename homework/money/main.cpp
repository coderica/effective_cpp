#include <iostream>
#include "utilities.h"
#include "Money.h"
#include "CanadianMoney.h"

int main() {
// Create a test program for each method created. Note that some of the operators may supersede others. This is ok, comment out test code as needed to ensure that every method is exercised.
    cout << endl << "TESTING CANADIAN MONEY CLASS... " << endl << endl;
    canadianMoneyTests();

    cout << endl << endl << endl << endl << "TESTING MONEY CLASS... " << endl << endl;
    moneyTests();
    return 0;
}