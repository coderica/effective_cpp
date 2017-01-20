#include <iostream>
using namespace std;

const int MAX_SEQ = 10;
int main()
{
	int fibSeq[MAX_SEQ] = {0,1};
	for (int i = 2; i < MAX_SEQ; i++)
	{
		fibSeq[i] = fibSeq[i - 1] + fibSeq[i - 2];
	}

	for (int i = 0; i < MAX_SEQ; i++)
		cout << fibSeq[i] << " ";
	
	cout << endl;

	return 0;
}