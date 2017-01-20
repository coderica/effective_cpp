#pragma once

#ifndef PAYROLL_OBJECTS_H
#define PAYROLL_OBJECTS_H

using namespace std;

struct employee
{ // Create a struct to store first name, last name, id, pay and status of each employee
    string first_name;
    string last_name;
    int id;
    int salary;
    string status;
};

struct linked_list_item
{
    linked_list_item* next;
    employee* value;
};

#endif //PAYROLL_OBJECTS_H
