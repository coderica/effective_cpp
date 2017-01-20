#include <iostream>
using namespace std;

//this example set illustrates things you MUST NOT do

void getSomeMemory(int *);

int main()
{

	int *p1;
	*p1 = 0;   // NO!  Pointer was not initialized

	int *p2 = nullptr;
	*p2 = 1;   // NO!  Pointer is NULL

	int *p3 = new int;
	p3[1] = 10; // NO!  You only asked for one
	delete p3;

	int *p4 = new int[3];
	p4[3] = 2;	// NO!  Boundary condition error
	delete[] p4;

	int *p5 = new int[3];
	p5[1] = 2;
	delete[] p5;
	p5[1] = 4;	// NO!  Memory has been deallocated

	int *p6 = new int;
	*p6 = 1;
	delete[] p6;

	int *p7, *p8;
	p7 = new int[3];
	p8 = p7;
	delete[] p7;
	p8[1] = 10;	// NO!  Memory has been deallocated

	int x;
	int *p9 = &x;
	*p9 = 10;
	delete p9;	// NO! It's local memory

	int *p10, *p11, y=0;
	p10 = new int;
	p11 = &y;
	*p11 = 100;
	*p10 = 101;
	p10 = p11;
	*p10 = 102;  // NO! No pointer to allocated memory
	delete p10;  // NO! It's local memory

	int *p12= nullptr;
	getSomeMemory(p12); // NO! Pointer to allocated memory went out of scope

}

void getSomeMemory(int *p)
{
	p = new int;
	*p = 12;
}
