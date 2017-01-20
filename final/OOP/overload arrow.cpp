#include <iostream>
#include <string>
using namespace std;

enum whichName { first, middle, last };

class Name
{
private:
	string firstName;
	string middleName;
	string lastName;
	whichName showName;
public:
	Name(string firstName, string lastName, string middleName=""): 
		firstName(firstName), lastName(lastName), middleName(middleName),showName(first) {}
	string operator-> ();
};

string Name::operator [] () 
{
	switch (showName)
	{
		case first: return firstName; 
		case last: return lastName;
		case middle: return middleName;
		default: return "";
	}
}

int main()
{
	Name sally("sally", "johnson", "ann");
	cout << sally[middle] << endl;
	return 0;
}
