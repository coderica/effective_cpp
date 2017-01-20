#include <iostream>
using namespace std;

enum genderType { male, female };

struct user
{
	string name;
	genderType gender;
	int age;
};


int main()
{
	user user1;
	user *p = &user1;
	p->name = "jim";
	return 1;
}