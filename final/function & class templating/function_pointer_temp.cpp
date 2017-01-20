#include <iostream>
#include <string>
using namespace std;

template <typename T, unsigned size>
void foreach(T (&collection)[size], void (*f)(T& t))
{
	for (int i = 0; i < size; i++)
	{
		f(collection[i]);
	}
}

class Employee
{

	string name;
	double pay;

public:	
	Employee(string _name = "joe",  double amount=0) :name(_name), pay(amount) {}
	void increasePay(double pct) { pay = pay * (1 + pct / 100.0); }
	friend void showEmployees(Employee *array, int size);
};

void doubleIt(int & n)
{
	n = n * 2;
}

void payRaise(Employee &e)
{
	e.increasePay(10);  //everyone gets a 10% raise
}

void showNumbers(int *array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

void showEmployees(Employee *array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i].name << ": " << array[i].pay << endl;
}

int main()
{

	int numbers[] = { 3,7,33,5,123,67,8,43 };
	Employee department[] = { Employee("Bob", 100), Employee("Carl", 200), Employee("Daniel",300) };


	showNumbers(numbers, 8);
	foreach(numbers, doubleIt);
	showNumbers(numbers, 8);
	cout << endl;

	showEmployees(department,3);
	foreach(department, payRaise);
	showEmployees(department, 3);

}