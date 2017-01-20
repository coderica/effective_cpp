#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct person {
	char name[10];
	int id;
};


void main()
{
	person pete = { "Pete",101 };
	ofstream ofile("file.dat");
	ofile.write((char *)&pete, sizeof(person));
	ofile.close();
	ifstream ifile("file.dat");
	ifile.read((char *)&pete, sizeof(person));
	ifile.close();
	cout << pete.name << endl;
	cout << pete.id << endl;
}
