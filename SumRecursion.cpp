/*
Write a function that accepts as arguments :
1. An array of integers
2. The number of elements in the array

The function needs to recursively calculate the sum of all of the numbers in
the array.

Demonstrate that the function works in a driver program.
_________________
Example :
If the contents of the array is : { 2, 4, 6, 8 } .
Then the recursive function will return 20.

20 will be outputted to the Console Screen
*/

#include <iostream>

using namespace std;

int function(int* arr, int size)
{
	if (size == 1)
		return arr[0];
	else
		return arr[size - 1] + function(arr, size - 1);
}

int main()
{
	int elements = 4;
	int* values = new int[elements];

	for (int i = 1; i < elements + 1; i++)
	{
		values[i - 1] = i * 2;
	}

	int num = function(values, elements);

	cout << num << endl;
}