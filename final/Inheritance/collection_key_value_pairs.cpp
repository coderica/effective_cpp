#include <iostream>
#include <string>
#include <vector>
using namespace std; 

#include "basket_pair.h"

string PairList::getValue(string key)
{
	KeyValuePair *kv;
	for (int i = 0; i < this->size(); i++)
	{
		kv = &this->at(i);
		if (kv->getKey() == key)
			return kv -> getValue();
	}
	return "";
}

void PairList::display()
{
	KeyValuePair *kv;
	for (int i = 0; i < this->size(); i++)
	{
		kv = &this->at(i);
		kv->display();  cout << endl;
	}
}

Employee::Employee(Person *p, int empId):KeyValuePair()
{
	char number[20];
	_itoa_s(empId, number, 10);
	key = number;
	value = p;
}

class Payroll :public PairList
{
public:
	string date;
	Payroll(string theDate) :PairList(), date(theDate) {}
};

int main()
{
	Payroll pay("11/8/2016");
	Person p1("sam"), p2("bob"), p3("barb");
	Employee e1(&p1, 101);
	Employee e2(&p2, 102);
	Employee e3(&p3, 103);
	pay.push_back(e1);
	pay.push_back(e2);
	pay.push_back(e3);	
	cout << "Employees on payroll: \n";
	pay.display();  cout << endl;

	cout << "Employee 101: " << pay.getValue("101") << endl << endl;

	return 0;
}

