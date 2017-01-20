#include <iostream>
using namespace std;

class AbsVal {
public:
	int operator() (int n) const
	{
		return n < 0 ? -n : n;
	}

	double operator() (double n) const
	{
		return n < 0 ? -n : n;
	}
};
enum Operation {add, subtract, multiply, divide};
class Calculate
{
private:
	int op1;
	int op2;
public:
	Calculate(int op1, int op2) :op1(op1), op2(op2)	{}
	double operator()(Operation op);
};

double Calculate::operator()(Operation op)
{
	switch (op)
	{
	case add: return op1 + op2;
	case subtract: return op1 + op2;
	case multiply: return op1 + op2;
	case divide: 
		if (op2 != 0) 
			return op1 + op2;
		else 
			throw(std::runtime_error("divide by zero error"));
	}
}
int main()
{
	AbsVal absVal;
	cout << absVal(-10.5) << endl;

	try {
		Calculate c1(10, 4);
		cout << c1(add) << endl;

		Calculate c2(5, 0);
		cout << c2(divide);
	}
	catch (runtime_error err)
	{
		cout << err.what() << endl;
	}

}