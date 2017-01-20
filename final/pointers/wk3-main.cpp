#include <iostream>
#include <string>
using namespace std;

#include "wk3-user.h"
#include "wk3-utilities.h"

int main()
{
	user jim = { "Jim", male, 12 ,{ "", "" }, false };
	user jane;
	jane.name = "Janey";
	jane.gender = female;
	jane.age = 14;
	jane.hasfriends = false;

	//	displayUser(jim);
	updateUserName(jim, "james");
	//	displayUser(jim);
	addUserFriends(jim, "sammy");
	//	displayUser(jim);

	const int numUsers = 4;
	user allUsers[numUsers] = { jim, jane,
	{ "anita", female, 11 ,{ "", "" }, false },
	{ "bob", male, 12,{ "Jim", "" }, true }
	};

	allUsers[2].friends[1] = "Sally";
	allUsers[2].hasfriends = true;

	for (int i = 0; i < numUsers; i++)
		displayUser(allUsers[i]);

	return 0;
}

