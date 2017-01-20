#include <iostream> 
#include <vector> 
using namespace std;

template <class T>
void showVector(vector<T> v)
{
	for (auto i = 0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
void main()
{
	vector<int> v1;			//empty
	cout << "v1 - empty: ";  showVector(v1);

	vector<int> v2(10);  	//10 elements
	cout << "v2 - 10 items: ";  showVector(v2); 
	
	vector<int> v3(10, 1); 	//10 1’s
	cout << "v3- 10 1's: ";  showVector(v3); 
	
	vector<int> v4 = v3;  	//copy from v3
	cout << "v4- copy v3: ";  showVector(v4);

	vector<int> v5 = { 1,2,3,4 };
	cout << "v5 - init list (1-4): ";  showVector(v5);

	int array[] = { 2,4,6,8,10,12,14,16,18,20 };
	vector<int> v6(array+1, &array[8]);
	cout << "v6- pointer range, evens 4-16: ";  showVector(v6);

	vector<int> v7(v6.begin()+1, v6.end());
	cout << "v7- iterator range (6 - 16): ";  showVector(v7);
}  
