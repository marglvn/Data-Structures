#include <iostream>
#include <cmath>

using namespace std;

void calculate(int p, long long& num)
{
	num = (pow(2, p) - 1) * pow(2, (p - 1));	//	p = 2, 3, 5, 7, 13, 17, 19, 31, 67|, 127, 257
}

int main()
{
	int input;
	long long output;

	cout << "Enter what you want the power of 2 to be: ";
	cin >> input;

	calculate(input, output);

	cout << output << endl;
}