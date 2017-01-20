#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

void  addLotsOfStuff(initializer_list<int> args);
int main()
{
	addLotsOfStuff({ 1, 2, 3, 4, 5, 6 });
}

void addLotsOfStuff(initializer_list<int> args)
{
	int sum = 0;
	vector<int> argsv = args;
	for (int i=0; i < argsv.size(); i++)
		sum += argsv[i];
	cout << "The sum is " << sum << endl;
}


