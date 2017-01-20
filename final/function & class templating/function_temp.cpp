#include <iostream>
#include <string>
using namespace std;


template <typename T>
void swapIt(T& first, T& second)
{
	T temp = first;
	first = second;
	second = temp;
}

int main()
{
	int n1 = 2, n2 = 3;
	cout << "Before: " << n1 << " " << n2 << endl;
	swapIt(n1, n2);
	cout << "After: " << n1 << " " << n2 << endl<< endl;

	string s1 = "first", s2 = "second";
	cout << "Before: " << s1 << " " << s2 << endl;
	swapIt(s1, s2);
	cout << "After: " << s1 << " " << s2 << endl<< endl;

	int *pn1 = &n1, *pn2 = &n2;
	cout << "Before: " << *pn1 << " " << *pn2<< endl;
	swapIt(pn1, pn2);
	cout << "After: " << *pn1 << " " << *pn2 << endl<< endl;


}