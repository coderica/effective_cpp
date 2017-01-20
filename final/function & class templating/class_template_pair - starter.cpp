#include <iostream>
#include <string>
#include <vector>
using namespace std;

/************  CLASS DEFINITIONS ****************/

class Basket
{

public:
	virtual void display() = 0;
	virtual string getValue() = 0;
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

class PairList : public vector<KeyValuePair> {
public:
	PairList() :vector<KeyValuePair>() {}
	string getValue(string key);
	virtual void display();
};

class Employee
{
	string name;
	double pay;

public:
	Employee(string _name = "joe", double amount = 0) :name(_name), pay(amount) {}
	void display() { cout << name << ": " << pay << endl; }
	string getName() { return name; }
	double getPay() { return pay; }

	
};

/************  METHOD  DEFINITIONS ****************/

string PairList::getValue(string key)
{
	KeyValuePair *kv;
	for (int i = 0; i < this->size(); i++)
	{
		kv = &this->at(i);
		if (kv->getKey() == key)
			return kv->getValue();
	}
	return "";
}

void PairList::display()
{
	KeyValuePair *kv;
	for (int i = 0; i < this->size(); i++)
	{
		kv = &this->at(i);
		kv->display();  cout << endl;
	}
}


int main()
{
	// create pairs such that the key is the employee id and the value is the employee data
	
}