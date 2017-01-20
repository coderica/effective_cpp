#pragma once

#ifndef hdr1 
#define hdr1


enum genderType { male, female };

struct user
{
	string name;
	genderType gender;
	int age;
	string friends[2];
	bool hasfriends;
};
#endif