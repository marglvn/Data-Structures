#include <iostream>
#include <string>

using namespace std;

void function(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)	//	'\0' is the null terminator in a c string
	{
		cout << str[i] << " * ";
	}
}

void insertfunction(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'e')
		{
			str.insert(str.begin() + i + 1, '3');
			//i--;
		}
		else
			cout << str[i];
	}
}

int main()
{
	string line = "Lone Star College";
	const char* cline = line.c_str();
	//function(cline);

	insertfunction(line);
}