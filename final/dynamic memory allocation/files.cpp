#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	cout << "Enter a line: ";
	char s[80];
	cin.getline(s, 80);
	ofstream f("text.out", ios::app);
	if (f.fail())
	{ 
		cout << "Can't open file\n";  
		exit(-1); 
	}
	f << s << endl;
	f.close();
	ifstream f2;
	f2.open("text.out");
	if (f2.fail())
	{ 
		cout << "Can't open file\n";  
		exit(-1); 
	}
	string str;
	while (!f2.eof())
	{
		getline(f2, str);
		cout << str << endl;
	}
	f2.close();
}
