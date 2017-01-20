#include <iostream>
#include "utilities.h"
using namespace std;

int main()
{
    char s1[11] = {'a', 'a', 'a', 'a', 'a'};
    char s2[5] = {'b', 'b', 'b', 'b', 'b'};
    int POS = 3;

    cout << compare(s1, s2) << endl;
    strInsert(s1, s2, POS);
    return 0;
}