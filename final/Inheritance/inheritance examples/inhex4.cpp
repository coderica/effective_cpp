#include <iostream>
#include <string>
using namespace std;

class Parent
{
private:
	int parent_data;
protected:
	string name;
public:
	Parent(string s="", int data = 0);
	void display() const;
	int getData() const;
};


class Child : public Parent
{
private: 
	int child_data;
public:
	Child(string s="",int data=0);
	void show() const;
};

Parent::Parent(string s, int data) :parent_data(data),name(s)
{
	cout << "In the parent constructor for " << name << endl;
}

void Parent::display() const
{
	cout << "Parent data: " << parent_data << endl;
}

int  Parent::getData() const
{
	return parent_data;
}

Child::Child(string s, int data) :Parent(s,data)
{
	cout << "In the child constructor for " << name << endl;
	child_data = getData() * 2;
}

void Child::show() const
{
	cout << "child data is: " << child_data << " and parent data is: " << getData() << endl;
}

int main()
{
	Parent p1 = "p1";
	p1.display();
	Child c1("c1", 10);
	c1.show();
}