#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<vector<T>> searchVector(vector<vector<T>>& v, T item)
{
	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == item)
			{
				cout << i << " " << j << endl;
				
				found = true;
			}
		}
	}

	if (!found)
	{
		cout << "Item is not found in the vector" << endl;
	}

	return v;
}

int main()
{
	vector<vector<float>> matrix{ {8, 3, 2}, {7, 1, 3, 8, 8, 8} };
	float input;


	for (auto i : matrix)
	{
		for (auto j : i)
		{
			cout << " " << j;
		}
		cout << endl;
	}

	cout << "Enter: ";
	cin >> input;

	searchVector(matrix, input);
}