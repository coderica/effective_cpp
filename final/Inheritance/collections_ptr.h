#pragma once

class ListPtr;

class BasketPtr
{
	BasketPtr * nextOne;
	void *cargo;
public:
	BasketPtr(void *stuff = nullptr) :cargo(stuff), nextOne(nullptr) {}
	BasketPtr * next();
	~BasketPtr();
	virtual void * getCargo();
	friend class ListPtr;
};

class PersonPtr 
{
public:
	string name;
	PersonPtr(string n = "") { name = n; }
	virtual void display() { cout << name; }
};

class EmployeePtr : public PersonPtr
{
public:
	int id;
	EmployeePtr(string empName, int empId) :PersonPtr(empName), id(empId) {}
	void display() override { cout << name << ":" << id; }
};

class ListPtr
{
public:
	BasketPtr *head;
	BasketPtr *tail;
	ListPtr() :head(nullptr), tail(nullptr) {}
	void append(BasketPtr *basket);
	virtual void display()=0;
};

class DepartmentPtr :public ListPtr
{
public:
	string name;
	DepartmentPtr(string theName) :ListPtr(), name(theName) {}
	void display() override;
};
