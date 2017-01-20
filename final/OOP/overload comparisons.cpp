#include <iostream>
#include <string>
using namespace std;

enum SortCriteria { first, last };
class Name
{
private:
	string firstName;
	string lastName;
	static SortCriteria sortBy;
public:
	Name(string firstName, string lastName) : firstName(firstName), lastName(lastName) {}
	static void sortByLast() { sortBy = last; }
	static void sortByFirst() { sortBy = first; }
	bool operator == (const Name &) const;
	bool operator < (const Name &) const;
	bool operator > (const Name &) const;
};

bool Name::operator == (const Name &n) const
{
	return this->firstName == n.firstName && this->lastName == n.lastName;
}

bool Name::operator < (const Name &n) const
{
	if (sortBy == first)
		return this->firstName < n.firstName;
	else
		return this->lastName < n.lastName;
}

bool Name::operator > (const Name &n) const
{
	if (sortBy == first)
		return this->firstName > n.firstName;
	else
		return this->lastName > n.lastName;
}

SortCriteria Name::sortBy; 

int main()
{
	Name::sortByLast();
	Name n1("sam", "baker");
	Name n2("john", "doe");
	cout << (n1 < n2) << endl;
	return 0;
}