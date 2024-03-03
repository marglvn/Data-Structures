#include <iostream>

using namespace std;

int main()
{
	const int size = 8;
	int box[size] = {2, 4, 6, 8, 10, 12, 14, 16};

	for (int i = 0; i < size; i++)
	{
		cout << box[i] << endl;
	}
}