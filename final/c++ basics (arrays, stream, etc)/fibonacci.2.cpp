#include <iostream>
using namespace std;

const int MAX_SEQ = 30;
int main()
{
	int start, howMany;
	int fibSeq[MAX_SEQ] = { 0,1 };

	cout << "Position to start at: ";  cin >> start;
	while (start < 1 || start > 10)
	{
		cout << "start position must be between 1 and 10- please answer again: ";  
		cin >> start;
	}

	cout << "How many to display: ";  cin >> howMany;
	while (howMany < 1 || howMany > 20)
	{
		cout << "Up to 20 items allowed - please answer again: ";
		cin >> howMany;
	}

	for (int i = 2; i < MAX_SEQ; i++)
	{
		fibSeq[i] = fibSeq[i - 1] + fibSeq[i - 2];
	}

	for (int i = start-1, n = 1; n <= howMany; i++, n++)
		cout << fibSeq[i] << " ";

	cout << endl;

	return 0;
}