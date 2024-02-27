#include <iostream>	//	for console in/out
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

class LinkedList
{
	private:

		//	Declare a structure for the nodes
		struct Node
		{
			double value;
			struct Node* next;
		};

		Node* head;

	public:

		//	Constructor
		LinkedList()
		{	head = nullptr;	}

		//	LinkedList Operators
		void appendNode(double);
		void deleteNode(double);
		void displayList() const;
};

void LinkedList::appendNode(double num)
{
	Node* newNode;	//	to hold the value of the number
	Node* nodePtr;	//	to move through the list

	//	Allocate the value onto the node
	newNode = new Node;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
	{	head = newNode;	}
	else
	{
		//	Initialize nodePtr to the head of list
		nodePtr = head;

		//	Find the last node in the list
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		//	Insert new Node as the last node
		nodePtr->next = newNode;
	}
}

void LinkedList::deleteNode(double num)
{
	Node* nodePtr;					//	to traverse the list
	Node* previousNode = nullptr;	//	to point to the previous node

	//	If the list is empty, do nothing
	if (!head)
	{	return;	}

	auto start = chrono::high_resolution_clock::now();						//	I thought this was ridiculous

	//	Determine if the first node is the one
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != num)
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

	auto end = chrono::high_resolution_clock::now();						//	but honestly

	chrono::duration<float> duration = end - start;						//	worth it

	cout << setprecision(9) << (duration.count() / CLOCKS_PER_SEC) << " seconds" << endl;
}

void LinkedList::displayList() const
{
	Node* nodePtr;	//	to move through the list

	//	Position node pointer to the head of the list
	nodePtr = head;

	//	While nodePtr points to a node, traverse
	//	the list
	while (nodePtr)
	{
		//	Display the value in this node
		cout << nodePtr->value << endl;

		//	Move to the next node
		nodePtr = nodePtr->next;
	}
}

int main()
{
	LinkedList list;

	//unsigned int i = 0, iteration;
	//unsigned int num_of_iterations;
	//clock_t begin, end;
	//double elapsed_time;
	//const int size = 100000;

	
	list.appendNode(1.41);
	list.appendNode(2.71);
	list.appendNode(3.14);

	list.displayList();
	cout << endl;

	//begin = clock();
	list.deleteNode(2.71);
	//end = clock();

	list.displayList();

	cout << endl;

	//elapsed_time = double(end - begin) / CLOCKS_PER_SEC;

	//cout << elapsed_time << endl;
	//cout << end << endl;
	//cout << begin << endl;
}