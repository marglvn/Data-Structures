#include <iostream>

using namespace std;

template <class T>
class Queue
{
	private:

		T* queueArray;
		int queueSize;
		int front;
		int rear;
		int numItems;

	public:

		Queue(int s)
		{
			queueArray = new T[s];
			queueSize = s;
			front = -1;
			rear = -1;
			numItems = 0;
		}
	
		Queue(const Queue& obj)
		{
			queueArray = new T[obj.queueSize];

			queueSize = obj.queueSize;
			front = obj.front;
			rear = obj.rear;
			numItems = obj.numItems;
	
			for (int count = 0; count < obj.queueSize; count++)
			{
				queueArray[count] = obj.queueArray[count];
			}
		}

		~Queue()
		{
			delete[] queueArray;
		}

		void enqueue(T value)
		{
			if (isFull())
			{
				cout << "The queue is full.\n";
			}
			else
			{
				//	Calculate the new rear position
				rear = (rear + 1) % queueSize;

				queueArray[rear] = value;

				numItems++;
			}
		}

		void dequeue(T& value)
		{
			if (isEmpty())
			{
				cout << "The queue is empty.\n";
			}
			else
			{
				front = (front + 1) % queueSize;

				value = queueArray[front];

				numItems--;
			}
		}

		bool isEmpty() const
		{
			bool status;

			if (numItems)
			{
				status = false;
			}
			else
				status = true;

			return status;
		}

		bool isFull() const
		{
			bool status;

			if (numItems < queueSize)
			{
				status = false;
			}
			else
				status = true;

			return status;
		}

		void clear()
		{
			front = queueSize - 1;
			rear = queueSize - 1;
			numItems = 0;
		}

};

int main()
{
	const int MAX_VALUES = 5;

	Queue<int> que(MAX_VALUES);

	for (int i = 0; i < MAX_VALUES; i++)
	{
		que.enqueue(i);
	}

	que.enqueue(MAX_VALUES);

	cout << "The values in the queue were: \n";

	while (!que.isEmpty())
	{
		int value;
		que.dequeue(value);
		cout << value << endl;
	}
}