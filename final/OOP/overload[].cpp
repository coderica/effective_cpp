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
public:
	Name(string firstName, string lastName, string middleName=""): 
		firstName(firstName), lastName(lastName), middleName(middleName) {}
	string operator[] (whichName namePos);
};

string Name::operator [] (whichName namePos) 
{
	switch (namePos)
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
