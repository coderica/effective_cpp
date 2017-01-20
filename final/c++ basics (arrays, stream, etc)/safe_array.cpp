#include <iostream>
using namespace std;

const int SIZE = 5;

int& safeArrayAssign(int *array, int index, int size, bool &err)
{
	if (index >= size)
	{
		index = size - 1;
		err = true;
	}
	return array[index];
}

int main()
{
	bool err = false;
	int myArray[5] = { 1,2,3,4,5 };
	safeArrayAssign(myArray, 2, SIZE, err) = 10;	//myArray[2] = 10
	safeArrayAssign(myArray, 7, SIZE, err) = 11;	//last element gets 11
	for (int i = 0; i < SIZE; i++) cout << myArray[i] << " "; //1 2 10 4 11
	cout << endl;
	return 0;
}