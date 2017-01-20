// Created by prenga on 11/4/16.

// Implement a class hierarchy given the following set of classes:

// Employee
//      data members: name and payRate
//      methods: pay()
//      override << to display employee’s name and pay

// SalariedEmployee derived from Employee
//      overrides pay() – note pay is the value of payRate

// HourlyEmployee derived from Employee
//      data member: hoursWorked
//      overrides pay()– note pay is the payRate times the hoursWorked, Pay 1.5 times the rate for hours in excess of 40 hours.

//SalesEmployee derived from Employee
//      static member: commissionRate
//      data member: totalSales
//      overrides pay()– note calculate the pay is the payRate as a base salary plus the totalSales times the commissionRate

//Use appropriate modifiers (public, private, protected, virtual, override, final)

#ifndef INHERITANCE_EMPLOYEE_H
#define INHERITANCE_EMPLOYEE_H


class Employee {

};


#endif //INHERITANCE_EMPLOYEE_H
