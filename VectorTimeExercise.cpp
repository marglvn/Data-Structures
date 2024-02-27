#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	unsigned int i = 0, iteration;														//i and iterations being initialized as unsigned integers
	unsigned int num_of_iterations = 50;												//number of iterations being initialzed as 50 --  why 50 though?
	clock_t begin, end;																	//the objects clock_t begin and end being brought in
	double elapsed_seconds;																//will be calculated later as a double
	const int size = 100000;															//a finalized integer named size set to 100,000
	
	cout << "Testing Vector" << endl;

	vector<int> nums(size);																//creates a vector to the final size of 100,000

	begin = clock();																	//starts the count

	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (i = 0; i < size; i++)
		{
			nums[i];
		}
	}

	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << elapsed_seconds << " seconds" << endl;
	return 0;
}