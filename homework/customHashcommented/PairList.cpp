#include "PairList.h"

PairList::PairList()
{
}//default constructor

PairList::PairList(const PairList & pl)
{
    list = pl.list;
}//copy constructor

PairList & PairList::findAll(callback c)
{
    PairList* pl = new PairList();
    for (KeyValuePair &p : list) // access by reference to avoid copying
    {
        if (c(p)) { //use callback on each key-value pair in this list
            pl->push_back(p); //if callback returns true, then add kvp to new list
        }
    }
    return *pl;
}

PairList & PairList::push_back(const KeyValuePair p)
{
    list.push_back(p);
    return *this;
}

PairList & PairList::operator +(const KeyValuePair p)
{
    list.push_back(p);
    return *this;
}//overload + operator - plist + p1 + p2 + "depth:10" + p3 + p4

ostream & operator <<(ostream & out, PairList & pl)
{
    for (KeyValuePair &p : pl.list) // access by reference to avoid copying
    {
        cout<<p;
    }
    return out;
}//overload << operator

int PairList::operator [](const string v)
{
    int val = 0;
    for (KeyValuePair &p : list) // access by reference to avoid copying
    {
        if (p.key == v) {
            val =  p.value;
        }
    }
    return val;
}//overload [] operator with string

KeyValuePair& PairList::operator [](const int k)
{
    return list[k];
}//overload [] operator with int