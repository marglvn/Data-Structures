#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Int2Excel
{
	public:
		string convertToTitle(int n)
		{
			string r = "";
			while (n > 0)
			{
				r = (char)(65 + (n - 1) % 26) + r;
				n = (n - 1) / 26;
			}
			return r;
		}
};

struct location
{
	int row;
	string col;
};

void feedValue(fstream& inputFile, vector<vector<string>>& c)
{
	vector<vector<string>> column;
	string line;

	while (getline(inputFile, line))
	{
		stringstream stream(line);
		string cell;
		vector<string> row;


		while (getline(stream, cell, ','))
		{
			row.push_back(cell);
		}
		column.push_back(row);

	}

	c = column;
}

void display(vector<vector<string>>& v)
{
	unsigned int row, col, size;
	unsigned int num_of_rows = v.size();

	for (row = 0; row < num_of_rows; row++)
	{
		size = v[row].size();
		for (col = 0; col < size; col++)
		{
			cout << v[row][col] << ", ";
		}
		cout << endl;
	}
}

void acquireCoords(vector<vector<string>>& v, vector<location>& l)
{
	Int2Excel convert;
	location L;
	vector<location> locations;

	unsigned int row, col, size;
	unsigned int num_of_rows = v.size();

	for (row = 0; row < num_of_rows; row++)
	{
		size = v[row].size();
		for (col = 0; col < size; col++)
		{
			L.row = row + 1;
			L.col = convert.convertToTitle(col + 1);
			locations.push_back(L);
		}
	}

	l = locations;
}

void displayCoords(vector<location>& l)
{
	for (int i = 0; i < l.size(); i++)
	{
		cout << l[i].row << " " << l[i].col << endl;
	}
}

int main()
{
	fstream inputFile;
	string fileName;
	vector<vector<string>> copiedValues;
	vector<location> locations;
	//vector<vector<string>> column;

	cout << "Please enter the input file name: ";
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	cout << endl;

	if (!inputFile.is_open())
	{
		cout << "File can not be found" << endl;
	}
	
	feedValue(inputFile, copiedValues);

	acquireCoords(copiedValues, locations);

	display(copiedValues);

	displayCoords(locations);


	/*
	while (getline(inputFile, data))	//	3rd Iteration. Beginning to save files to a vector
	{									//	However, don't know if they're saving correctly, and
		string cell;					//	still need to display them.
		vector<string> row;				//	Decide to make it a function of its own.

		while (getline(inputFile, cell, ','))
		{
			row.push_back(cell);
		}
		column.push_back(row);

	}
	*/

	/*
	while (getline(inputFile, data))	//	2nd iteration. Capable of printing to the console without saving values yet.
	{									//	Assumption is correct with newline and the row of the values.
		//vector<string> row;	//	Disregard, but you can see the hamster wheel is starting to spin.
		cout << data << endl;
	}
	*/

	/*
	else	//	1st iteration. Making sure the file is opening correctly and registers as such.
	{
		cout << "Done" << endl;
	}
	*/

	inputFile.close();

	return 0;

}