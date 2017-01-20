#include <iostream>
using namespace std;

class ListElement
{
private:
	int _data;
	ListElement * _next;
public:
	ListElement() : _data(0), _next(nullptr) {}
	ListElement(int val): _data(val) {}
	int data() { return _data; }
	void set(int val) { _data = val; }
	void link(ListElement *e) { _next = e; }
	ListElement *next() { return _next; }
};

class LinkedList
{
private:
	ListElement *head;
	ListElement *tail;
	ListElement *current;
public:
	LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}
	void append(ListElement *e);
	void moveFirst();
	bool moveNext();
	bool empty();
	int data();
};

bool LinkedList::empty()
{
	return head == nullptr;
}
void LinkedList::moveFirst() 
{ 
	current = head; 
}

void LinkedList::append(ListElement *e)
{
	if (!head) //this is first one
	{
		head = tail = current = e;
	}
	else
	{
		tail->link(e);
		tail = tail->next();
	}
	e->link(nullptr);
}
bool LinkedList::moveNext()
{
	if (!current)
	{
		return false;	
	}
	else if (current->next())
	{
		current = current->next();
		return true;
	}
	else
		return false;
}
int LinkedList::data()
{
	if (current)
		return current->data();
	else
		throw overflow_error("Attempt to access beyond list bounds");
}

int main()
{
	//create elements
	ListElement e1 = 10;
	ListElement e2 = 20;
	ListElement e3 = 30;

	//create list
	LinkedList list;

	//addd elements to list
	list.append(&e1);
	list.append(&e2);
	list.append(&e3);

	//navigate through list and display data
	if (!list.empty())
	{
		do
		{
			cout << list.data() << endl;
		} while (list.moveNext());
	}
}