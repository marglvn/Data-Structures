#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>

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
T** transfer(vector<vector<T>>& v)
{
	size_t row = v.size();
	T** jagged = new T* [row];

	for (size_t i = 0; i < row; i++)
	{
		size_t col = v[i].size();
		jagged[i] = new T[col];
		for (size_t j = 0; j < col; j++)
		{
			jagged[i][j] = v[i][j];
		}
	}

	return jagged;
}

template <class T>
void display(T** a, vector<vector<T>>& v)
{
	size_t c, r = v.size();
	for (size_t i = 0; i < r; i++)
	{
		c = v[i].size();
		for (size_t j = 0; j < c; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

template <class T>
void displayVector(vector<vector<T>>& v)
{
	unsigned int row, col, size;
	unsigned int numRows = v.size();

	for (row = 0; row < numRows; row++)
	{
		size = v[row].size();
		for (col = 0; col < size; col++)
		{
			cout << v[row][col] << " ";
		}
		cout << endl;
	}
}

int main()
{
	clock_t begin0, begin1, end0, end1;
	unsigned int iteration, num_of_iterations = 50;
	unsigned int itr, num_of_itrs = 50;
	double elapsed_seconds0, elapsed_seconds1;
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

	string** array = transfer(values);

	begin0 = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (itr = 0; itr < num_of_itrs; itr++)
		{
			display(array, values);
		}
	}
	end0 = clock();

	//elapsed_seconds0 = double(end - begin) / CLOCKS_PER_SEC;

	//cout << "Time elapsed: " << elapsed_seconds0 << " seconds" << endl;

/*************************************************************************************************/

	begin1 = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (itr = 0; itr < num_of_itrs; itr++)
		{
			displayVector(values);
		}
	}
	end1 = clock();

	elapsed_seconds0 = double(end0 - begin0) / CLOCKS_PER_SEC;
	elapsed_seconds1 = double(end1 - begin1) / CLOCKS_PER_SEC;

	cout << "Array display time elapsed: " << elapsed_seconds0 << " seconds" << endl;
	cout << "Vector display time elapsed: " << elapsed_seconds1 << " seconds" << endl;
}