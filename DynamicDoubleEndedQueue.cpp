#include <iostream>

using namespace std;

template<class T>
class DynamicQueue
{
	private:

		struct QueueNode
		{
			T value;
			QueueNode* next;
		};

		QueueNode* front;
		QueueNode* rear;
		int numItems;

	public:

		DynamicQueue()
		{
			front = nullptr;
			rear = nullptr;
			numItems = 0;
		}

		void push_back(T item)
		{
			QueueNode* newNode;

			newNode = new QueueNode;
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

		template<class T>
		void push_front(T item)
		{
			QueueNode* newNode;
			QueueNode* nodePtr;

			newNode = new QueueNode;
			newNode->value = item;
			newNode->next = nullptr;

			if (isEmpty())
			{
				front = newNode;
				rear = newNode;
			}
			else
			{
				nodePtr = front;
				front = newNode;
				newNode->next = nodePtr;
			}

			numItems++;
		}

		template <class T>
		void dequeue(T& item)
		{
			QueueNode* temp = nullptr;

			if (isEmpty())
				cout << "The queue is empty.\n";
			else
			{
				item = front->value;

				temp = front;
				front = front->next;
				delete temp;

				numItems--;
			}
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
	DynamicQueue<int> que;
	int count = 0;
	int var;

	que.push_front(5);
	que.push_front(8);
	que.push_back(10);
	que.push_back(15);
	que.push_front(22);
	que.push_back(3);

	count = que.size();
	cout << count << endl;

	for (int i = 0; i < count; i++)
	{
		que.dequeue(var);
		cout << var << " ";
	}
	cout << endl;

	cout << count << endl;

}