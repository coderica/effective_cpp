#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(0));				//seed the pseudo-random number generator
	int r = rand() % 10 + 1;	//rand() produces a number from 0 to RAND_MAX (at least, 32,767)
}