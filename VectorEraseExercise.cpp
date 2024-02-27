#include <iostream>
#include <vector>

using namespace std;

vector<int> eraseVector(vector<int> arr, int num)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == num)
		{
			arr.erase(arr.begin() + i);
		}
	}

	return arr;
}

void displayVector(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ", ";
	}

	cout << endl << endl;
}

int main()
{
	int input;
	vector<int> numbers = {2, 4, 8, 16, 32, 64, 128, 256, 512};

	cout << "Enter a number to delete from the vector: " << endl;
	cin >> input;
	cout << endl << endl;

	numbers = eraseVector(numbers, input);

	displayVector(numbers);
}