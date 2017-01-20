#pragma once

class ListInh;
class BasketInh
{
	BasketInh * nextOne;
public:
	BasketInh() :nextOne(nullptr) {}
	virtual BasketInh * next();
	virtual void display()=0;
	virtual ~BasketInh() {};
	friend class ListInh;
};

class PersonInh : public BasketInh
{
public:
	string name;
	PersonInh(string n = "") :BasketInh() { name = n; }
	void display() override { cout << name; }
};

class EmployeeInh : public PersonInh
{
public:
	int id;
	EmployeeInh(string empName, int empId) :PersonInh(empName), id(empId) {}
	void display() override { cout << name << ":" << id; }
};

class ListInh
{
public:
	BasketInh *head;
	BasketInh *tail;
	ListInh() :head(nullptr), tail(nullptr) {}
	void append(BasketInh *basket);
	void display();
};

class DepartmentInh :public ListInh
{
public:
	string name;
	DepartmentInh(string theName) :ListInh(),name(theName) {}
};
