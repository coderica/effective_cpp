#include <iostream>
#include <string>
using namespace std;


template <class T1, class T2, class TSum>
void  addThem(T1 m, T2 n, TSum &sum);

enum cars  { toyota, honda, subaru, mercedes, volvo, hundai, chevrolet };
string strCars[]  = { "toyota", "honda", "subaru", "mercedes", "volvo", "hundai", "chevrolet" };

void addTest()
{
	cout << "Add test : \n\n";
	int n1 = 2;
	float n2 = 3.5;
	cout << "Double + Int: " << n1 << " " << n2 << endl;
	double s;
	addThem(n2, n1, s);
	cout << "After: sum = " << s << endl << endl;

	cars mycar = subaru, newcar;
	int n = 2;
	addThem(n, mycar, newcar);
	cout << "New car is: " << strCars[newcar] << endl;

}

template <class T1, class T2, class TSum>
void  addThem(T1 m, T2 n, TSum &sum)
{
	m = m + static_cast<T1>(n);
	sum = static_cast<TSum>(m);
}


int main()
{
	
	addTest();

}