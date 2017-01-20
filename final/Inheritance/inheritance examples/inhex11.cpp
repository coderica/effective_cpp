#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class MyAbstractBaseClass
{
protected:
	int someData;
public:
	MyAbstractBaseClass():someData(0) {}
	virtual void display() const = 0;
};

class Parent:public MyAbstractBaseClass
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

class Child3 : public MyAbstractBaseClass
{

};



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

int Parent::id;

int main()
{
	Parent::setID(101);
	Parent p1;
	p1.display();
//	p1.someChildFunc();
	Child c1 = 10;
	c1.display();
	c1.someChildFunc();

	Parent *pptr;
	pptr = &p1;
	pptr->display();
	pptr->someNewCoolThing();
//	pptr->someChildFunc();

	pptr = &c1;
	pptr->display();
	pptr->someNewCoolThing();
//	pptr->someChildFunc();

	
	//conversions
	p1 = c1;
	p1.display();

//	c1 = p1;
//	c1.display();

//	Child3 c3;
}