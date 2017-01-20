#include <iostream>
#include <fstream>
#include <sstream>

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

string trim(string str)
{
    size_t endpos = str.find_last_not_of(" \t\f\v\n\r");
    return (string::npos != endpos) ? str.substr(0, endpos+1) : str;
}

linked_list_item* create_employees(string filename, bool new_employee=false)
{
    ifstream inFile;
    inFile.open(filename); //open for reading;
    if (inFile.fail()) cout << "Unable to open files";

    string line;
    getline(inFile, line);

    static linked_list_item* head = nullptr;
    static linked_list_item* tail = nullptr;

    while (getline(inFile, line)) {
        employee* e = new employee();
        istringstream ss(line);
        string token;

        getline(ss, e->first_name, ',');
        getline(ss, e->last_name, ',');
        getline(ss, token, ',');
        e->id = stoi(token);
        getline(ss, token, ',');
        e->salary = stoi(token);
        getline(ss, e->status, ',');

        e->first_name = trim(e->first_name);
        e->last_name = trim(e->last_name);
        e->status = trim(e->status);

        linked_list_item* employee_item = new linked_list_item();
        employee_item->value = e;

        if (head == nullptr) head = employee_item;

        if(new_employee) {
            bool inserted = false;
            linked_list_item *current = head;
            linked_list_item *previous = head;
            do {
                if (employee_item->value->last_name > current->value->last_name) {
                    previous = current;
                    current = current->next;
                } else {
                    employee_item->next = current;
                    previous->next = employee_item;
                    inserted = true;
                }
            } while(!inserted);
            e->status = "active";
        } else {
            if (tail != nullptr) tail->next = employee_item;
            tail = employee_item;
        }
    }
    inFile.close();
    return head;
}

void sort_by_name(linked_list_item* head)
{ // Sort employees sorted by last name
    linked_list_item* current;
    bool swapped; //watch for swaps

    do {
        swapped = false;
        current = head;
        while (current->next) {
            if (current->value->last_name > current->next->value->last_name) {
                employee * swap = current->value;
                current->value = current->next->value;
                current->next->value = swap;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void sort_by_id(linked_list_item* head)
{ // Sort employees sorted by id
    linked_list_item* current;
    bool swapped; //watch for swaps

    do {
        swapped = false;
        current = head;
        while (current->next) {
            if (current->value->id > current->next->value->id) {
                employee * swap = current->value;
                current->value = current->next->value;
                current->next->value = swap;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void deactivate_employees(linked_list_item* head)
{
    ifstream inFile;
    inFile.open("deactivate_employees.txt"); //open for reading;
    if (inFile.fail()) cout << "Unable to open files";

    string line;
    getline(inFile, line);
    int id;

    while (getline(inFile, line)) {
        linked_list_item* current = head;
        id = stoi(trim(line));
        while (current->next) {
            if (current->value->id == id) {
                current->value->status = "inactive";
                break;
            }
            current = current->next;
        }
    }
}

void employee_raise(linked_list_item* head)
{
    linked_list_item* current = head;

    while (current->next) {
        if (current->value->status == "active") {
            current->value->salary += current->value->salary*.07;
        }
        current = current->next;
    }
}

void update_file(string filename, linked_list_item* head)
{
    ofstream outFile(filename);
    linked_list_item* current = head;

    outFile << "first,last,id,pay,status\r";

    while (current) {
        string str;
        string comma = ",";
        str.append(current->value->first_name);
        str.append(comma);
        str.append(current->value->last_name);
        str.append(comma);
        str.append(to_string(current->value->id));
        str.append(comma);
        str.append(to_string(current->value->salary));
        str.append(comma);
        str.append(current->value->status);
        str.append("\r");

        outFile << str;
        current = current->next;
    }
    outFile.close();
}

void testing(linked_list_item* head, string label)
{
    cout << label << endl;
    linked_list_item* current = head;
    while (current->next) {
        cout << current->value->first_name << ' '
             << current->value->last_name << ": "
             << current->value->status << " - "
             << current->value->salary << endl;
        current = current->next;
    }
    cout << endl << endl;
}

void garbage_collection(linked_list_item* head)
{
    linked_list_item* current = head;
    do { // de-allocation
        linked_list_item* previous = current;
        current = current->next;
        delete previous->value;
        delete previous;
    } while (current->next);
}