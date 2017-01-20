//
// Created by prenga on 10/2/16.
//

#ifndef PROBLEM_1_MONEY_H
#define PROBLEM_1_MONEY_H

class money
{
private:
    int dollars;
    int cents;
public:
    money();
    money(int, int);
    void set(int, int); //set the amount of dollars and cents using individual integer values
    void set(double); //set the amount of dollars and cents using a double
    void increase(int, int); //add to the amount of dollars and cents using individual integer values
    void increase(double);
    void decrease(int, int); //add to the amount of dollars and cents using individual integer values
    void decrease(double);
    void display(); //display the monetary value represented by the object
    void check(); //check that cents value is between 0 & 100
};

#endif //PROBLEM_1_MONEY_H
