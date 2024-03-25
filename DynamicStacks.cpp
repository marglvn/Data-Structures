#include <iostream>

using namespace std;

template <class T>
class DynStack
{
	private:

		struct StackNode
		{
			T value;
			struct StackNode* next;
		};

		StackNode* top;

	public:

		DynStack()
		{	top = nullptr;	}

		~DynStack()
		{
			StackNode* nodePtr = nullptr, * nextNode = nullptr;
			nodePtr = top;

			while (nodePtr != nullptr)
			{
				nextNode = nodePtr->next;
				delete nodePtr;
				nodePtr = nextNode;
			}
		}

		void push(T num)
		{
			StackNode* newNode;

			newNode = new StackNode;
			newNode->value = num;

			if (isEmpty())
			{
				top = newNode;
				newNode->next = nullptr;
			}
			else
			{
				newNode->next = top;
				top = newNode;
			}
		}

		void pop(T& num)
		{
			StackNode* temp = nullptr;

			if (isEmpty())
			{
				cout << "The stack is empty.\n";
			}
			else
			{
				num = top->value;
				temp = top->next;
				delete top;
				top = temp;
			}
		}

		bool isEmpty()
		{
			bool status;

			if (!top)
				status = true;
			else
				status = false;

			return status;
		}
};

int main()
{
	DynStack<int> stack;

	for (int i = 5; i < 30; i += 5)
	{
		cout << "Pushing...\n" << i << endl;
		stack.push(i);
	}
	cout << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << "Popping...\n";
		int catchVar;
		stack.pop(catchVar);
		cout << catchVar << endl;
	}
}