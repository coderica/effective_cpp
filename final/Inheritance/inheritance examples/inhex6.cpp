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
	void display() const;
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
	void show() const;
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
	cout << "Parent data: " << parent_data << endl;
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

void Child::show() const
{
	cout << "child data is: " << child_data << " and parent data is: " << getData() << endl;
}

int Parent::id;

int main()
{
	Parent::setID(101);
	Parent p1;
	p1.display();
	Child c1 = 10;
	c1.show();
	c1.someNewCoolThing();
	
}