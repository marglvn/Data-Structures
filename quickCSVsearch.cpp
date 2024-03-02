#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	fstream inputFile;
	string fileName, data;
	//vector<vector<string>> copiedValues;
	//vector<vector<string>> column;

	cout << "Please enter the input file name: ";
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	cout << endl;

	if (!inputFile.is_open())
	{
		cout << "File can not be found" << endl;
	}

	
	while (getline(inputFile, data))	//	2nd iteration. Capable of printing to the console without saving values yet.
	{									//	Assumption is correct with newline and the row of the values.
		cout << data << endl;
	}
	


	inputFile.close();

	return 0;

}