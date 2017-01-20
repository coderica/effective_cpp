#include <iostream>
using namespace std;

void doubleIt(int *);
void advancePointer(int **p);

int main()
{
	int n=2;
	cout << "before: " << n << endl;
	doubleIt(&n);
	cout << "after: " << n << endl;

	int array[] = { 1,2,3,4,5 }, size = 5;
	int *p = array;
	
	for (int i = 0; i < size; i++)
	{
		cout << *p << endl;
		advancePointer(&p);
	}


	return 0;
}

void doubleIt(int *x)
{
	*x *= 2;
}

void advancePointer(int **p)
{
	(*p)++;
}