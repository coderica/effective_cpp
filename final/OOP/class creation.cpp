#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class date
{
private:
	int month;
	int day;
	int year;
public:	
	date();
	date(string strDate);
	date(int month, int day, int year);
	void set(int month = 1, int day = 1, int year = 2016);
	void display() 
	{ 
		cout << month << '/' << day << '/' << year << endl; 
	}
};

class bad_date
{
	int month; int day;
public:
	bad_date(int month, int day) :month(month), day(day)
	{ }
	void error() {
		cout << "Invalid date: " << endl
			 << "Month: " << month << "  Day: " << day << endl;
	}
};


date::date(): date(1,1,2016)
{  }

date::date(string strDate)
{
	
	istringstream s1(strDate);
	s1 >> month;
	s1.get();
	s1 >> day;
	s1.get();
	s1 >> year;
}

date::date(int month, int day, int year) : month(month), day(day), year(year)
{  }

void date::set(int month, int day, int year)
{
	if (month > 12 || day > 31)
		throw(bad_date(month, day));
	this->month = month;
	this->day = day;
	this->year = year;
}

int main()
{
	date d1;
	try {
		d1.set(12, 32, 2016);
	}
	catch (bad_date errDate)
	{
		errDate.error();
	}
}