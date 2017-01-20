#include <iostream> 
#include <vector> 
#include <string>
using namespace std;

void main()
{
	vector<string> people = { "alice", "barbara", "cleo", "darlene", "edna" };
	try {
		for (auto i = 0; i < people.size(); i++)
			cout << people[i] << " ";
		cout << endl;

		for (auto i = 0; i < people.size(); i++)
			cout << people.at(i) << " ";
		cout << endl;

		for (auto it = people.begin(); it != people.end()+1; it++)
			cout << *it << " ";
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Exception: " << e.what() << endl;
	}

}  //end main
