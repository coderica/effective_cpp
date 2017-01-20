#include <iostream>
#include <string>
using namespace std;

#include "wk3-user.h"
#include "wk3-utilities.h"


void displayUser(const user &user1)
{
	cout << "Name: " << user1.name << endl;
	cout << "Gender: " << (user1.gender == male ? "male" : "female") << endl;
	cout << "Age: " << user1.age << endl;
	if (user1.hasfriends)
		cout << "Friends: " << user1.friends[0] << " " << user1.friends[1] << endl;
	cout << endl;
}

void updateUserName(user &user1, string name)
{
	user1.name = name;
}

void addUserFriends(user & user1, string friend1, string friend2)
{
	user1.friends[0] = friend1;
	user1.friends[1] = friend2;
	user1.hasfriends = true;
}


