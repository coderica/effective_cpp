// Create a class called SmartString that dynamically stores a character array

#include "SmartString.h"

int SmartString::instance = 0;

SmartString::SmartString():data(nullptr), _size(0)
{
    instance+=1;
    count = instance;
} //default constructor

SmartString::SmartString(const char* data):data(nullptr), _size(0)
{
    int newSize = int(strlen(data));
    char * newString = new char[newSize+1]; // create new array
    memcpy(newString, data, sizeof(char) * (newSize+1)); //copy contents into new array
    instance+=1;
    count = instance;
    setData(newString, newSize);
} // constructor

SmartString::SmartString(const SmartString &smartString):SmartString(smartString.data)
{
} // copy constructor

SmartString::~SmartString()
{
    empty();
} // destructor

SmartString& SmartString::assign(const char *s)
{
    int newSize = int(strlen(s));
    char * newString = new char[newSize+1]; // create new array
    memcpy(newString, s, sizeof(char) * (newSize+1)); //copy contents into new array
    setData(newString, newSize);
    return *this;
} // set the data string to s – returns a reference to this object

SmartString& SmartString::assign(const string* s)
{
    int newSize = int(s->size()+1);
    char * newString = new char[newSize]; // create new array
    memcpy(newString, s, sizeof(char) * (newSize)); //copy contents into new array
    setData(newString, newSize);
    return *this;
} // set the data string to s – returns a reference to this object

SmartString& SmartString::concat(const SmartString* s)
{
    int newSize = int(_size + s->size());
    char * newString = new char[newSize+1]; // create new array
    memset(newString, 0, sizeof(char)*(newSize+1));
    strcat(newString, data);
    strcat(newString, s->data);
    setData(newString, newSize);
    return *this;
} // append the string contained in s to the end of this objects data string - returns a reference to this object

SmartString& SmartString::concat(string* s)
{
    int newSize = int(_size + s->size());
    char * newString = new char[newSize+1]; // create new array
    strcat(newString, data);
    strcat(newString, s->c_str());
    setData(newString, newSize);
    return *this;
}

char* SmartString::substring(int posStart, int posEnd) const
{
    posEnd-=1;
    posStart-=1;
    posEnd = posEnd > strlen(data) ? int(strlen(data)) : posEnd;
    int len = (posEnd - posStart) + 1;
    char * newArray = new char[len]; //+1 for null termination
    int a = posStart;
    for(int b=0; b<len; b++, a++) {
        newArray[b] = data[a]; // copy contents of old array
    }

    return newArray;
} // return a null terminated char array string consisting of all characters from posStart to posEnd inclusive. If posEnd is too large or not provided, the substring will end at the end of the data string.

char SmartString::valueAt(const int pos) const
{
    return data[pos];
} // returns the character value at the specified position.

char* SmartString::at(const int pos) const
{
    return &data[pos-1];
} // returns a reference to element at pos (this can be used to store a value)

void SmartString::setData(char* str, int size)
{
    empty();
    try {
        data = str;
        _size = size;
    }
    catch (bad_alloc)
    { 
        cout << "Allocation error\n"; exit(-1);
    }
}

bool SmartString::isEmpty() const
{
    return _size == 0;
} // true if the string is empty

SmartString& SmartString::empty()
{
    if(!isEmpty()) {
        delete[] data;
    }
    _size = 0;
    return *this;
} // set the length of the string to 0

int SmartString::size() const
{
    return _size;
} // length of the string

SmartString& SmartString::display()
{
    cout << "SmartString " << count << ": ";
    if (isEmpty()) {
        cout << "is empty";
    } else {
        cout << *this;
    }
    cout << endl;
    return *this;
} // display all elements in array

ostream & operator << (ostream & out, const SmartString &s)
{
    for (int i=0; i<s.size(); i++) {
        out << s.data[i];
    }
    return out;
} // Override << to display a SmartString

bool operator == (SmartString &s1, SmartString &s2)
{
    if (s1.size() != s2.size()) {
        return false;
    }
    for (int i=0; i<s1.size(); i++) {
        if (s1.data[i] != s2.data[i]) {
            return false;
        };
    }
    return true;
} // Override == to return true if two data strings are the same.

void operator += (SmartString &s1, SmartString &s2)
{
    s1.concat(&s2);
} // Override += to concatenate two data strings