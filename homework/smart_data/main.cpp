//Rubric:
//20 points - all required methods/data in place
//40 points - program compiles and runs without crashing
//20 points - thorough test program
//20 points = quality of code:
//      program makes good use of const methods,
//      data members are private,
//      program is segregated into meaningful cpp and header files,
//      variable names are meaningful


#include "SmartString.h"
#include "SmartArray.h"

using namespace std;

int main() {
    const int SIZE = 9;
    SmartArray* sa1 = new SmartArray(SIZE,4,6,7,56,2,12,7,73,44); //initialize with variable params
    sa1->display();
    cout << sa1->valueAt(4) << endl; //display value at index 3/pos4
    *(sa1->at(4)) = 6; //set value at index 3 to '6'
    sa1->display();

    SmartArray* sa2 = new SmartArray(*sa1);
    sa2->display().pushBack(2).display();
    sa1->display();

    const int nums[5] = {2, 8, 34, 5, 1};
    SmartArray* sa3 = new SmartArray(nums, 5); // initialize with array
    sa3->display().insert(2, *sa1, 2, 1).display() //test insert
            .removeBlock(4,2).display() // test removeBlock
            .addBlock(6).display(); //test addBlock
    cout << sa3->toString() << endl; //display as string

    char str[6] = "hello";
    SmartString* ss1 = new SmartString(str); //initialize with char array
    ss1->display();
    cout << ss1->valueAt(3) << endl; //check value at index 2

    char * substring = ss1->substring(3, 5); //return value from pos 3 to pos 5 (inclusive)
    for (int i=0; i<strlen(substring); i++) {
        cout << substring[i]; //display values
    }
    cout << endl;
    ss1->display();

    SmartString* ss2 = new SmartString(str); //initialize with char array
    string* cat = new string(" there");

    ss2->concat(ss1).concat(cat).display() // test concat with string ptr
            .assign(cat).display() // test assign with string
            .assign(str).display(); // test assign with char array

    bool b = *ss1 == *ss2; //check equality between two Smart Strings
    cout << b << endl;

    ss2->display();
    ss1->display();
    *ss2 += *ss1; //concat two SmartStrings
    ss2->display();
    b = *ss1 == *ss2; //check equality between two Smart Strings
    cout << b << endl;

    SmartString* ss3 = new SmartString(*ss1);
    ss3->display();
    ss1->empty().display();
    ss3->display();

    return 0;
}
