#include <iostream>
using namespace std;

struct date {
	int month; 
	int day; 
	int year;
};

date *makeDate(int, int, int);
void displayDate(date *);

int main()
{
	date *christmas, *newYears;
	christmas = makeDate(12, 25, 2016);
	newYears = makeDate(1, 1, 2016);
	displayDate(christmas);
	displayDate(newYears);
	delete christmas; 
	delete newYears;
	return 0;
}

// allocate space and store data
date *makeDate(int mon, int day, int yr)
{
	date *temp = new date;  // allocate space
	if (!temp)			    // request granted?
	{
		cout << "Memory allocation error\n";
		exit(-1);
	}
	temp->month = mon; 	// store data
	temp->day = day;
	temp->year = yr;
	return temp;		//return pointer
}

void displayDate(date *d)
{
	cout << d->month << '/' 
		<< d->day << '/'
		<< d->year << endl;
}


