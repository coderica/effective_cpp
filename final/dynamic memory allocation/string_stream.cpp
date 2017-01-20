#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string sentence = "Look at all these words";
	string word;
	vector<string> words;
	istringstream s(sentence);
	while (!s.eof())
	{
		s >> word;
		words.push_back(word);
	}
	for (size_t i = 0; i < words.size(); i++)
		cout << words.at(i) << endl;
	return 0;
}