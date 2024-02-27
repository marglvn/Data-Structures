#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
	private:

		//	Declare a structure for the list
		struct ListNode
		{
			T value;				//	The value in this node
			struct ListNode* next;	//	To point to the next node
		};

		ListNode* head;				//	List head pointer

	public:

		//	Constructor
		LinkedList()
		{
			head = nullptr;
		}

		//	Linked list Operations
		void appendNode(T newValue)
		{
			ListNode* newNode;	//	To point to a new node
			ListNode* nodePtr;	//	To move through the list

			//	Allocate a new mode and store newValue there
			newNode = new ListNode;
			newNode->value = newValue;
			newNode->next = nullptr;

			//	If there are no nodes in the list
			//	make newNode the first node.
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
		void displayList() const
		{
			ListNode* nodePtr;

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
	LinkedList<double> list;

	list.appendNode(1.41);
	list.appendNode(2.71);
	list.appendNode(3.14);

	list.displayList();

	return 0;
}