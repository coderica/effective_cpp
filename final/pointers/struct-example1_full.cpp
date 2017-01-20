#include <iostream>
#include <string>
using namespace std;

enum genderType { male, female };

struct user
{
	string name;
	genderType gender;
	int age;
	string friends[2];
	bool hasfriends;
};


void displayUser(const user &);
void updateUserName(user &, string);
void addUserFriends(user &, string , string = "");

int main()
{
	user jim = { "Jim", male, 12 , {"", ""}, false};
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
					{"anita", female, 11 , {"", ""}, false},
					{"bob", male, 12, { "Jim", "" }, true}
			};

	allUsers[2].friends[1] = "Sally";
	allUsers[2].hasfriends = true;
	
	for (int i = 0; i < numUsers; i++)
		displayUser(allUsers[i]);

	return 0;
}

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

