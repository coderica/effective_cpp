#include <iostream>
using namespace std;

//safe array access

const int SIZE=5;
int &contentAt(int *a, int index);

int main()
{
	int i;
	try {
	  int *arr = new int[SIZE];
	  for (i=0; i< SIZE; i++)		// loop counter is intentionally
									// allowed to overflow.
	      contentAt(arr, i) = i;
	  for (i = 0; i < SIZE; i++)
		  cout << contentAt(arr, i) << ' ';
	  cout << endl;
	}
	catch (bad_alloc)
	{
		cout << "Memory allocation failure\n";
		exit(-1);
	}
	catch(int x)
	{
		cerr << "Index too large: " << x << endl;
	}

	return 0;
}

int &contentAt(int *a, int index)
{
	if (index >= SIZE)
		throw  index;
	return a[index];
}
