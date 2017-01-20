#include <iostream>
using namespace std;

class Parent
{
private:
	int parent_data;
public:
	Parent(int data = 0);
	void display() const;
};


class Child : public Parent
{
	Child() {}
};

Parent::Parent(int data) :parent_data(data)
{
	cout << "In the constructor for the parent\n";
}

void Parent::display() const
{
	cout << "Parent data: " << parent_data << endl;
}

int main()
{
	Parent pobj;
	pobj.display();
}