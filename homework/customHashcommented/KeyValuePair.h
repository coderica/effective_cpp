#ifndef CUSTOMHASH_KEYVALUEPAIR_H
#define CUSTOMHASH_KEYVALUEPAIR_H


#include <iostream>
using namespace std;


//Class KeyValuePair will contain a key that is a string and a value that is an integer.
class KeyValuePair {
public:
    string key;
    int value;
    KeyValuePair(); //default constructor
    KeyValuePair(string _key, int _value); // @@ Constructors could take string reference
    KeyValuePair(string s); //string constructor //p1 = "count:1";
    KeyValuePair(const char* s); //string constructor //p1 = "count:1";
    KeyValuePair(const KeyValuePair & kvp); //copy constructor
	// @@ Could take a const reference
    friend ostream & operator <<(ostream & out, KeyValuePair & p); //overload << operator
    operator string() const;
};


#endif //CUSTOMHASH_KEYVALUEPAIR_H
