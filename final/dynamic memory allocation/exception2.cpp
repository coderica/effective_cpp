#include <iostream>
#include <string>
using namespace std;

struct ball {};
struct fish {};

void func1(bool);
void func2();
void func3();

int main()
{
	try {
		func1(false);
		func2();
	}
	catch (ball) { cout << "Exception: ball\n"; }
	catch (fish) { cout << "Exception: fish\n"; }
	return 0;
}

void func1(bool hasException)
{ 
	if (hasException)
		throw ball(); 
}

void func2() 
{ 
	throw fish(); 
}

void func3() 
{ 
	throw ("Something is wrong here"); 
}