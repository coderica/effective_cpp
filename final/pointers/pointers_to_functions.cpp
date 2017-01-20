#include <iostream>
using namespace std;

int addThem(int, int);
int subtractThem(int, int);

int main()
{
	int addResult, subResult;
	int (*opPtr)(int, int);
	opPtr = addThem;
	addResult = opPtr(3, 2);
	opPtr = subtractThem;
	subResult = opPtr(3, 2);
	cout << "Adding: " << addResult << " Subtracting: " << subResult << endl;
}

int addThem(int a, int b)
{
	return a + b;
}

int subtractThem(int a, int b)
{
	return a - b;
}

