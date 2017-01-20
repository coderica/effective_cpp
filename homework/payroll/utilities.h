#pragma once

#ifndef PAYROLL_UTILITIES_H
#define PAYROLL_UTILITIES_H

using namespace std;

string trim(string);
linked_list_item* create_employees(string, bool=false);
void sort_by_name(linked_list_item*);
void sort_by_id(linked_list_item*);
void deactivate_employees(linked_list_item*);
void employee_raise(linked_list_item*);
void update_file(string, linked_list_item*);
void testing(linked_list_item*, string);
void garbage_collection(linked_list_item*);

#endif //PAYROLL_UTILITIES_H
