#include <iostream>

using namespace std;

template <class T>
class DynQueue
{
	private:

		struct QueueNode
		{
			T value;
			struct QueueNode* next;
		};

		QueueNode* front;
		QueueNode* rear;
		int numItems;

	public:

		DynQueue()
		{
			front = nullptr;
			rear = nullptr;
			numItems = 0;
		}

		~DynQueue()
		{	clear();	}

		void enqueue(T num)
		{
			QueueNode* newNode;

			newNode = new QueueNode;
			newNode->value = num;
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

		void dequeue(T& num)
		{
			QueueNode* temp = nullptr;

			if (isEmpty())
			{
				cout << "The queue is empty.\n";
			}
			else
			{
				num = front->value;

				temp = front;
				front = temp->next;
				delete temp;

				numItems--;
			}
		}

		bool isEmpty() const
		{
			bool status;

			if (numItems > 0)
				status = false;
			else
				status = true;

			return status;
		}
		
		void clear()
		{
			int value;

			while (!isEmpty())
			{
				dequeue(value);
			}
		}
};

int main()
{
	const int MAX_VALUES = 5;

	DynQueue<int> ique;

	cout << "Enqueuing " << MAX_VALUES << " items...\n";

	for (int x = 0; x < 5; x++)
	{
		ique.enqueue(x);
	}

	cout << "Tha values in the queue were:\n";

	while (!ique.isEmpty())
	{
		int value;
		ique.dequeue(value);
		cout << value << endl;
	}
}