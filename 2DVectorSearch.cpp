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
	vector<location> locations;
	int input;


	cout << "Enter a value you want to find: ";
	cin >> input;

	locations = searchVector(matrix, input);

	for (int i = 0; i < locations.size(); i++)
	{
		cout << locations[i].row << " " << locations[i].col << endl;
	}
}