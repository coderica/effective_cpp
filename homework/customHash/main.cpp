#include <iostream>
#include "utilities.h"
#include "PairList.h"

using namespace std;

int main() {
    KeyValuePair p1; //default constructor
    p1 = "count:1"; //set the the key:value pair of p1 to "count" and 1
    KeyValuePair p2("size", 10); //create a KeyValuePair with "size" and 10
    KeyValuePair p3 = p1; // copy p1's data into the new KeyValuePair, p3
    KeyValuePair p4("width", 20); // create a KeyValuePair with "width" and 20
    PairList plist; // create a PairList
    plist + p1 + p2 + "depth:10" + p3 + p4; // Add to plist: p1, p2,
    //a pair defined by key:"depth" and value:10, p3 and p4
    cout << plist; //display all elements in the list
    cout << endl;
    PairList temp = plist.findAll(valLess20); // create new PairList w/ all values <20 using valLess20
    cout << temp; // display the new list
    cout << plist["width"] << endl; // display the value for key = "width"
    cout << string(plist[3]) << endl; //display the 4th element of plist
    return 0;
}

//This should be the resulting output:
//count : 1 size : 10 depth : 10 count : 1 width : 20
//count : 1 size : 10 depth : 10 count : 1 20
//count : 1