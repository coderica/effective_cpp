#include <iostream>
using namespace std;

class myClass {
	static int n;
	int x;
public:
	myClass() { x = 0; n++; }
	int getn() { return n; };
	static void setn(int p) { n = p; }
	int getx() { return x; }
	void setx(int p) { x = p; }
};

int myClass::n = 101;

int main()
{
	myClass::setn(12);
	
	myClass m1;
	myClass m2;
	
	cout << m1.getn() << "  " << m2.getn() << "  "
		<< m1.getx() << "  " << m2.getx() << endl;

	m1.setn(10);
	m1.setx(100);

	cout << m1.getn() << "  " << m2.getn()  << "  "
		 << m1.getx() << "  " << m2.getx()<< endl;
	return 0;
}