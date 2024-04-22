#include <iostream>

using namespace std;

int function(int*& arr, int size)
{
	if (size == 1)
		return arr[0];
	else
		return arr[size - 1] + function(arr, size - 1);
}

int main()
{
	int elements = 4;
	int* arr = new int[elements];

	for (int i = 1; i < elements + 1; i++)
	{
		arr[i - 1] = i * 2;
	}

	for (int i = 0; i < elements; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int num = function(arr, elements);

	cout << num << endl;
}