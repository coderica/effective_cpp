//Redo the bubble sort example- this time with pointers. Your code should have two arrays: an array of pointers and an array of data (integers or strings). Each pointer in the pointer array should point to one element in the data array, Sort the second array by changing pointer values ONLY. I.e., you are not allowed to move any of the array elements.

#include "utilities.h";

int main() {
    const int LENGTH = 7;
    double DOUBLES[LENGTH] = {2.63, 0.222, 1.0000007, 0.02, 3.990253, 2.222222222, 0.08};
    double *POINTERS[LENGTH]; //declare array with n pointers (where n is length of the given data array)

    for (int i = 0; i < LENGTH; i++)
    {
        POINTERS[i] = &DOUBLES[i]; // assign each pointer to an element in the data array
    }

    bubble_sort(POINTERS, LENGTH);
    pretty_print(POINTERS, DOUBLES, LENGTH);

    return 0;
}