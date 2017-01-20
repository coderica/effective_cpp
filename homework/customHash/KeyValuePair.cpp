#include "KeyValuePair.h"

KeyValuePair::KeyValuePair() : key("/0"), value(0)
{

}//default constructor

KeyValuePair::KeyValuePair(string _key, int _value) : key(_key), value(_value)
{
}

KeyValuePair::KeyValuePair(string s)
{
    string delimiter = ":";
    unsigned long location = s.find(delimiter);
    key = s.substr(0, location);
    value = stoi(s.substr(location+1, s.length()));
}

KeyValuePair::KeyValuePair(const char* s) : KeyValuePair(string(s))
{
}

KeyValuePair::KeyValuePair(const KeyValuePair & kvp) : KeyValuePair(kvp.key, kvp.value)
{
}//copy constructor

ostream & operator <<(ostream & out, KeyValuePair & p)
{
    cout << p.key << " : " << p.value << " ";
    return out;
}

KeyValuePair::operator string() const
{
    string val = to_string(value);
    string s = key + ":" + val;
    return s;
}// convert this value to a string