#include <iostream>

using namespace std;

template <class T>
class PriorityQueue
{
	private:

		struct Node
		{
			T value;
			Node* next;
		};

		Node* head;

	public:

		PriorityQueue()
		{
			head = nullptr;
			numItems = 0;
		}

		void push_back(T item)
		{
			Node* newNode;
			Node* nodePtr;
			Node* prevoiusNode = nullptr;

			newNode = new Node;
			newNode->value = item;
			newNode->next = nullptr;

			if (isEmpty())
			{	head = nullptr;	}
			else
			{
				nodePtr = head;
				previousNode = nullptr;
				
				while (nodePtr != nullptr && nodePtr = > value > item)
				{
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}
				if (previousNode == nullptr)
				{
					head = newNode;
					newNode->next = nodePtr;
				}
				else
				{
					previousNode->next = newNode;
					newNode->next = nodePtr;
				}
			}
		}
};

int main()
{

}