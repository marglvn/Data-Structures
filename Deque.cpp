#include <iostream>

using namespace std;

template <class T>
class Deque
{
	private:

		struct Node
		{
			T value;
			Node* next;
		};

		Node* front;
		Node* rear;
		int numItems;

	public:

		Deque()
		{
			front = nullptr;
			rear = nullptr;
			numItems = 0;
		}

		void push_back(T item)
		{
			Node* newNode;
			newNode = new Node;

			newNode->value = item;
			newNode->next = nullptr;

			if (isEmpty())
			{
				front = newNode;
				rear = newNode;
			}
			else
			{
				rear->next = newNode;
				rear = newNode;
			}

			numItems++;
		}

		void push_front(T item)
		{
			Node* newNode;
			Node* temp;

			newNode = new Node;
			newNode->value = item;
			newNode->next = nullptr;

			if (isEmpty())
			{
				front = newNode;
				rear = newNode;
			}
			else
			{
				temp = front;
				front = newNode;
				newNode->next = temp;
			}

			numItems++;
		}

		void dequeue(T& item)
		{
			Node* temp;

			if (isEmpty())
				cout << "The queue is empty.\n";
			else
			{
				item = front->value;

				temp = front;
				front = front->next;
				delete temp;
			}

			numItems--;
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
	Deque<int> dq;
	int count;
	int var;

	dq.push_front(5);
	dq.push_back(10);
	dq.push_front(15);
	dq.push_back(20);
	dq.push_front(25);
	dq.push_back(30);

	count = dq.size();

	for (int i = 0; i < count; i++)
	{
		dq.dequeue(var);

		cout << var << " ";
	}
}