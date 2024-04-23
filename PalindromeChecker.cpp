#include <iostream>

using namespace std;

bool function(const string& s, int start, int end)
{
	if (start >= end)
		return true;
	
	if (s[start] != s[end])
		return false;

	return function(s, start + 1, end - 1);
}

int main()
{
	string input;
	bool result;
	int size;
	string endResult;
	
	cout << "Enter word to check if it's a palindrome: \n";
	cin >> input;
	
	size = input.size();

	result = function(input, 0, size - 1);
	if (result == true)
		endResult = "true";
	else
		endResult = "false";
	

	cout << endResult << endl;
}