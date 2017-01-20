#include <iostream>
#include <string>
using namespace std; 

#include "basket_classes.h"
#include "person_classes.h"

Basket* Stack::pop()
{
	if (tail == nullptr)	//case: empty, throw underflow exception?
		return nullptr;
	else
	{
		Basket *popped = tail;// get the "popped" element
		if (head == tail)	  //adjust the tail
			head = tail = nullptr;
		else
		{
			Basket *b = head;
			while (b->next() != tail)
				b = b->next();
			tail = b;
		}
		return popped;		// return "popped" element
	}
}


Basket* Queue::pop()
{
	if (head == nullptr)	//case: empty, throw underflow exception?
		return nullptr;
	else
	{
		Basket *popped = head;// get the "popped" element
		if (head == tail)	  // popping the last one - included for clarity
			head = tail = nullptr;
		else
			head = head->next();
		
		return popped;		// return "popped" element
	}
}

void Stack_Queue::push(Basket *basket)
{
	if (!basket) return;
	if (!head)		//case:  list is empty
		head = tail = basket;
	else			//case:  list is empty
		setNext(tail, basket);
	tail = basket;
}

void Stack_Queue::display()
{
	Basket *b = head;
	while (b)
	{
		b->display(); cout << endl;
		b = b->next();
	}
}

class Payroll :public Stack
{
public:
	string date;
	Payroll(string theDate) :Stack(), date(theDate) {}
};

int main()
{
	Payroll pay("11/8/2016");
	Employee e1("sam", 101);
	Employee e2("bob", 102);
	Employee e3("barb", 103);
	pay.push(&e1);
	pay.push(&e2);
	pay.push(&e3);
	
	cout << "Employees on payroll: \n";
	pay.display();  cout << endl;

	cout << "Payroll for " << pay.date << endl;
	while (! pay.empty())
	{
		cout << "Paying: ";
		
		pay.pop()->display();
		cout << endl;
	}


	return 0;
}

