#include <iostream>
#include <set>

using namespace std;

void random(set<int>& n)
{
	for (int i = 0; i <= 1000; i++)
	{
		n.insert(2);
		n.insert(4);
		n.insert(6);
		n.insert(8);
		n.insert(10);
	}
}



int main()
{
	set<int> numbers;
	set<int>::iterator itr;

	random(numbers);

	for (itr = numbers.begin(); itr != numbers.end(); itr++)
	{
		cout << *itr << endl;
	}
}