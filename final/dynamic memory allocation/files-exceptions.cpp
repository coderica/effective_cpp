#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	cout << "Enter a line: ";
	char s[80];
	cin.getline(s, 80);
	ofstream f1;
	f1.exceptions(ios::failbit || ios::badbit);
	try {
		f1.open("text.out", ios::app);
	}
	catch (fstream::failure)
	{
		cout << "Can't open file\n";
		exit(-1);
	}
	try {
		f1 << s << endl;
		f1.close();
	}
	catch (fstream::failure)
	{
		cout << "File write error \n";
		exit(-1);
	}
	ifstream f2;
	f2.exceptions(ios::failbit || ios::badbit);
	try {
		f2.open("text.out");
		string str;
		while (true)
		{
			getline(f2, str);
			cout << str << endl;
		}
	}
	catch (ios::failure)
	{
		if (f2.eof())
		{
			cout << "\nEOF\n";
			f2.close();
		}
		else
		{
			cout << "File error\n";
			exit(-1);
		}
	}
}
