#include <iostream>
using namespace std;

class myClass {
public:	
	typedef int * intptr;
	intptr p;
};

int main()
{
	int x = 10;
	myClass::intptr p2;
	myClass m1;
	m1.p = &x;
	p2 = &x;
	cout << *m1.p << " " << *p2 << endl;
}