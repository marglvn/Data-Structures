#include <iostream>
#include <string>

using namespace std;
int numChars(char, string, int);

int main()
{
	string str = "aaaabbbbbbcccddddeef";
	char choice = 'c';

	cout << "The letter " << choice << " appears " << numChars(choice, str, 0) << " times.\n";
}

int numChars(char search, string str, int subscript)
{
	if (subscript >= str.length())
		return 0;												// Base case: The end of the string is reached.


	else if (str[subscript] == search)
		return 1 + numChars(search, str, subscript + 1);		// Recursive case: A matching character was found.
																// Return 1 plus the number of times the search
																// character appears in the rest of the string.
	else
		return numChars(search, str, subscript + 1);			// Recursive case: A character that does not match the
																// search character was found. Return the number of times
																// the search character appears in the rest of the string.
}