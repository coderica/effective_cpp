#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;
enum colors {red, blue, green};
enum card_suits {diamonds, hearts, clubs, spades};

int main()
{
	unsigned int x;
	uint y;
	string suit_names[] = { "diamonds", "hearts", "clubs", "spades" };
	card_suits suit = hearts;
	cout << suit_names[suit] << endl;
	return 0;
}