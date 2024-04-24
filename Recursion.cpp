#include <iostream>

using namespace std;

int factorial(int n)
{
	if (n == 0)
		return 1; // Base case
	else
		return n * factorial(n − 1); // Recursive case
}

int fib(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + (n - 2);
}

void message(int times)
{
	cout << "message called with " << times << " in times.\n";

	if (times > 0)
	{
		cout << "This is a recursive function.\n";
		message(times - 1);
	}

	cout << "message returning with " << times << " in times.\n";
}

int main()
{
	message(5);
	cout << factorial(5) << endl;


}