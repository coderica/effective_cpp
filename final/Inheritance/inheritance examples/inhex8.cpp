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
	Parent();
public:
	Parent(int data);
	void display() const;
	int getData() const;
	void someNewCoolThing();
	void setData(int);
	string getPrefix() const { return "parent-"; }
	static void setID(int);
	void setName();
};


class Child : public Parent
{
private: 
	int child_data;
public:
	Child(int data=0);
	void display() const;
	string getPrefix() const { return "child-"; }
	void setName();
};

Parent::Parent()
{
	parent_data = 0;
}

Parent::Parent(int data) :parent_data(data)
{
	setName();
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
void  Parent::setData(int data) 
{
	parent_data = data;
}
void Parent::someNewCoolThing()
{
	cout << "Parent has a new, cool thing!\n";
}

void Parent::setID(int n) { id = n; }

void Parent::setName()
{
	ostringstream sname;
	sname << getPrefix() << id++;
	name = sname.str();
}

Child::Child(int data):Parent()
{
	setName();
	setData(data);
	cout << "In the child constructor for " << name << endl;
	child_data = getData() * 2;
}

void Child::setName()
{
	ostringstream sname;
	sname << getPrefix() << id++;
	name = sname.str();
}

void Child::display() const
{
	Parent::display();
	cout << "child data for: " << name << " is " <<  child_data << endl;
}

int Parent::id;

int main()
{
	Parent::setID(101);
	Parent p1=5;
	p1.display();
	Child c1 = 10;
	c1.display();

}