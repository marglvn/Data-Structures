#include <iostream>
#include <vector>

using namespace std;

template <class T>
T** transfer(vector<vector<T>>& m, T& row, T& col)	//	I have no idea what's going on here, just that it's returning a double pointer of type T
{
	T** temp = new T * [row];	//	or here but temp is of double point type T creating a new pointer of type T with an array the size of row

	for (int i = 0; i < row; i++)
	{
		temp[i] = new T[col];	//	can't even begin to comprehend what's going on here
		for (int j = 0; j < col; j++)
		{
			temp[i][j] = m[i][j];	//	copying the contents from the vector to the array
		}
	}
	return temp;
}

template <class T>
void display(T** a, T& row, T& col)	// looks suprisingly normal for a dynamic array to be printed
{
	cout << "Printing array" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Array printed";
}

int main()
{
	vector<vector<int>> matrix{ {8, 3, 2}, {2, 8, 1}, {7, 1, 3} };
	int row = matrix.size();
	int col = matrix[0].size();
	int** array = transfer(matrix, row, col);

	display(array, row, col);
}