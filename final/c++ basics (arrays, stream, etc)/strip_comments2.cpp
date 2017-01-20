/*  Strip commented text out of a line of code 
 *     comments start with  slash *
 *     and end with * slash
 *     Assumption: we do not have to deal with an end comment
 *	   on a line without a previous starting comment
 */

#include <iostream>
#include <string> 
using namespace std;

int main()
 {
	string line, lineCopy;
	int startIndex, endIndex;
	
	getline(cin, line);

	startIndex = line.find("/*");
	if (startIndex < 0)
		lineCopy = line;
	else
	{
		endIndex = line.find("*/", startIndex);
		lineCopy = line.substr(0, startIndex);
		if (endIndex > 0)
			lineCopy += line.substr(endIndex + 2, line.size());
	}

	cout << lineCopy << endl;

	return 0;
 }