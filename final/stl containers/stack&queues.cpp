#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	stack<string> mystack;
	vector<string> v = { "to", "be", "or",  "not", "to", "be" };
	for (auto it = v.begin(); it != v.end(); it++)
		mystack.push(*it);
	while (!mystack.empty())
	{
		cout << mystack.top() << " " ;
		mystack.pop();
	}
	cout << endl;

	queue<string> myqueue;
	for (auto it = v.begin(); it != v.end(); it++)
		myqueue.push(*it);
	while (!myqueue.empty())
	{
		cout << myqueue.front() << " ";
		myqueue.pop();
	}
	cout << endl;

	priority_queue<string> myqueue2;
	for (auto it = v.begin(); it != v.end(); it++)
		myqueue2.push(*it);
	while (!myqueue2.empty())
	{
		cout << myqueue2.top() << " ";
		myqueue2.pop();
	}
	cout << endl;

}