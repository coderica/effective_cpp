#include <iostream> 
#include <vector> 
#include <set>
#include <string>
using namespace std;


void main()
{
	vector<string> v1 = { "bob", "carol", "ted", "alice", "bob" };
	for (auto i = v1.begin(); i != v1.end(); i++)
		cout << *i << " - ";
	
	cout << endl;

	set<string> s1 = { "bob", "carol", "ted", "alice", "bob" };
	s1.insert("jill");
	for (auto i = s1.begin(); i != s1.end(); i++)
		cout << *i << " - ";

	cout << endl;
}  //end main
