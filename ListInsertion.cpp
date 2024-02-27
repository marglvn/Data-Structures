#include <iostream>
#include <list>

using namespace std;

template <class T>
void listInsertion(list<T>& v, int index, T value)
{
	list<int>::iterator iter;

	if (index >= 0 && index <= v.size())
	{
		iter = v.begin();
		advance(iter, index);
		v.insert(iter, value);
	}
	else
	{
		cout << "Invalid index" << endl;
	}
}

int main()
{
	list<int> numberList;
	list<int>::iterator iter;
	int input;
	int index;

	for (int i = 0; i < 9; i++)
	{
		numberList.push_back(i);
	}

	cout << "Enter value to be inserted: ";
	cin >> input;

	cout << "Enter the index of the value: ";
	cin >> index;

	cout << endl;

	listInsertion(numberList, index, input);

	for (iter = numberList.begin(); iter != numberList.end(); iter++)
	{
		cout << *iter << " ";
	}
}