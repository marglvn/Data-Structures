#include <iostream>
#include <vector>

using namespace std;

struct location
{
	int row, col;
};

vector<location> searchVector(vector<vector<int>>& v, int item)
{
	location L;
	vector<location> locations;

	unsigned int row, col, size;
	unsigned int num_of_rows = v.size();

	for (row = 0; row < num_of_rows; row++)
	{
		size = v[row].size();
		for (col = 0; col < size; col++)
		{
			if (v[row][col] == item)
			{
				L.row = row;
				L.col = col;
				locations.push_back(L);
			}
		}
	}

	if (locations.size() == 0)
	{
		L.row = -1;
		locations.push_back(L);
	}

	return locations;
}

int main()
{
	vector<vector<int>> matrix{ {8, 3, 2}, {7, 1, 3, 8, 8, 8} };
	//vector<vector<int>>::iterator itr1;
	//vector<int>::iterator itr2;
	vector<location> coords;
	vector<location>::iterator iterator;
	int input;

	
	cout << "Enter a value you want to find: ";
	cin >> input;
	
	coords = searchVector(matrix, input);

	for (int i = 0; i < coords.size(); i++)
	{
		const location coord = coords[i];
		cout << coord.row << " " << coord.col << endl;
	}

	//	To display values
	/*
	for (itr1 = matrix.begin(); itr1 != matrix.end(); itr1++)
	{
		for (itr2 = itr1->begin(); itr2 != itr1->end(); itr2++)
		{
			cout << " " << *itr2;
		}
		cout << endl;
	}
	*/

	
	
}