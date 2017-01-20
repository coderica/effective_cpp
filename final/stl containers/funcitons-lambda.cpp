#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct  isOdd {			
	bool  operator()  (int i)
	{
		return(i % 2) == 1;
	}
};

bool isOdder(int i)
{
	return(i % 2) == 1;
}



int main()
{
	vector<int> v1{ 1,44,5,3,22,76,45,84,23,9 };
	isOdd fOdd;

	auto n = count_if(v1.begin(), v1.end(), fOdd);
	n = count_if(v1.begin(), v1.end(), isOdder);
	n = count_if(v1.begin(), v1.end(), [](int i) {return(i % 2) == 1; });

	cout << n << " are odd\n";

}