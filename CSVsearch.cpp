#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct location
{
	int row, col;
};

void intake(vector<vector<string>>& c, fstream& f)
{
	string line;

	while (getline(f, line))
	{
		stringstream stream(line);
		string cell;
		vector<string> row;

		while (getline(stream, cell, ','))
		{
			row.push_back(cell);
		}
		c.push_back(row);
	}
}

int main()
{
	fstream file;
	string fileName;

	vector<vector<string>> values;

	cout << "Please enter the input file name: ";
	getline(cin, fileName);
	cout << endl;
	file.open(fileName.c_str());

	if (!file.is_open())
	{
		cout << "Error. File not found" << endl;
	}
	
	intake(values, file);


}