#include <iostream>

using namespace std;

template <class T>
class Stack
{
	private:
		
		T* stackArray;
		int stackSize;
		int top;

	public:

		Stack(int size)
		{
			stackArray = new T[size];
			stackSize = size;
			top = -1;
		}

		Stack(const Stack& obj)
		{
			if (obj.stackSize > 0)
				stackArray = new int[obj.stackSize];
			else
				stackArray = nullptr;

			stackSize = obj.stackSize;

			for (int count = 0; count < stackSize; count++)
				stackArray[count] = obj.stackArray[count];

			top = obj.top;
		}

		~Stack()
		{
			delete[] stackArray;
		}

		void push(T num)
		{
			if (isFull())
			{
				cout << "The stack is full.\n";
			}
			else
			{
				top++;
				stackArray[top] = num;
			}
		}

		void pop(T& num)
		{
			if (isEmpty())
			{
				cout << "The stack is empty.\n";
			}
			else
			{
				num = stackArray[top];
				top--;
			}
		}

		bool isFull() const
		{
			bool status;

			if (top == stackSize - 1)
				status = true;
			else
				status = false;

			return status;
		}

		bool isEmpty() const
		{
			bool status;

			if (top == -1)
				status = true;
			else
				status = false;

			return status;
		}
};

int main()
{
	Stack<int> stack(5);

	for (int i = 5; i < 30; i += 5)
	{
		cout << "Pushing...\n" << i << endl;
		stack.push(i);
	}
	cout << endl;

	while (!stack.isEmpty())
	{
		cout << "Popping..." << endl;
		int catchVar;
		stack.pop(catchVar);
		cout << catchVar << endl << endl;;
	}
}