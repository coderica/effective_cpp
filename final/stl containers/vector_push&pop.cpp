#include <iostream> 
#include <vector> 
using namespace std;

typedef vector<int> INTVECTOR;
void main()
{
	// No elements in theVector 
	INTVECTOR theVector;

	// Add one element to the end of the vector, an int 
	// with the value 42. Memory will be allocated if needed.  
	theVector.push_back(42);

	// Add two more elements to the end of the vector. // theVector contains [ 42, 1, 109 ]
	theVector.push_back(1);
	theVector.push_back(109);

	// Erase last element in vector.    
	theVector.pop_back();  // theVector contains [ 42, 1 ]

	// show the vector
	for (int i = 0; i<theVector.size(); i++)
	{
		cout << "Element " << i << " is "
			<< theVector[i] << endl;
	}
}  //end main
