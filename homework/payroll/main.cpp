// Rubric:
//      Compiles and runs with no run time errors - 30 points
//      Runs correctly and meets the spec – 50 points
//      Quality of code – 20 points

#include <iostream>
#include <fstream>
#include <sstream>
#include "objects.h"
#include "utilities.h"

int main()
{
    linked_list_item* head = create_employees("employees.txt"); // Store employees as a linked list

    sort_by_name(head);
        testing(head, "Sorted employees by name: ");
    create_employees("new_employees.txt", true); // Read the file new_employees.txt and add to the list
        testing(head, "Added new employees: ");
    deactivate_employees(head); // set the status of employees to be inactive
        testing(head, "Deactivated employees: ");
    employee_raise(head);// Give all "active" employees a 7% raise
        testing(head, "Raised salaries of active employees: ");
    sort_by_id(head); // Sort employees by id number
        testing(head, "Sorted employees by id: ");

    update_file("employees.txt", head); // Write the list back to the file sorted in order by id number

    garbage_collection(head);

    return 0;
}