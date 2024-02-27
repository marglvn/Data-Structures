#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

template <class T>	//	creates template LinkedList
class LinkedList
{
	private:
		struct Node
		{
			T value;
			struct Node* next;
		};

		Node* head;

	public:
		LinkedList()
		{	head = nullptr;	}

		void appendNode(T newValue)
		{
			Node* newNode;
			Node* nodePtr;

			newNode = new Node;
			newNode->value = newValue;
			newNode->next = nullptr;

			if (!head)
			{
				head = newNode;
			}
			else
			{
				nodePtr = head;

				while (nodePtr->next)
				{
					nodePtr = nodePtr->next;
				}

				nodePtr->next = newNode;
			}
		}

		void deleteNode(T deleteValue)
		{
			Node* nodePtr;
			Node* previousNode = nullptr;

			if (!head)
			{
				return;
			}
			if (head->value == deleteValue)
			{
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			else
			{
				nodePtr = head;

				while (nodePtr != nullptr && nodePtr->value != deleteValue)
				{
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}

				if (nodePtr)
				{
					previousNode->next = nodePtr->next;
					delete nodePtr;
				}
			}
		}

		void displayList() const
		{
			Node* nodePtr;

			nodePtr = head;

			while (nodePtr)
			{
				cout << nodePtr->value << endl;

				nodePtr = nodePtr->next;
			}
		}

};


int main()
{
	clock_t begin, end;	//	clock objects begin and end
	unsigned int iteration;
	unsigned int num_of_iterations = 50000;
	double elapsed_seconds;
	const int SIZE = 50000;

	vector<int> numbers;	//	initializes a vector of integers named numbers

	for (int i = 0; i < SIZE; i++)	//	stores values from 0 to 7500 onto vector
	{
		numbers.push_back(i);
	}

	begin = clock();	//	begins the count; normally this is going to be clocked at 0
	for (iteration = 0; iteration < num_of_iterations; iteration++)	//	amount of times it runs the inner for loop
	{
		for (int i = 0; i < numbers.size(); i++)	//	begins deleting values from vector
		{
			numbers.erase(numbers.begin() + i);
		}
	}
	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;

	cout << "Vector deletion time is: " << elapsed_seconds << " seconds" << endl;


//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888//


	LinkedList<int> numbs;

	for (int i = 0; i < SIZE; i++)
	{
		numbs.appendNode(i);
	}

	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		numbs.deleteNode(iteration);
	}
	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;

	cout << "Linked List deletion time is: " << elapsed_seconds << " seconds" << endl;


//8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888//


	list<int>::iterator iter;

	list<int> nummys;

	for (int i = 0; i < SIZE; i++)
	{
		nummys.push_back(i);
	}

	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (auto iter = nummys.begin(); iter != nummys.end(); )
		{
			iter = nummys.erase(iter);
		}
	}
	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;

	cout << "STL List deletion time is: " << elapsed_seconds << " seconds" << endl;
}