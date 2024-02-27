//Vector size access timer
//Written by: Cyril Harris
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//*************************************************************************
//*************************************************************************
//*************************************************************************
//*************************************************************************

int main()
{
	unsigned int size = 200000;
	clock_t begin, end;
	vector<int> numbers;
	unsigned int i = 0;
	double elapsed_secs;
	cout << "clock_t demo" << endl;
	begin = clock();
	do
	{
		i++;
		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	} while (elapsed_secs < 5);
	cout << "5 seconds elapsed" << endl;
	cout << endl << endl;
	for (i = 0; i < size; i++)//Build Vector
		numbers.push_back(i);
	//Compute size2 time ->
	begin = clock();
	unsigned int size2 = numbers.size();
	for (i = 0; i < size2; i++)
	{
	}
	cout << endl;
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Elapsed Time using size2 = " << elapsed_secs << endl;
	//Compute numbers.size() time ->
	begin = clock();
	for (i = 0; i < numbers.size(); i++)
	{
	}
	cout << endl;
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Elapsed Time using numbers.size() = " << elapsed_secs <<
		endl;
	system("pause");
	return 0;
}
