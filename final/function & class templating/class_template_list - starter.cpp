#include <iostream>
#include <string>
using namespace std;

/*********** CLASS DEFINITIONS **************/

class List;

class Basket
{
	Basket * nextOne;
	void *cargo;
public:
	Basket(void *stuff = nullptr) :cargo(stuff), nextOne(nullptr) {}
	Basket * next();
	~Basket();
	virtual void * getCargo();
	friend class List;
};

class List
{
public:
	Basket *head;
	Basket *tail;
	List() :head(nullptr), tail(nullptr) {}
	void append(Basket *basket);
	virtual void display() = 0;
};

class Department :public List
{
public:
	string name;
	Department(string theName) :List(), name(theName) {}
	void display() override;
};

/*********** METHOD DEFINITIONS **************/

Basket * Basket::next()
{
	return nextOne;
}

Basket::~Basket()
{
	delete cargo;
}

void *Basket::getCargo()
{
	return cargo;
}

void List::append(Basket *basket)
{
	if (!basket) return;
	if (!head)		//case:  list is empty
		head = tail = basket;
	else			//case:  list is empty
		tail->nextOne = basket;
	tail = basket;
}

void Department::display()
{
	Basket *b = head;
	Employee *e;
	while (b)
	{
		e = static_cast<Employee *>(b->getCargo());
		e->display(); cout << endl;
		b = b->next();
	}
}

class Employee
{
	string name;
	double pay;

public:
	Employee(string _name = "joe", double amount = 0) :name(_name), pay(amount) {}
	void display() { cout << name << ": " << pay << endl; }
};


int main()
{
	//new Employee("sam", 201);
	//new Employee("bob", 202));
	
}