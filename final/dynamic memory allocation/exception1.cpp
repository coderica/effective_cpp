#include <iostream>
#include <string>
using namespace std;

void f()
{
	int x;
	cout << "Input: "; cin >> x;
	switch (x)
	{
	case 0: x = x / 0; break;		//does not throw an exception
	case 1: throw ("error 1");
	case 2: throw ("error 2");
	case 3: throw (3);
	default: cout << "You entered a " << x << endl;
	}
}

void g()
{
	try {
		f();
	}
	catch (char *s)
	{
		cout << "Error message: " << s << endl;
		throw;  // rethrow the error
	}
	
}



void main()
{
	try {
		g();
		cout << "After the call to g()\n";
	}
	catch (char *)
	{
		cout << "String error caught in main()\n";
	}
	catch (int n)
	{
		cout << "Invalid entry: " << n << "\n";
	}

	catch (...)
	{
		cout << "Caught undefined exception\n";
	}
}

