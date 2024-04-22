#include <iostream>

using namespace std;

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
}