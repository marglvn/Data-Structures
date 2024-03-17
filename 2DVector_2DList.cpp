#include <iostream>
#include <vector>
#include <list>
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
		vector<string> temp;

		while (getline(stream, cell, ','))
		{
			temp.push_back(cell);
		}
		v.push_back(temp);
	}
}

template <class T>
void transfer(vector<vector<T>>& v, list<list<T>>& c)
{
	unsigned int row, col, size;
	unsigned int num_of_rows = v.size();

	for (row = 0; row < num_of_rows; row++)
	{
		size = v[row].size();
		list<T> temp;
		for (col = 0; col < size; col++)
		{
			temp.push_back(v[row][col]);
		}
		c.push_back(temp);
	}
}

template <class T>
void display(list<list<T>>& c)
{
	typename list<list<T>>::iterator it;
	typename list<T>::iterator itr;

	for (it = c.begin(); it != c.end(); it++)
	{
		for (itr = it->begin(); itr != it->end(); itr++)
		{
			cout << *itr << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<string>> values;
	list<list<string>> copied;

	vector<vector<int>> matrix{ {2, 8, 1}, {7, 1, 3}, {8, 3, 2} };
	list<list<int>> copy;

	fstream file;
	string fileName, input;

	cout << "Enter file you want to copy onto a vector: ";
	getline(cin, fileName);

	file.open(fileName.c_str());

	if (file.is_open())
	{
		intake(values, file);
		transfer(values, copied);
		cout << endl;
		display(copied);
	}
	else
	{
		cout << "Error. File not found.";
	}

	transfer(matrix, copy);
	cout << endl;
	display(copy);
}