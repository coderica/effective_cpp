#include <iostream>
using namespace std;

class Fraction {
private:
	int num;
	int den;
public:	
	Fraction(int n=0, int d=1) : num(n), den(d) {}
};

int main()
{
	Fraction f1(1, 2);
	Fraction f2(3, 4);
	Fraction f3;
	double d = f1 + f2;
	if (f1 > f2) cout << "the first one is bigger\n";
	f3 = f1;
	cout << f3 << endl;
	return 0;
}
