#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


template <class T>
void showVectorReverse(vector<T> v);
template <class T>
void showVectorReverse2(vector<T> v);

int main()
{
	vector<int> v1= {1, 2, 3, 4, 5};
	showVectorReverse(v1);
	showVectorReverse2(v1);

	return 0;
}

template <class T>
void showVectorReverse(vector<T> v)   //what is wrong with this?
{
	for (auto i = v.end() - 1; i != v.begin(); i--)
		cout << *i << " - ";
	cout << endl;
}

template <class T>
void showVectorReverse2(vector<T> v)		//better!
{
	for (auto i = v.rbegin(); i != v.rend(); i++)
		cout << *i << " - ";
	cout << endl;
}