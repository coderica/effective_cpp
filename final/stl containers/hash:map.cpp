#include <iostream> 
#include <map>
#include <string>
using namespace std;



void main()
{
	map<string, double> employees = { {"jim", 100}, {"sam", 200} , {"john", 300} };
	employees["john"] *= 1.1;  //increase john's pay by 10%
	employees.insert({ "tim", 400 });
	employees.insert({ "sam", 250 });
	employees["harvey"] = 500;
	employees["sam"] = 275;
	employees.emplace(make_pair("bob", 450));
	employees.erase("sam");

	for (auto it = employees.begin(); it != employees.end(); it++)
		cout << it->first << " " << it->second << endl;

	

	cout << endl;
}  //end main
