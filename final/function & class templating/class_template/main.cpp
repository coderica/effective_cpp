#include <iostream>
using namespace std;

class Person
{
    string name;
public:
    Person(string name = "joe") :name(name) {}
    bool operator > (Person& p2) { return name > p2.name; }
    bool operator < (Person& p2) { return name < p2.name; }
    friend ostream& operator << (ostream& out, Person& p) {
        out << p.name;
        return out;
    }
};

class Employee
{
    string name;
    int pay;
public:
    Employee(string name="Bobby", int pay=0) :name(name), pay(pay) {}
    bool operator > (Employee& e2) { return pay > e2.pay; }
    bool operator < (Employee& e2) { return pay < e2.pay; }
    friend ostream& operator << (ostream& out, Employee& e) {
        out << e.name << ": " << e.pay;
        return out;
    }
};

template <typename T=int>
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
//    OrderedArray of ints
    OrderedArray<> array1;
    array1.insert(4);
    array1.insert(1);
    array1.insert(66);
    array1.insert(12);
    array1.display();

//    OrderedArray of strings
    OrderedArray<string> array2;
    array2.insert("sixty six.");
      array2.insert("one.");
    array2.insert("four.");
    array2.insert("twelve.");
    array2.display();

//    OrderedArray of a Person type
    OrderedArray<Person> array3;
    array3.insert(string("Bob"));
    array3.insert(string("Mary"));
    array3.insert(string("Luis"));
    array3.insert(string("Cary"));
    array3.display();

//    OrderedArray of Employees
    OrderedArray<Employee> array4;
    array4.insert(Employee("Grace", 6));
    array4.insert(Employee("Paul", 12));
    array4.insert(Employee("Sara", 2));
    array4.insert(Employee("Ariel", 8));
    array4.display();

    return 0;
}