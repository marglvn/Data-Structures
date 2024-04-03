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
		int numItems;

	public:

		PriorityQueue()
		{	
			head = nullptr;	
			numItems = 0;
		}

		void push(T item)
		{
			Node* newNode;
			Node* nodePtr;
			Node* previousNode = nullptr;

			newNode = new Node;
			newNode->value = item;
			newNode->next = nullptr;

			if (isEmpty())
			{	head = newNode;	}
			//else if (value > head->value)
			//{
			//	nodePtr = head;
			//	head = newNode;
			//	newNode->next = nodePtr;
			//}
			else
			{
				nodePtr = head;
				previousNode = nullptr;

				while (nodePtr != nullptr && nodePtr->value > item)
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

			numItems++;
		}

		void pop(T& item)
		{
			Node* nodePtr;

			if (isEmpty())
				cout << "The queue is empty.\n";
			else
			{
				item = head->value;

				nodePtr = head;
				head = head->next;
				delete nodePtr;
			}

			numItems--;
		}

		T top()
		{
			if (isEmpty())
				cout << "The queue is empty.\n";
			else
				return head->value;
		}

		bool isEmpty()
		{
			bool status;

			if (numItems > 0)
				status = false;
			else
				status = true;

			return status;
		}

		int size()
		{
			return numItems;
		}

};

int main()
{
	PriorityQueue<int> pq;
	int var;
	int count = 0;

	pq.push(5);
	pq.push(10);
	pq.push(3);
	pq.push(8);
	pq.push(12);
	pq.push(2);
	pq.push(15);
	pq.push(10232);
	pq.push(36);
	pq.push(51);
	pq.push(291);
	pq.push(383);
	pq.push(89);
	pq.push(94);
	pq.push(3873);

	count = pq.size();

	for (int i = 0; i < count; i++)
	{
		pq.pop(var);

		cout << var << " ";
	}
}