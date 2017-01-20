#include <iostream>
using namespace std;

class Number
{
	int *data;
public:
	Number(int);
	Number();
	~Number();
	void set (int);
	bool isDefined() const;
	int value() const;
   	void show() const;
	int operator + (int) const;
	Number & operator + (const Number &);
	Number & operator = (const Number &);
	int operator ++ ();
	int operator ++ (int);  //postfix version
	bool operator > (const Number &) const;
	void *operator new(size_t);
	operator int();
	friend int operator + (int, const Number &);
	//friend ostream& operator << (ostream &, const Number &);
	friend istream& operator >> (istream &in, Number &n);
};

void * Number::operator new(size_t t)
{
	void *p = malloc(t);
	if (!p) throw bad_alloc();
	static_cast<Number *>(p)->data = new int;
	*static_cast<Number *>(p)->data = 0;
	cout << "Created a new Number\n";
	return p;
}

Number::Number(int n):data(nullptr)
{
	set(n);
}

Number::Number():data(nullptr) {  }

Number::~Number()
{
	if (!isDefined())			//don't delete if is not allocated
		delete data;
}

bool Number::isDefined() const
{
	return data != nullptr;
}

void Number::set (int n)
{
	try {
		if (!isDefined())
			data = new int;
		*data = n;
	}
	catch (bad_alloc)
	{
		cout << "Allocation error\n"; exit(-1);
	}
}

void Number::show() const
{
	cout << "Value is: " << *data << endl;
}

int Number::operator + (int n) const
{
	if (isDefined())
		return *data + n;
	else
		return n;

}

int operator + (int n, const Number &number) 
{
	return number + n;
}

int Number::operator ++ () //prefix operation
{
	if (this->isDefined())
	{
		*data += 1;
		return *data;
	}
	else
		return 0;
}

int Number::operator ++ (int n) //postfix operation
{
	if (this->isDefined())
	{
		int save = *data;
		*data += 1;
		return save;
	}
	else
		return 0;
}

/*ostream& operator << (ostream &out, const Number &n)
{
	int data = n.isDefined() ? *n.data : 0;
	out << data;
	return out;
}
*/

istream& operator >> (istream &in, Number &n)
{
	int data;
	in >> data;
	n.set(data);
	return in;
}

bool Number::operator > (const Number &n) const
{
	if (this->isDefined() && n.isDefined())
		return *this->data > *n.data;
	else
		return false;
}

int Number::value() const
{
	if (isDefined())
		return *data;
	else
		return 0;
}

Number& Number::operator + (const Number & n)
{
	if (this->isDefined() && n.isDefined())
		*this->data += n.value();

	return *this;
}

Number& Number::operator = (const Number & n)
{
	if (n.isDefined())
		set(n.value());

	return *this;
}

Number::operator int()
{
	if (isDefined())
		return *data;
	else
		return 0;
}

int main()
{
	Number n1 = 2, n2 = 4;
	Number *n3 = new Number;
	n1 = n1 + n2 + *n3;
	cout << n1 << endl;
	return 1;
}
