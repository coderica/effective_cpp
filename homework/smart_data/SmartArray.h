// Create a class called SmartArray that can dynamically grow and shrink with its data members

#ifndef SMART_DATA_SMARTARRAY_H
#define SMART_DATA_SMARTARRAY_H

#include <iostream>
using namespace std;

class SmartArray
{
    int _size; // size of the array
    int* data; // pointer to a int array
    int count; // version number
    static int defaultData; // static member representing a default data value for newly allocated memory
    static int instance; // static class instance count
public:
    SmartArray();
    SmartArray(const int* arr, const int size);
    SmartArray(int n_args, ... );
    SmartArray(const SmartArray &smartArray);
    ~SmartArray();

    SmartArray& setData(int* arr, const int size);
    SmartArray& addBlock(int num);
    SmartArray& pushBack(int num, int block=1);
    SmartArray& insert(const int fromPos, const SmartArray &fromArray, const int howMany, const int toPos);
    SmartArray& removeBlock (int pos, int howMany);
    int valueAt(int pos) const;
    int* at(int pos) const;
    bool isEmpty() const;
    void empty();
    int size() const;
    std::string toString() const;
    SmartArray& display();

    friend ostream & operator << (ostream & out, const SmartArray &s);
};

#endif //SMART_DATA_SMARTARRAY_H
