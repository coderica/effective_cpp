#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	/*******problem 1: divisors *************/

	// limit input value to 2,000
	int divisors[2000] = {1};		//one divisor is always 1
	int number, i, j;

	do {							// get the number
		cout << "enter number (up to 2000): ";
		cin >> number;
	} while (number > 2000);

	divisors[1] = number;			//other divisor is always the number itself
									//starting with 2, find all divisors 
									//until number we are checking is greater
									//than last divisor
									//alternately, could loop until i > square root
									//sqrt(number)
	for ( i=2, j=2; i < divisors[j-1] ; i++)
	{
		if (number % i == 0)
		{
			divisors[j++] = i;		//store divisor
			divisors[j++] = number / i;  // find its counterpart
		}
	}
	
	for (int i = 0; i < j; i++)		// display
		cout << divisors[i] << " ";

	cout << endl;

	/*********** problem 2 - palindrome **********/

	cin.get();  // get newline left in buffer 
	char string1[80] = {}, string2[80] = {};   
	i = 0; j = 0;
	bool pal = true;					// assume true until proven false

	cout << "enter some text (all lower case): ";   //get the string
	cin.getline(string1, 80);
	
	while (string1[i]) //copy string stripping out everything other than a - z
	{
		if (string1[i] >= 'a' && string1[i] <= 'z')
			string2[j++] = string1[i];
		i++;
	}
	string2[j] = 0;

	i = strlen(string2)-1; j = 0;  //initialize two indexes to start and end of the string
	while (i > j)				   //compare all values from outside to inside
	{
		if (string2[i--] != string1[j++])   //any missed compares?  
		{									//it is not a palindrome - no need to continue
			pal = false;
			break;
		}
	}
	
	cout << "it is " << (pal?"":"not ") << "a palindrome\n";

	/*********** problem 3 - words **********/
	vector<string> words;					//storage for the words
	string word, longest, shortest;
	do {									//get the words - use escape char \" to display a quote
		cout << "enter word - \"stop\" to stop: ";
		cin >> word;
		words.push_back(word);				//store each in the vector
											//note - could have used a conditional to avoid storing "stop"
	} while (word != "stop");				//stop if word is "stop"
	words.pop_back();						//remove last item ("stop")
	if (words.empty())						//account for empty vector
		cout << "no words entered!\n";
	else
	{
		longest = shortest = words[0];		//set longest and shortest to first word in vector
		for (i = 1; i < words.size(); i++)  //start at index 1 (already accounted for 0)
		{
			if (words[i].size() < shortest.size())	//replace shortest with a shorter word
				shortest = words[i];
			if (words[i].size() > longest.size())	//replace longest with a longer word
				longest = words[i];
		}
		cout << "longest word is " << longest << " and shortest word is " << shortest << endl;
	}
	return 0;
}