#include <iostream> 
#include <vector> 
using namespace std;

typedef vector<int> INTVECTOR;

template <class T>
void showVectorStats(char *label, vector<T>& v)
{
	cout << label << ": Size: " << v.size() <<
		 " Capacity: " << v.capacity() << endl << endl;
}

void main()
{
	// No elements in theVector 
	INTVECTOR theVector;
	showVectorStats("Just created", theVector);
	

	// Add one element to the end of the vector, an int 
	// with the value 42. Memory will be allocated if needed.  
	theVector.push_back(42);
	showVectorStats("One element added",theVector);

	// Add two more elements to the end of the vector. // theVector contains [ 42, 1, 109 ]
	
	theVector.reserve(10);
	theVector.push_back(1);
	theVector.push_back(109);
	showVectorStats("10 spaces reserved, 2 elements added", theVector);

	// Erase last element in vector.    
	theVector.pop_back();  // theVector contains [ 42, 1 ]
	showVectorStats("One element removed", theVector);

	theVector.resize(8);
	showVectorStats("Resized to 8", theVector);

	theVector.insert(theVector.end(), { 3,2,1 });
	showVectorStats("Insert- 3,2,1", theVector);

	theVector.shrink_to_fit();
	showVectorStats("After shrink to fit", theVector);

	theVector.resize(6);
	showVectorStats("Resize to 6", theVector);

	// show the vector
	for (unsigned i = 0; i<theVector.size(); i++)
	{
		cout << "Element " << i << " is "
			<< theVector[i] << endl;
	}
}  //end main
