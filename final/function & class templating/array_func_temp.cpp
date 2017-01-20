#include <iostream>
#include <string>
using namespace std;


template <typename T, unsigned size>
int frequency(T findIt, T (&collection)[size])
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (collection[i] == findIt)
			count++;
	}
	return count;
}

class Person
{

	string name;
public:	
	Person(string _name = "joe") :name(_name) {}
	bool operator == (Person & p2) { return name == p2.name; }
};

int main()
{

	int numbers[] = { 3,7,33,5,3,123,3,67,8,3,43 };
	string cars[] = { "toyota", "honda", "subaru", "mercedes", "volvo", "hundai", "chevrolet" };
	Person group[] = { "Bob", "Carl", "Daniel", "Ethan", "Frank", "George" };

	int n;
	n = frequency(3, numbers);
	cout << "3 was found " << n << " times\n\n";

	n = frequency(string("honda"), cars);
	cout << "honda was found " << n << " times\n\n";

	n = frequency(string("bmw"), cars);
	cout << "bmw was found " << n << " times\n\n";

	n = frequency(Person("Carl"), group);
	cout << "Carl was found " << n << " times\n\n";

}