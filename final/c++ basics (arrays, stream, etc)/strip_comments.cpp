/*  Strip commented text out of a line of code 
 *     comments start with  slash *
 *     and end with * slash
 *     Assumption: we do not have to deal with an end comment
 *	   on a line without a previous starting comment
 */

 #include <iostream>
 using namespace std;

 const int MAX = 80;

 int main()
 {
	char line[MAX], temp;
	char lineCopy[MAX] = {};
	bool inComment = false;
	
	cin.getline(line, MAX - 1);
	for (int i = 0, j=0; i < MAX && line[i]; i++)
	{
		if (!inComment)
		{
			if (i < MAX - 1 && line[i] == '/' && line[i + 1] == '*')
			{
				inComment = true;
				i++;
			}
			else
			{
				lineCopy[j++] = line[i];
			}
		}  // end not within comment
		else
		{
			if (i < MAX - 1 && line[i] == '*' && line[i + 1] == '/')
			{
				inComment = false;
				i++;
			}
		}
	}

	cout << lineCopy << endl;

	return 0;
 }