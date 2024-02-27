#include <iostream>
#include <fstream>
//#include <string>
#include <list>

using namespace std;

template <class T>
struct Values
{
	T value1;
	T value2;
	T value3;
	T value4;
};

int main()
{
	ifstream inputFile;
	string name;
	list<string> array;
	list<string>::iterator itr;

	inputFile.open("C:\\Users\\Martin\\Desktop\\Data.csv");

	string column1;
	string column2;
	string column3;
	string column4;

	while (inputFile.good())
	{
		getline(inputFile, column1, ",");
		getline(inputFile, column2, ",");
		getline(inputFile, column3, ",");
		getline(inputFile, column4, "\n");

		cout << column1 << " " << column2 << " " << column3 << " " << column4 << endl;

	}

	cout << "Reading data from the file.\n\n";

	
	inputFile.close();
	
	return 0;
}