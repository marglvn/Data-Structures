#include <iostream>
#include <ctime>
#include <vector>
#include <list>

using namespace std;

template <class T>
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
			{	head = newNode;	}
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

		void deleteNode(T searchValue)
		{
			Node* nodePtr;
			Node* previousNode = nullptr;

			if (!head)
			{	return;	}
			if (head->value == searchValue)
			{
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			else
			{
				nodePtr = head;

				while (nodePtr != nullptr && nodePtr->value != searchValue)
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
	unsigned int iteration;
	unsigned int num_of_iterations = 50000;
	clock_t begin, end;
	double elapsed_seconds;
	const int SIZE = 50000;


//		88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888		//


	vector<int> numberList;

	for (int i = 0; i < SIZE; i++)
	{
		numberList.push_back(i);
	}

	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (int i = 0; i < numberList.size(); i++)
		{
			numberList.erase(numberList.begin() + i);
		}
	}
	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << "Vector deletion time is: " << elapsed_seconds << " seconds." << endl;


//		88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888		//


	LinkedList<int> listing;

	for (int i = 0; i < SIZE; i++)
	{
		listing.appendNode(i);
	}

	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			listing.deleteNode(i);
		}
	}
	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << "Linked List deletion time is: " << elapsed_seconds << " seconds." << endl;


//		88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888		//


	list<int> numbers;
	list<int>::iterator iter;

	for (int i = 0; i < SIZE; i++)
	{
		numbers.push_back(i);
	}

	begin = clock();
	for (iteration = 0; iteration < num_of_iterations; iteration++)
	{
		for (auto iter = numbers.begin(); iter != numbers.end(); )
		{
			iter = numbers.erase(iter);
		}
	}
	end = clock();

	elapsed_seconds = (double(end) - double(begin)) / CLOCKS_PER_SEC;
	cout << "List deletion time is: " << elapsed_seconds << " seconds." << endl;
}