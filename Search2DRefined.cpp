#include <iostream>
#include <vector>

using namespace std;

struct location
{
	int row, col;
};

vector<location> search(vector<vector<int>>& v, int item)
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
		L.col = -1;
		locations.push_back(L);
	}

	return locations;
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
	vector<vector<int>> matrix{ {8, 3, 2}, {2, 8, 1}, {7, 1, 3} };
	vector<location> locations;
	int input;

	cout << "Enter a value to find: ";
	cin >> input;
	cout << endl;

	locations = search(matrix, input);

	displayCoords(locations);
}