#include <iostream>
#include "utilities.h"
using namespace std;

int compare(char *s1, char *s2)
{ // a < b => 1 // aa < b => 1 // aaa > aa => -1

    if (is_greater_than(s1, s2) || is_longer_than(s1, s2))
    { //Return -1 if the first string is identical but longer or alphabetically greater.
        return -1;
    }

    if (is_greater_than(s2, s1) || is_longer_than(s2, s1))
    { // Return 1 if the second string is identical but longer or alphabetically greater.
        return 1;
    }

    return 0; // if they are the same.
}

int is_greater_than(char *s1, char *s2)
{
    return s1[0] > s2[0];
}

int is_longer_than(char *s1, char *s2)
{
    int len1 = int(strlen(s1));
    int len2 = int(strlen(s2));

    if (len1 > len2 && s1[0] == s2[0])
    {
        return 1;
    }
    return 0;
}

void shift_right(char *s, int p)
{
    int l = int(strlen(s)-1);
    while (l >= p)
    {
        s[l + 1] = s[l];
        s[l] = 0;
        l--;
    }
}

void pretty_print(char *s)
{
    for (int i=0; i < strlen(s); i++)
    {
        cout << s[i];
    }
}

void strInsert(char *s1, char *s2, int position)
{ // Insert s2 into s1 at position specified. Assume that s1 is large enough to store all characters.
    int len2 = int(strlen(s2)-1);
    for (int i = 0; i <= len2; i++)
    {
        shift_right(s1, position);
        s1[position] = s2[i];
    }

    pretty_print(s1);
}