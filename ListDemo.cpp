//STL list Demo
//Written by: Cyril Harris

#include <iostream>
#include <list>
#include <string>
using namespace std;

void Output_List(const list<int>& lst, string s)
{
	cout << s << " = ";
	list<int>::const_iterator i;	//	since lst is const(read only), the iterator that accesses it must also be const, const_iterator.
		for (i = lst.begin(); i != lst.end(); i++)
			cout << *i << ' ';
	cout << endl;
}

//**************************************************************************

int main()
{
	int j;
	list<int>::iterator i1;
	list<int>::iterator i2;
	list<int> lst1;
	list <list<int>> lst2;	//	2D linked list


	Output_List(lst1, "lst1"); // lst1 is empty


	list<int> lst3(4, 2);
	Output_List(lst3, "lst3"); // lst3 = (2 2 2 2)


	for (j = 1; j <= 5; j++)
		lst1.push_back(j);
	Output_List(lst1, "lst1"); // lst1 = (1 2 3 4 5)


	lst1.pop_back();
	Output_List(lst1, "lst1"); // lst1 = (1 2 3 4)


	lst1.push_front(0);
	Output_List(lst1, "lst1"); // lst1 = (0 1 2 3 4)

	//******************************************************************************
	//lst1.insert(lst1.begin() + 1, 3);	//	This would be allowed if lst1 was a vector
	i1 = lst1.begin();
	i1++;
	lst1.insert(i1, 333);
	Output_List(lst1, "lst1"); // lst1 = (0 333 1 2 3 4)


	//******************************************************************************
	//lst1.erase(lst1.end() - 1);	//	This would be allowed if lst1 was a vector
	i2 = lst1.end();
	i2--;
	lst1.erase(i2);
	Output_List(lst1, "lst1"); // lst1 = (0 333 1 2 3)


	//******************************************************************************
	lst1.clear();
	Output_List(lst1, "lst1");
	//******************************************************************************


	list<int> lst4 = { 80,90,100 };
	list<int>::reverse_iterator it;
	cout << "lst4 reversed is: ";
	for (it = lst4.rbegin(); it != lst4.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}