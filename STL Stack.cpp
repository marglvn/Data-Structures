#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	const int MAX = 8;
	int count;

	stack <int, vector<int>> plate;

	for (count = 2; count < MAX; count += 2)
	{
		cout << "Pushing... " << count << endl;
		plate.push(count);
	}

	cout << "The size of the stack is " << plate.size() << endl;

	for (count = 2; count < MAX; count += 2)
	{
		cout << "Popping... " << plate.top() << endl;
		plate.pop();
	}
}