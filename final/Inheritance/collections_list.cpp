#include <iostream>
#include <string>
using namespace std;

#include "collections_inh.h"
#include "collections_ptr.h"


BasketInh * BasketInh::next()
{
	return nextOne;
}

void ListInh::append(BasketInh *basket)
{
	if (!basket) return;
	if (!head)		//case:  list is empty
		head = tail = basket;
	else			//case:  list is empty
		tail->nextOne = basket;
	tail = basket;
}

void ListInh::display()
{
	BasketInh *b = head;
	while (b)
	{
		b->display(); cout << endl;
		b = b->next();
	}
}


BasketPtr * BasketPtr::next()
{
	return nextOne;
}

BasketPtr::~BasketPtr()
{
	if (cargo) delete cargo;
	cargo = nullptr;
	nextOne = nullptr;
}

void *BasketPtr::getCargo()
{
	return cargo;
}

void ListPtr::append(BasketPtr *basket)
{
	if (!basket) return;
	if (!head)		//case:  list is empty
		head = tail = basket;
	else			//case:  list is empty
		tail->nextOne = basket;
	tail = basket;
}

void DepartmentPtr::display()
{
	BasketPtr *b = head;
	EmployeePtr *e;
	while (b)
	{
		e = static_cast<EmployeePtr *>(b->getCargo());
		e->display(); cout << endl;
		b = b->next();
	}
}

void createDepartmentInh()
{
	EmployeeInh *e;
	DepartmentInh d("Sales");
	e = new EmployeeInh("sam", 101);
	d.append(e);
	d.append(new EmployeeInh("bob", 102));
	d.display();
}

void createDepartmentPtr()
{
	EmployeePtr *e;
	BasketPtr *b;
	DepartmentPtr d("Sales");
	e = new EmployeePtr("sam", 201);
	b = new BasketPtr(e);
	d.append(b);
	d.append(new BasketPtr(new EmployeePtr("bob", 202)));
	d.display();
}


int main()
{
	createDepartmentInh(); 
	cout << "\n--------------------\n\n";
	createDepartmentPtr();

	cout << endl;
	
	return 0;
}

