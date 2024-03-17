#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void intake(vector<vector<string>>& v, fstream& f)
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
		v.push_back(row);
	}
}

template <class T>
T** transfer(vector<vector<T>>& v, size_t r, size_t c)
{
	T** temp = new T* [r];

	for (size_t i = 0; i < r; i++)
	{
		temp[i] = new T[c];
		for (size_t j = 0; j < c; j++)
		{
			temp[i][j] = v[i][j];
		}
	}

	return temp;
}

template <class T>
void display(T** a, size_t r, size_t c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<string>> values;
	
	string fileName;
	fstream file;

	cout << "Enter file you want to access: ";
	getline(cin, fileName);

	file.open(fileName.c_str());

	if (file.is_open())
	{
		intake(values, file);
	}
	else
	{
		cout << "Error. File not found." << endl;
	}
	cout << endl;

	size_t row = values.size();
	size_t col = values[0].size();

	string** array = transfer(values, row, col);

	display(array, row, col);
}