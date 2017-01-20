#include <iostream>
using namespace std;

class MyClass {
private:
	int data;
public:
	MyClass():data(10) { }
	void show() { cout << x << endl; }
//	friend class AnotherClass;
//	friend void friendFunction(MyClass &m);
};

class AnotherClass {
private:
	MyClass m1;
public:
	AnotherClass() { m1.data = 20; }	// allowed because its a friend
	void show() { cout << m1.data << endl; }
};

void friendFunction(MyClass &m)
{
	m.data = m.data * 2;  // allowed because its a friend
}

int main()
{
	MyClass m1;
	//m1.data = m1.data * 2;  // illegal - private
	m1.show();
	
	friendFunction(m1);
	m1.show();
	
	AnotherClass a1;
	a1.show();
	return 0;
}

