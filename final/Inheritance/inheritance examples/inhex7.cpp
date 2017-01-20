#include <iostream>
using namespace std;

class First {
public:				// full access to
	int data1;		// all members
	First(int d):data1(d) {};
};

// all parent members are limited to private access to 
// instances or children of “Second”
class Second : protected First
{
	int data2;		// this is private
public:
	Second(int d1, int d2);
};

Second::Second(int d1, int d2) : First(d1)
{
	data2 = d2;
	data1 = 6;		// ok, b/c access in the parent class is public
}

/*
class Third: public Second
{
public:
	Third::Third()
	{
		data1 = 101;
		data2 = 102;
	}
};
*/

int main()
{
	First f(1);
	Second s(1, 2);
	f.data1 = 2;  // ok, data1 is public
//	s.data1 = 2;  // no! private derivation

	

}