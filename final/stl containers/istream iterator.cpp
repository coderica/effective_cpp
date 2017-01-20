#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


template <class T>
void showVector(vector<T> v)
{
	for (auto i = v.begin(); i!= v.end(); i++)
		cout << *i << " - ";
	cout << endl;
}

int main()
{
	vector<int> v1= {1, 2, 3};
	for (istream_iterator<int> i = cin; i != istream_iterator<int>(); ++i)
		v1.push_back(*i);
	showVector(v1);


	return 0;
}
