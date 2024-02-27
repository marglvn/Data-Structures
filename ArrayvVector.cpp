#include<iostream>
#include<vector>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{
	unsigned int i = 0, iteration;
	unsigned int num_of_iterations = 50;
	clock_t begin, end;
	double elapsed_seconds;
	const int size = 100000;

	//**********************************************

	cout << "Testing Array" << endl;
	int numbers[size];
	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (i = 0; i < size; i++)
			numbers[i];
	}
	end = clock();
	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;

	//**********************************************

	cout << endl << endl;
	cout << "Testing Vector" << endl;
	vector <int> numbers2(size);
	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (i = 0; i < size; i++)
			numbers2[i];
	}
	end = clock();
	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << endl;
	return 0;
}