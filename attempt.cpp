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
			cout << s[row][col] << " ";
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

void categorize(vector<vector<string>>& v, string i)
{
	unsigned int row, col, size;
	unsigned int num_of_rows = v.size();
	string hilo;

	for (row = 0; row < num_of_rows; row++)
	{
		size = v[row].size();
		for (col = 0; col < size; col++)
		{
			hilo = v[row][col];
			if (hilo.substr(0, 4) == i)
			{
				cout << v[row][col] << " " << v[row][col + 1];
			}
		}
		cout << endl;
	}
}

void displayL(vector<location>& l)
{
	if (l.size() == 0)
	{
		return;
	}

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
	vector<vector<string>> values;
	vector<location> locations;
	string fileName, input, les;

	cout << "Please enter the input file name: ";
	getline(cin, fileName);
	cout << endl;
	file.open(fileName.c_str());

	if (file.is_open())
	{
		intake(values, file);
		//displayV(values);
		cout << endl;

		//cout << "Please enter what you are searching for: ";
		//getline(cin, input);

		cout << endl;

		//categorize(values, input);

		//coords(values, locations, input);

		//displayL(locations);

		cout << "Classes: ";
		getline(cin, les);

		categorize(values, les);
	}
	else
	{
		cout << "Error. File not found" << endl;
	}

}