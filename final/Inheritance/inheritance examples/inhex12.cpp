#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Parent
{

private:
	int parent_data;
protected:
	static int id;
	string name;
public:
	Parent(int data = 0);
	virtual void display() const;
	int getData() const;
	void someNewCoolThing();
	static void setID(int);
	virtual ~Parent();
};


class Child : public Parent
{
private: 
	int child_data;
public:
	Child(int data=0);
	void display() const override;
	void someNewCoolThing();
	void someChildFunc() { }
	~Child();
};

class NoKids final
{
public: 
	int whatever;
};

/*
class Child2 : public NoKids
{

};
*/

Parent::Parent(int data) :parent_data(data)
{
	ostringstream sname;
	sname << "parent-" << id;
	name = sname.str();

	id++;
	cout << "In the parent constructor for " << name  << endl;
}

void Parent::display() const
{
	cout << "Parent data for: " << name << " is " << parent_data << endl;
}

int  Parent::getData() const
{
	return parent_data;
}

void Parent::someNewCoolThing()
{
	cout << "Parent has a new, cool thing!\n";
}

void Parent::setID(int n) { id = n; }

Parent::~Parent()
{
	cout << "In the destructor for the parent for " << name << endl;
}

Child::Child(int data):Parent(data)
{
	cout << "In the child constructor for " << name << endl;
	child_data = getData() * 2;
}

void Child::display() const
{
	Parent::display();
	cout << "child data for: " << name << " is " <<  child_data << endl;
}

void Child::someNewCoolThing()
{
	cout << "Child has a new, cool thing!\n";
}

Child::~Child()
{
	cout << "In the destructor for the child for " << name << endl;
}

int Parent::id;

int main()
{
	Parent::setID(101);
	Parent p1;
	p1.display();
	Child c1 = 10;
	c1.display();
	c1.someChildFunc();

	Parent *pptr;
	pptr = &p1;
	pptr->display();
	pptr->someNewCoolThing();

	pptr = &c1;
	pptr->display();
	pptr->someNewCoolThing();

	cout << endl << endl;

	if (true)
	{
		Child *cptr = new Child (1);
		pptr = cptr;
		delete pptr;
	}
	cout << endl << endl;

}