#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class OrderedArray
{
	T * array;
	unsigned int size;
public:
	OrderedArray() :array(nullptr),size(0) {}
	void insert(T item);
	void display() const;
};

template <typename T>
void OrderedArray<T>::insert(T item)
{
	if (!size)
	{
		array = new T[1];
		array[0] = item;
		size = 1;
	}
	else
	{
		T * temp = new T[size+1];
		unsigned int i = 0, j = 0;
		while (i < size && item > array[i])
			temp[j++] = array[i++];

		temp[j++] = item;
		while (i < size)
			temp[j++] = array[i++];

		delete[] array;
		array = temp;
		size++;
	}
	
}


template <typename T>
void OrderedArray<T>::display() const
{
	for (unsigned int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
	
	OrderedArray<int> array1;
	array1.insert(4);
	array1.insert(1);
	array1.insert(66);
	array1.insert(12);
	array1.display();

}