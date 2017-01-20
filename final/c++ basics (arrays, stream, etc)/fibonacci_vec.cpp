#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "How many to display: ";  cin >> howMany;
	while (howMany < 1 || howMany > 20)sll
	{
		cout << "Up to 20 items allowed - please answer again: ";
		cin >> howMany;
	}

	for (int i = 2; i < start + howMany -1 ; i++)
	{
		fibSeq.push_back(fibSeq[i - 1] + fibSeq[i - 2]);
	}

	for (int i = start-1, n = 1; n <= howMany; i++, n++)
		cout << fibSeq[i] << " ";

	cout << endl;

	return 0;
}