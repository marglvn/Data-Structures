#include <iostream>
#include <list>

using namespace std;

//template <class T>
void list_insert(list<int>& scroll, int value, int position)	//	I kept messing this up so there
{																//	were a number of mistakes made
	list <int>::iterator iter;
	iter = scroll.begin();

	if (scroll.empty() || *iter > value)
	{
		//cout << "true" << endl;								//	testing the code for it to push
		scroll.push_front(value);								//	correctly and taking
	}
	if (value > *iter)
	{
		scroll.push_back(value);								//	strange bug is going on between
	}															//	here and the insertion when working
																//	larger numbers
	for (int i = 0; i <= position; i++)
	{
		if (*iter < value)
		{
			iter++;
		}
	}
	

	scroll.insert(iter, value);									//	inserts from iter
	cout << endl;
}

void listDisplay(list<int> scroll)
{
	list<int>::const_iterator iter;

	for (iter = scroll.begin(); iter != scroll.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;
}


int main()
{
	list<int> listing = {3, 5, 7, 11, 13};
	
	listDisplay(listing);

	list_insert(listing, 8, 8);

	listDisplay(listing);
}