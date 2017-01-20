#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i;
	char *names[5] = { "Tom", "Dick", "Harry", "Paula", "Ed" };
	double numbers[5] = { 1, 1.2, 1.23, 12.34, 123.45 };

	/******  Using I/O Functions ******/

	cout << "******  Using I/O Functions ******\n";
	for (i = 0; i<5; i++)
	{
		cout.width(6); cout.fill('-');
		cout << names[i] << '\n';
	}
	for (i = 0; i<5; i++)
	{
		cout.width(8); cout.fill('*'); cout.precision(2);
		cout << numbers[i] << '\n';
	}
	cout << endl << endl;

	/******  Using I/O Manipulators ******/

	cout << "******  Using I/O Manipulators ******\n";
	for (int i = 0; i<5; i++)
	{
		cout << setw(6) << setfill('-')
			<< names[i] << '\t'
			<< setw(8) << setfill('*') << setprecision(2)
			<< numbers[i] << '\n';
	}
	cout << endl << endl;

	/******  Using IOS Flags ******/

	cout << "******  Using IOS Flags ******\n";
	for (int i = 0; i<5; i++)
	{
		cout << setw(6) << setfill('-')
			<< resetiosflags(ios::left)
			<< setiosflags(ios::right)
			<< names[i] << '\t'
			<< setw(8)
			<< setprecision(2) // notice precision has a 
							   // different meaning when 
							   // combined with ios::fixed
			<< setfill(' ')
			<< resetiosflags(ios::right)
			<< setiosflags(ios::left)
			<< setiosflags(ios::fixed)
			<< numbers[i] << '\n';
	}

	return 0;

}
