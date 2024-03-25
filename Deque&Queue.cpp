#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main()
{
	const int MAX = 8;
	int count;

	deque<int> idque;
	queue<int> que;

	cout << "Enqueuing STL deque container items...\n";
	for (count = 2; count < MAX; count += 2)
	{
		cout << "Pushing " << count << endl;
		idque.push_back(count);
	}

	cout << "Dequeuing STL deque container items...\n";
	for (count = 2; count < MAX; count += 2)
	{
		cout << "Popping " << idque.front() << endl;
		idque.pop_front();
	}

	cout << endl;

	cout << "Enqueuing STL queue container items...\n";
	for (count = 2; count < MAX; count += 2)
	{
		cout << "Pushing " << count << endl;
		que.push(count);
	}

	cout << "Dequeuing STL queue container items...\n";
	for (count = 2; count < MAX; count += 2)
	{
		cout << "Popping " << que.front() << endl;
		que.pop();
	}
}