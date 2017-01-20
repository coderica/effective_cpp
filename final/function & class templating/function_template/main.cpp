#include <iostream>
using namespace std;

//Create a function template that takes an array of a generic type and two integers representing a beginning and ending index.  The function should return a pointer to a new array that consist of all elements in the original array from the first index to the last index (inclusive).  If the last index is beyond the size of the original array, stop at the last element.
template <class T, unsigned size>
T* newArray(T (&arr)[size], int first, int last) {
    int length = last-first+1;
    T* newArr = new T[length];
    for(int i = 0, index = first; i<length && index<size; i++, index ++) {
        newArr[i] = arr[index];
    }
    return newArr;
}

//Create a second function to display an array of a generic type.
template <class T, unsigned size>
void display(T (&arr)[size]) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    char ca[] = "hello";
    char* newca = newArray(ca, 2, 4);

    int na[] = {1,2,3,4,5,6};
    int* newna = newArray(na, 1, 3);

    display(ca);
    display(na);

    return 0;
}