#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyException :public std::exception {
public:
	MyException(const string m = "") :strErr(m) {}
	~MyException(void) {};
	const char* what() const override
	{
		return strErr.c_str();
	}
private:
	string strErr;
};

int main()
{
	try {
		int n = 10;
		throw MyException("error happening!\n\n");
	}
	catch (MyException &e)
	{
		cout << e.what();
	}
}
