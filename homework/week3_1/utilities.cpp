//
// Created by prenga on 9/22/16.
//
#include <iostream>
using namespace std;
#include "utilities.h";

void bubble_sort(double *pointers[], int length)
{
    int reducing_size = length;
    for (int i = 0; i < length; i++, reducing_size--) //loop through doubles
    {
        bool swapped = false; //watch for swaps
        int a = 0;
        for (int b = 1; b < reducing_size; b++, a++)
        {
            if (*pointers[a] > *pointers[b])
            {
                swap(pointers[a], pointers[b]); //swap values to sort
                swapped = true;
            }
        }
        if (!swapped) { break; } //if no swaps were done, vector is sorted
    }
}

void pretty_print(double *pointers[], double doubles[], int length)
{
    cout << "Original: ";

    for (int i = 0; i < length; i++)
    {
        cout << doubles[i] << ' ';
    }

    cout << endl << endl << "Sorted: ";

    for (int i = 0; i < length; i++)
    {
        cout << *pointers[i] << ' ';
    }
}