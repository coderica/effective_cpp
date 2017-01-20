#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "the quick brown fox jumps over the lazy dog", sresult;
	sresult = s1.substr(5, 10);
	cout << sresult << endl;
/*	sresult = s1.append(" - more stuff here");
	cout << sresult << endl;
	sresult = s1.erase(3, 6);
	cout << sresult << endl;
	auto pos = sresult.find("lazy");
	sresult = s1.replace(pos, 4, "industrious");
	cout << sresult << endl;
	sresult = s1.assign("new string!");
	cout << sresult << endl; 
	cout << s1 << endl; 
	s1 = "to be or not to be, that is the question";
	cout << s1 << endl; 
	pos = s1.find_first_of("aeiou");
	cout << s1.at(pos) << endl;
	s1 = "135";
	int n = stoi(s1);
	cout << n << endl;
	sresult = to_string(n);
	cout << sresult << endl;
*/
}