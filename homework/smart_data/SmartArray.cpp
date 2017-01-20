// Create a class called SmartArray that can dynamically grow and shrink with its data members

#include "SmartArray.h"

int SmartArray::defaultData = 0;
int SmartArray::instance = 0;

SmartArray::SmartArray():data(nullptr),_size(0)
{
    instance+=1;
    count = instance;
} // default constructor

SmartArray::SmartArray(const int* arr, const int size):data(nullptr), _size(0)
{
    int newSize = size;
    int * newArray = new int[newSize]; // create new array
    memcpy(newArray, arr, sizeof(int) * newSize); //copy contents into new array
    setData(newArray, newSize);
    instance+=1;
    count = instance;
} // constructor

SmartArray::SmartArray(int n_args, ... ):data(nullptr), _size(0) //not very efficient
{
    va_list arguments;
    va_start(arguments, n_args);
    for (int i=0; i<n_args; i++) {
        pushBack(va_arg(arguments, int)); //push int into array
    }
    va_end(arguments);
    instance+=1;
    count = instance;
} //    add block and then loop through new block and add args

SmartArray::SmartArray(const SmartArray &smartArray):SmartArray(smartArray.data, smartArray.size())
{
} // copy constructor

SmartArray::~SmartArray()
{
    empty();
} // destructor

SmartArray& SmartArray::setData(int* arr, const int size)
{
    empty();
    try {
        data = arr;
        _size = size;
    }
    catch (bad_alloc)
    {
        cout << "Allocation error\n"; exit(-1);
    }

    return *this;
}

SmartArray& SmartArray::addBlock(int num)
{
    pushBack(defaultData, num);
    return *this;
}// increase size of the array by the specified size – new items have a data value equal to the default data value

SmartArray& SmartArray::pushBack(int num, int block)
{
    int newSize = _size+block; //add block to size
    int * newArray = new int[newSize]; //create new array with more space
    memcpy(newArray, data, sizeof(int)*_size); //copy contents into new array
    for(int i=_size; i<newSize; i++) {
        newArray[i] = num; // set new space(s) to num
    }
    setData(newArray, newSize);
    return *this;
}// adds space for one element and then stores the specified data value

SmartArray& SmartArray::insert(const int fromPos, const SmartArray &fromArray, const int howMany, const int toPos)
{
    int newSize = _size + howMany;
    int * newArray = new int[newSize]; //create new array with more space

    int a = fromPos;
    int b = toPos-1;
    int c = 0;

    for(int i=0; i<newSize; i++, c++) {
        newArray[i] = data[c]; // copy contents of old array
        if (i >= b && i < b+howMany) { // if inside block
            char at = *fromArray.at(a);
            newArray[i] = *fromArray.at(a); // copy contents of fromArray
            a++;
            c--;
        }
    }
    setData(newArray, newSize);
    return *this;
} // insert data from “fromArray” starting at fromPos for howMany elements into this array starting at position toPos

SmartArray& SmartArray::removeBlock (int pos, int howMany)
{
    int newSize = _size-howMany; //add block to size
    int * newArray = new int[newSize]; //create new array with more space

    int a = 0;
    for(int i=0; i<newSize; i++, a++) {
        if (a == (pos-1)) {
            a+= howMany;
        } //skip block
        newArray[i] = *this->at(a+1); // copy contents
    }
    setData(newArray, newSize);
    return *this;
} // removes howMany items from this array starting at position pos.

int SmartArray::valueAt(int pos) const
{
    return data[pos-1];
} // returns the data value at the specified position.

int* SmartArray::at(int pos) const
{
    return &data[pos-1];
} // returns a reference to element at specified position (can be used to store a value)

bool SmartArray::isEmpty() const
{
    return _size == 0;
} // true if the array is empty/null

void SmartArray::empty()
{
    if(!isEmpty()) {
        delete[] data;
    }
    _size = 0;
} // remove all items

int SmartArray::size() const
{
    return _size;
} // number of items in the array

string SmartArray::toString() const
{
    string str;
    for(int i=0; i<_size; ++i) {
        str.push_back('0'+ data[i]);
    }
    return str;
} // convert data array to string

SmartArray& SmartArray::display()
{
    cout << "SmartArray " << count << ": ";
    if (isEmpty()) {
        cout << "is empty";
    } else {
        cout << *this;
    }
    cout << endl;
    return *this;
} // display all elements

ostream & operator << (ostream & out, const SmartArray &s)
{
    for (int i=0; i<s.size(); i++) {
        out << s.data[i];
        out << ' ';
    }
    return out;
} // Override << to display all elements
