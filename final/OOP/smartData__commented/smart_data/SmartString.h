// Create a class called SmartString that dynamically stores a character array

#ifndef SMART_DATA_SMARTSTRING_H
#define SMART_DATA_SMARTSTRING_H

#include <iostream>
using namespace std;

class SmartString
{
    int _size; // size of the array
    char* data; // pointer to a char array
    int count; // version number
    static int instance; // static class instance count
public:
    SmartString(const SmartString &);
    SmartString();
    SmartString(const char*);
    ~SmartString();

    SmartString& assign(const char* s);
    SmartString& assign(const string* s);
    SmartString& concat(const SmartString* s);
    SmartString& concat(string* s);
    char* substring (int posStart, int posEnd) const;
    char valueAt(const int pos) const;
    char* at(const int pos) const;
    void setData(char* str, const int size);
    bool isEmpty() const;
    SmartString& empty();
    int size() const;
    SmartString& display();

    friend ostream & operator << (ostream & out, const SmartString &s);
    friend bool operator == (SmartString &s1, SmartString &s2);
    friend void operator += (SmartString &s1, SmartString &s2);

};

#endif //SMART_DATA_SMARTSTRING_H
