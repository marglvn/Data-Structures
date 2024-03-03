#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Solution
{
	public:
		string convert(int n)
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

void displayV(vector<vector<string>>& s)
{
	unsigned int row, col, size;
	unsigned int num_of_rows = s.size();

	for (row = 0; row < num_of_rows; row++)
	{
		size = s[row].size();
		for (col = 0; col < size; col++)
		{
			cout << s[row][col] << ", ";
		}
		cout << endl;
	}
}

void coords(vector<vector<string>>& v, vector<location>& l, string i)
{
	location L;
	Solution title;
	unsigned int row, col, size;
	unsigned int num_of_rows = v.size();

	for (row = 0; row < num_of_rows; row++)
	{
		size = v[row].size();
		for (col = 0; col < size; col++)
		{
			if (v[row][col] == i)
			{
				L.row = row + 1;
				L.col = title.convert(col + 1);
				l.push_back(L);
			}
		}
	}

	if (l.size() == 0)
	{
		cout << "This file did not contain the item that you searched for." << endl;

	}
}

void displayL(vector<location>& l)
{
	cout << "The item that you searched for can be\n";
	cout << "found at the following location(s) ->" << endl;

	for (int i = 0; i < l.size(); i++)
	{
		cout << l[i].row << " " << l[i].col << endl;
	}
}

int main()
{
	fstream file;
	string fileName;
	vector<vector<string>> values;
	vector<location> locations;
	string input, data;

	cout << "Please enter the input file name: ";
	getline(cin, fileName);
	cout << endl;
	file.open(fileName.c_str());

	if (!file.is_open())
	{
		cout << "Error. File not found" << endl;
	}
	
	intake(values, file);
	displayV(values);
	cout << endl;
	
	cout << "Please enter what you are searching for: ";
	getline(cin, input);

	cout << endl;

	coords(values, locations, input);

	displayL(locations);

}