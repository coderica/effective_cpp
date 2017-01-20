#include <iostream>
using namespace std;

class Number
{
	int *data;
	int instNumber;
public:
	static int lastInstNumber;
	Number(int);
	Number();
	~Number();
	void set (int);
	bool isDefined();
   	void show();
};

int Number::lastInstNumber = 0;

Number::Number(int n):data(nullptr)
{
	instNumber = ++lastInstNumber;
	cout << "In the int parameter constructor for Instance #" << instNumber << endl;
	set(n);
}

Number::Number():data(nullptr) 
{
	instNumber = ++lastInstNumber;
	cout << "In the default constructor for Instance #" << instNumber << endl;
}

Number::~Number()
{
	if (!isDefined())			//don't delete if is not allocated
		delete data;
	cout << "In the destructor for Instance #" << instNumber << endl;
}

bool Number::isDefined()
{
	return data != nullptr;
}

void Number::set (int n)
{
	try {
		if (!isDefined())
			data = new int;
		*data = n;
	}
	catch (bad_alloc)
	{
		cout << "Allocation error\n"; exit(-1);
	}
}

void Number::show()
{
	cout << "Value is: " << *data << endl;
}


int main()
{
	
	Number n1(2);
	if (true)
	{
		Number n2;
	}
	Number n3;
}




