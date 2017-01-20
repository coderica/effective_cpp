//PROBLEM 1: **********************************************
//  The problem: Sort an array of doubles (may use a vector or an array).
//      Work through the bubble sort algorithm as an exercise in working with arrays, functions and references.
//      There is a lot of code out on the internet, so this assignment will be graded as pass/fail.
//      We will be looking for an elegant solution using the tools in C++.
//
//  Ground Rules: You may use a vector or an array. You may only use one array – i.e., you must sort it in place.
//      User Input: optional – you may hard code the array values
//      Output: display the array prior to and after sorting

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<double> v) //does not print with perfect precision, however values are stored correctly
{
    for (int x=0; x < v.size(); x++) {
        cout << v[x] << " ";
    }
    cout << endl;
}

vector<double> bubble_sort(vector<double> v)
{
    int reducing_size = (int)v.size();
    for (int i = 0; i < v.size(); i++) //loop through doubles
    {
        bool swapped = false; //watch for swaps
        int a = 0;
        for (int b = 1; b < reducing_size; b++)
        {
            if (v[a] > v[b])
            {
                swap(v[a], v[b]); //swap values to sort
                swapped = true;
            }
            a++;
        }
        reducing_size--; //last element is always sorted after each runthrough
        if (!swapped) { break; } //if no swaps were done, vector is sorted
    }
    return v; //return sorted vector
}

int main() {
    vector<double> doubles {2.63, 0.222, 1.0000007, 0.02, 3.990253, 2.222222222, 0.08};
    cout << "Unsorted: ";
    print_array(doubles);
    vector<double> sorted = bubble_sort(doubles);
    cout << "Sorted: ";
    print_array(sorted);
}