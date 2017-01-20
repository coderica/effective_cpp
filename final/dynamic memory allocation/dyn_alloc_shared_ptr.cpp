#include <iostream>
#include <memory>
using namespace std;

struct date {
	int month; 
	int day; 
	int year;
};

void initDate(shared_ptr<date> d, int, int, int);
void displayDate(shared_ptr<date>);

int main()
{
	shared_ptr<date> christmas, newYears, scroogeDay, xmas;
	try {
		christmas = make_shared<date>();
		newYears = make_shared<date>();

		initDate(christmas, 12, 25, 2016);
		initDate(newYears, 1, 1, 2016);
		
		displayDate(christmas);
		displayDate(newYears);
		scroogeDay = christmas;
		xmas = christmas;
		
		cout << scroogeDay.use_count() << endl;
		cout << christmas.use_count() << endl;
		
		christmas.reset();
		cout << scroogeDay.use_count() << endl;
		cout << christmas.use_count() << endl;
		
		displayDate(christmas);
	}
	catch (bad_alloc)
	{
		cout << "memory allocation error\n";
		exit(-1);
	}
	catch (char *s)
	{
		cout << s << endl;
		exit(-1);
	}

	return 0;
}

// allocate space and store data
void initDate(shared_ptr<date> d, int mon, int day, int yr)
{
	if (!d)  throw("attemmpt to access invalid pointer"); 
	d->month = mon; 	// store data
	d->day = day;
	d->year = yr;
}

void displayDate(shared_ptr<date> d)
{
	if (!d)  throw("attemmpt to access invalid pointer");
	cout << d->month << '/' 
		<< d->day << '/'
		<< d->year << endl;
}


