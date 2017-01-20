#include <iostream>
#include "utilities.h"
#include "Money.h"
#include "CanadianMoney.h"

// @@ Good tests.
// @@ Would be even better if expected results were displayed, or even better, validation of results,
// displaying success/failure.
int main() {
// Create a test program for each method created. Note that some of the operators may supersede others. This is ok, comment out test code as needed to ensure that every method is exercised.
    cout << endl << "TESTING CANADIAN MONEY CLASS... " << endl << endl;
    canadianMoneyTests();

    cout << endl << endl << endl << endl << "TESTING MONEY CLASS... " << endl << endl;
    moneyTests();
    return 0;
}