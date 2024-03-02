#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct location
{
	string row, col;
};

int main()
{
	fstream inputFile;
	string fileName, data;
	cout << "Please enter the input file name: ";
	getline(cin, fileName);
	inputFile.open(fileName.c_str());

	if (!inputFile.is_open())
	{
		cout << "File can not be found" << endl;
	}
	
	while (getline(inputFile, data))
	{
		cout << data << endl;;
	}

	inputFile.close();

	return 0;

}