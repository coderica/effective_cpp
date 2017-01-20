#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v1= {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	vector<int>::iterator iter = std::find(v1.begin(), v1.end(), 14);
	if (iter == v1.end()) cout << "not found\n";
	else cout << "Found: " << *iter << endl;
	return 0;
}
