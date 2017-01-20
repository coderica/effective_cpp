#include <iostream>
#include <string>
using namespace std;

class Parent
{
private:
	int parent_data;
	string name;
public:
	Parent(string s="", int data = 0);
	void display() const;
};


class Child : public Parent
{
public:
	Child(string s="",int data=0);
};

Parent::Parent(string s, int data) :parent_data(data),name(s)
{
	cout << "In the parent constructor for " << name << endl;
}

void Parent::display() const
{
	cout << "Parent data: " << parent_data << endl;
}

Child::Child(string s, int data) :Parent(s,data)
{
	cout << "In the child constructor" << endl;
}

int main()
{
	Parent p1("p1");
	p1.display();
	Child c1="c1";
	c1.display();
}