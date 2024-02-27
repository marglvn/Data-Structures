#include <iostream>																		//allows the use of console out and in
#include <fstream>																		//don't know what this does
#include <ctime>																		//to bring clock object -- #include <time.h> can do the same thing

using namespace std;

int main()
{
	unsigned int i = 0, iteration;														//i and iterations being initialized as unsigned integers
	unsigned int num_of_iterations = 50;												//number of iterations being initialzed as 50 --  why 50 though?
	clock_t begin, end;																	//the objects clock_t begin and end being brought in
	double elapsed_seconds;																//will be calculated later as a double
	const int size = 100000;															//a finalized integer named size set to 100,000

/******************************************************************************************************************************/

	cout << "Testing Array" << endl;													//Just spitting out to the console what's going to happen
	int numbers[size];																	//initializes array to size -- this is the array that will be tested for the timer
	begin = clock();																	//time stamps the start count
	for (iteration = 0; iteration < num_of_iterations; iteration++)						//cycles through starting at 0, cycles through the interior loop, going up to 50
	{
		for (i = 0; i < size; i++)														//cycles through the array going from 0 to 100,000
		{
			numbers[i];
		}
	}
																						//for loops cycle through 5,000,000 times? -- (50 x 100,000)
	end = clock();																		//time stamps the end count

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;					//CLOCK_PER_SEC is brought in along with <ctime> -- end result calculates time elapsed
	cout << elapsed_seconds << " seconds" << endl;										//spits out result to the console

	//Just wanted to spit these out to console to understand what they are but I get the gist
	//obvi the next 3 cout lines can be commented out honestly

	cout << end << endl;																// will display either 11 or 10 -- unit is in milliseconds
	cout << begin << endl;																// displays 0
	cout << CLOCKS_PER_SEC << endl;														// const of 1000 to divide the numbers and change the units into seconds from milliseconds
	return 0;
}

/*
	The end result spits out 

	Testing Array
	0.01

	Is the 0.01 in seconds?



*/