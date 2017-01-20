#include <iostream>
#include <string>
using namespace std;

struct listElement
{
	string data;
	int sortKey;
	listElement *next;
	listElement *prev;
};

void displayList(listElement *);

int main()
{
	listElement animals[4], *p, *lastNode;
	animals[0].data = "cat";
	animals[0].sortKey = 2;
	animals[1].data = "dog";
	animals[1].sortKey = 22;
	animals[2].data = "fish";
	animals[2].sortKey = 10;
	animals[3].data = "frog";
	animals[3].sortKey = 8;

	p= &animals[0];
	listElement *head = p;
	p->prev = nullptr;
	p->next = nullptr;
	lastNode = p;

	p= &animals[3];
	p->prev = lastNode;
	p->next = 0;
	lastNode->next = p;
	


	displayList(head);


	return 1;
}

void displayList(listElement *p)
{
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}

}