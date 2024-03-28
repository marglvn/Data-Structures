#include <iostream>

using namespace std;

template<class T>
class DynStack
{
	private:

		struct StackNode
		{
			T value;
			StackNode* next;
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

		void push(T index)
		{
			StackNode* newNode;

			newNode = new StackNode;
			newNode->value = index;

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

		void pop(T& index)
		{
			StackNode* temp = nullptr;

			if (isEmpty())
			{
				cout << "The stack is empty.\n";
			}
			else
			{
				index = top->value;
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
	DynStack<int> plates;
	int catchVar;

	plates.push(5);
	plates.pop(catchVar);

	cout << catchVar << endl;
}