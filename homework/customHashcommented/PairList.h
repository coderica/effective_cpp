#ifndef CUSTOMHASH_PAIRLIST_H
#define CUSTOMHASH_PAIRLIST_H


#include <iostream>
#include <vector>
#include "KeyValuePair.h"
using namespace std;

// @@ Could be const ref
typedef bool (*callback)(KeyValuePair & p);

//Class PairList contains a vector of key value pairs. I.e., it contains a set of KeyValuePair objects.
class PairList {
private:
    vector<KeyValuePair> list;
public:
    //Implement Exception Handling within the PairList class to
        // catch out of bound errors and
        // catch attempts to access a non-existent key.
    PairList(); //default constructor
    PairList(const PairList & pl);
    PairList & findAll(callback); // @@ Could be const method
    PairList & push_back(const KeyValuePair p);
    PairList & operator +(const KeyValuePair p);//overload + operator
//    PairList & operator +(const string s);//overload + operator
    friend ostream & operator <<(ostream & out, PairList & pl); //overload << operator

    // @@ Could be const method
	int operator [](const string v);//overload [] operator with int
    KeyValuePair& operator [](const int k);//overload [] operator with string
};


#endif //CUSTOMHASH_PAIRLIST_H
