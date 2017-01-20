#pragma once

class Basket
{

public:
	virtual void display() = 0;
	virtual string getValue()=0;
	virtual ~Basket() {};
};

class KeyValuePair
{
protected:
	string key;
	Basket *value;
public:
	KeyValuePair() {};
	virtual string getValue() { return value->getValue(); }
	string getKey() { return key; }
	void display() { 
		string sval = value->getValue();
		string skey = getKey();
		cout << sval << ":" << skey;
	}
};

class PairList: public vector<KeyValuePair> {
public:
	PairList() :vector<KeyValuePair>(){}
	string getValue(string key);
	virtual void display();
};

class Person : public Basket
{
protected:
	string name;
public:
	
	Person(string n = "") :Basket() { name = n; }
	void display() override { cout << name; }
	string getValue() override { return name; }
};

class Employee : public KeyValuePair
{
public:
	Employee(Person *p, int empId);
};


