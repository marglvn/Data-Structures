#include <iostream>

using namespace std;

clock_t begin, end;
double estimated_time;
//const int size = 100000;

class NumberList
{
	private:
		struct ListNode
		{
			double value;
			struct ListNode* next;
		};

		ListNode* head;

	public:
		//Constructor
		NumberList()
		{
			head = nullptr;
		}
	
		//Destructor
		//~NumberList();

		//LinkedList Operations
		void appendNode(double);
		//void insertNode(double);
		void deleteNode(double);
		void displayList() const;
};

/************************************************

	Create a new node
	Store data in the new node
	If there are no nodes in the list
		Make the new node the first node
	Else
		Traverse the list to find the last node
		Add the new node to the end of the list
	End If

*************************************************/

void NumberList::appendNode(double num)
{
	ListNode* newNode;							//To point to a new node
	ListNode* nodePtr;							//To move through the list

	//	Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	//	If there are no nodes in the list
	//	make newNode the first node
	if (!head)
	{
		head = newNode;
	}
	else //	Otherwise, insert newNode at end
	{
		//	Initialize nodePtr to head of list
		nodePtr = head;

		//	Find the last node in the list
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		//	Insert newNode as the last node
		nodePtr->next = newNode;
	}
	
}

/*************************************************

	Assign List head to node pointer
	While node pointer is not null
		Display the value member of the node pointed to by node pointer
		Assign node pointer to its own next member
	End While

*************************************************/

void NumberList::displayList() const
{
	ListNode* nodePtr;	//	To move through the list

	//	Position nodePtr at the head of the list
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

	cout << endl;
}

void NumberList::deleteNode(double num)
{

	clock_t begin, end;
	double estimated_time;

	ListNode* nodePtr;		//	To traverse the list
	ListNode* previousNode = nullptr;	//	To point to the previous node

	//	start timing the deletion
	begin = clock();

	//	If the list is empty, do nothing
	if (!head)
	{
		return;
	}
	else
	{
		//	Initialize nodePtr to head of list
		nodePtr = head;

		//	Determine if the first node is the one
		if (head->value == num)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			//	Initialize nodePtr to head of list
			nodePtr = head;

			//	Skip all nodes whose value member is
			//	not equal to num
			while (nodePtr != nullptr && nodePtr->value != num)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			//	If nodePtr is not at the end of the list,
			//	link the previous node to the node after
			//	nodePtr, the delete nodePtr.
			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}

	end = clock();
	estimated_time = (double(end) - double(begin)) / CLOCKS_PER_SEC;

	cout << estimated_time << endl;
}

int main()
{

	//	Define a NumberList object
	NumberList list;

	//	Append some values to the list
	list.appendNode(1.41);	//	Root 2 = 1.414
	list.appendNode(1.62);	//	Golden Ratio = 1.618
	list.appendNode(2.71);	//	Euler's number = 2.71
	list.appendNode(3.14);	//	Pi

	//	Display the list
	list.displayList();

	list.deleteNode(1.62);
	
	list.displayList();

	return 0;
}
