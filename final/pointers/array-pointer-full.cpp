#include <iostream>
using namespace std;

void displayArray(const int*, int);
void times2(int*, int);
void pointersAndConstants();
void characterArray();

void main()
{
/*	int array1[] = { 1,3,5,7,9,11 };
	int size = sizeof(array1) / sizeof(int);
	cout << "Size of the array is: " << size << endl;

	for (int i = 0; i < size; i++)
		cout << array1[i] << " ";
	cout << endl;

	int *pi = array1;
	for (int i = 0; i < size; i++)
		cout << *pi++ << " ";
	cout << endl;

//	for (int i = 0; i < size; i++)
//		cout << *array1++ << " ";  //error - array name is a pointer constant
	
	displayArray(array1, 6);

	times2(array1, 6);

	displayArray(array1, 6);

	pointersAndConstants();
*/
	characterArray();

}

void displayArray(const int *array, int size)
{
//	size = sizeof(array) / sizeof(int);  //what happens if size if defined this way?
//	cout << "Size of the array is: " << size << endl;

	for (int i = 0; i < size; i++)
		cout << *array++ << " ";

	cout << endl;
}

void times2( int *array, int size)
{
	for (int i = 0; i < size; i++)
		*array++ *= 2;
}

void changeSomething(const int *array)
{
	//array[0] = 2;		//error array points to a const
}


void pointersAndConstants()
{
	int x = 42;
	int *ptr = &x;		//ptr points to x
	cout << *ptr << endl;
	*ptr = 10;			//update x using the pointer

	const int ci = 42;
	const int *ptr2 = &ci;  //ptr points to ci
	cout << *ptr2 << endl;
//	*ptr2 = 10;			// error can't change a constant
//	ptr = &ci;			// error can't point to a constant with a non-const pointer
//	*ptr = 10;

	int array[] = { 1,2,3 };
	int * const ptr3 = array;
	*ptr3 = 10;
//	ptr3++;				//error - pointer can't point elsewhere - its a constant

	const int array2[] = { 1,2,3 };	// create array of constants
//	array2[1] = 10;					//error - array of constants
//	int * ptr4 = array2;			//error - regular pointer can't point to constants
//	int * const ptr5 = array2;		//error - ptr5 is constant pointer (not pointer to const)
	const int * ptr6 = array2;		// WORKS!
	displayArray(ptr6, 3);
}

void characterArray()
{
	char hamlet1[] = "To be or not to be";
	// display one char at a time
	for (char *pc = hamlet1; *pc; pc++)
		cout << *pc;
	cout << endl;

	// reverse a string
	char temp;
	for (char *pbegin = hamlet1, *pend = &hamlet1[strlen(hamlet1) - 1]; pbegin < pend; pbegin++, pend--)
	{
		temp = *pbegin;
		*pbegin = *pend;
		*pend = temp;
	}

	cout << hamlet1 << endl;

}