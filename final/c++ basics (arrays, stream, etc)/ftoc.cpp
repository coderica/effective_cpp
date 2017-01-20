#include <iostream>
using namespace std;

int main()
{
	int degreesF, degreesC;


	cout << "Enter temp in degrees fahrenheit: ";
	cin >> degreesF;

	//formula: multiply 5/9 times temp in fahrenheit minus 32

	degreesC = static_cast<int> (5.0 / 9 * (degreesF - 32));

	cout << "Degrees Celsius: " << degreesC << endl;

	return 0;
}