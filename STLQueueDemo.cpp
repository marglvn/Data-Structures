//Written by: Cyril Harris
//Queues access elements in a First In First Out Manner.
#include <queue>
#include <iostream>

using namespace std;

int main()
{
	int item, num_of_items, count;
	queue<int> q;
	cout << "How many items do you want to input?" << endl;
	cin >> num_of_items;
	for (count = 0; count < num_of_items; count++)
	{
		cout << "Enter an item" << endl;
		cin >> item;
		q.push(item);
	}

	cout << "There are " << q.size() << " items in the queue " << endl;
	while (!q.empty())
	{
		cout << q.front() << endl;
		//cout<<q.back()<<endl;//uncomment this line and compare it to the line above
		q.pop();
	}
	cout << endl;
	system("pause");
}