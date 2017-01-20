#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>   // For ostringstream 
#include <Windows.h> // For OutputDebugString

bool testReversedString( char inputString[] )
{
	int reversedIx = strlen(inputString);
	char reversedString[200];
	for (size_t i = 0; i < strlen(inputString); i++)
	{
		reversedString[--reversedIx] = inputString[i];
	}
	
	// Where's the null terminator?
	// Here it is:
	// Let's look at the memory in the debugger via Debug|Windows|Memory, copy/paste reversedString into Address.
	reversedString[strlen(inputString)] = '\0';

	if (_stricmp(inputString, reversedString) == 0)
		return true;
	else
		return false;
}


#define MAX_INPUT_SIZE 256
#define ENABLE_LOGGING

#if defined(ENABLE_LOGGING)
	#define LOG_MSG_VAL(m,v) \
		{ \
			std::ostringstream msg; \
			msg << m << v << std::endl; \
			OutputDebugString(msg.str().c_str()); \
		}
#else
	#define LOG_MSG_VAL(m,v)
#endif

int main()
{
	{ // Divisor Problem #1: integer division vs. modulus operator.
		int number(10);
		int potentialDivisor(4);

		bool isDivisor = (number % potentialDivisor) == 0;

		// Perfectly valid. Worst case: Intent is unclear, may be slower than modulus operator.
		isDivisor = ((number / potentialDivisor)*potentialDivisor == number);
	}

	{ // Divisor Problem #2: Iterating up to value
		int value(10);
		int maxSearch = value / 2; // allow integer trunctation
		// or
		maxSearch = value >> 1; // This performs a 'right shift' of the bitpattern.

		std::vector<int> divisors;

		divisors.push_back(1);
		for (int i = 2; i <= maxSearch; i++)
		{
			if (value%i == 0)
			{
				divisors.push_back(i);
				LOG_MSG_VAL("Found divisor: ", i);
			}
		}
		divisors.push_back(value);
	}

	{ // Palindrome Problem Common error #1: missing string termination
		char inputString[] = "WasItACarOrACatISaw";

		// Common Error for Problem 2 (Palindome):
		if (testReversedString(inputString))
		{
			std::cout << "It's a palindrome";
		}
		else
		{
			std::cout << "It's not a palindrome";
		}
	}

	{ // Palindrome Problem Common error #2: Unnecessary -1 in getline. getline ALWAYS null terminates.
		char inputString[MAX_INPUT_SIZE];
		std::cin.getline(inputString, MAX_INPUT_SIZE - 1);
	}

	{ // Palindrome Problem Common error #3: When changing string to lower case manually (rather than via tolower), use of raw ascii codes:
		// Why? Code should be self-commenting when possible.

		char inputString[MAX_INPUT_SIZE];

		// ... code happens ...
		for (size_t i = 0; i < strlen(inputString); i++)
		{
/*
			if (inputString[i] > 64 && inputString[i] < 91)
			{
				inputString[i] = inputString[i] + 32;
			}
*/
			if (inputString[i] >= 'A' && inputString[i] <= 'Z')
			{
				inputString[i] = inputString[i] + 32; // Or even 'a'-'A', or a comment.
			}
		}
	}

	{ // Palindrome Problem/MinMax Word Common error #4: calling strlen for each loop iteration:
		char inputString[MAX_INPUT_SIZE];

		size_t strSize = strlen(inputString);
		for (size_t i = 0; i < strSize; i++)
		{
			// ... code happens
		}
	}
}