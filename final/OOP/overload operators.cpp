#include <iostream>
#include <string>
using namespace std;

enum colors {red, green,blue,black};
const string strColors[] = {"red", "green","blue","black"};

class MyClass {
private:
	int data;
public:
	MyClass():data(10) { }
	void show() { cout << data << endl; }
	friend ostream & operator << (ostream & out, const MyClass &m);
	friend void operator += (MyClass &m, int n);
};

ostream & operator << (ostream & out, const MyClass &m)
{
	out << m.data;
	return out;
}

void operator += (MyClass &m, int n)
{
	m.data = m.data + n;
}

ostream & operator << (ostream & out, int *n)
{
	*n = -*n;
	out << *n;
	return out;
}

istream & operator >> (istream & in, colors &c)
{
	int input;
	cout << "Enter a color: 1-red, 2-green, 3-blue: ";
	in >> input;
	switch (input) 	{
	case 1:  c = red; break;
	case 2:  c = green; break;
	case 3:  c = blue; break;
	default: c = black;
	}
	return in;
}


int main()
{
	MyClass m1;
	m1.show();
	m1 += 17;
	cout << m1 << endl;
	int n = 1, *ptr;
	ptr = &n;
	cout << ptr << endl;
	colors myColor = black;
	cin >> myColor;
	cout << "The color value is: " << strColors[myColor] << endl;
}

