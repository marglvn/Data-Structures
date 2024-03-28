#include <iostream>

using namespace std;

class IntStack
{
	private:

		int* stackArray;
		int stackSize;
		int top;

	public:

		IntStack(int size)
		{
			stackArray = new int[size];
			stackSize = size;
			top = -1;
		}

		IntStack(const IntStack& obj)
		{
			if (obj.stackSize > 0)
				stackArray = new int[obj.stackSize];
			else
				stackArray = nullptr;

			stackSize = obj.stackSize;

			for (int count = 0; count < obj.stackSize; count++)
				stackArray[count] = obj.stackArray[count];

			top = obj.top;
		}

		~IntStack()
		{
			delete[] stackArray;
		}

		void push(int num)
		{
			if(isFull())
			{
				cout << "The stack is full.\n";
			}
			else
			{
				top++;
				stackArray[top] = num;
			}
		}

		void pop(int& num)
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

		bool isFull()
		{
			bool status;

			if (top == stackSize - 1)
				status = true;
			else
				status = false;

			return status;
		}

		bool isEmpty()
		{
			bool status;

			if (top == -1)
				status = true;
			else
				status = false;

			return status;
		}

};

class MathStack : public IntStack
{
	public:

		MathStack(int s) : IntStack(s) {}

		void add()
		{
			int num, sum;

			pop(sum);
			pop(num);

			sum += num;

			push(sum);
		}

		void product()
		{
			int num, mul;

			pop(mul);
			pop(num);

			mul *= num;

			push(mul);
		}

		void sub()
		{
			int num, diff;

			pop(diff);
			pop(num);

			diff -= num;

			push(diff);
		}

		void quotient()
		{
			int num, div;

			pop(div);
			pop(num);

			div /= num;

			push(div);
		}

		void addAll()
		{
			int num, sum = 0;

			if (isEmpty())
				cout << "The stack is empty." << endl;
			else
			{
				while (!isEmpty())
				{
					pop(num);
					sum += num;
				}
				push(sum);
			}
		}

		void multiplyAll()
		{
			int num, product = 1;

			if (isEmpty())
				cout << "The stack is empty." << endl;
			else
			{
				while (!isEmpty())
				{
					pop(num);
					product *= num;
				}
				push(product);
			}
		}

};

int main()
{
	int catchVar;

	MathStack stack(5);

	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);

	stack.add();
	cout << "The sum is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);

	stack.product();
	cout << "The product is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);

	stack.quotient();
	cout << "The quotient is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 7\n";
	stack.push(7);
	cout << "Pushing 10\n";
	stack.push(10);

	stack.sub();
	cout << "The difference is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 2\n";
	stack.push(2);
	

	stack.addAll();
	cout << "The sum of all values is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);

	stack.addAll();
	cout << "The sum of all values is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 1\n";
	stack.push(1);

	stack.multiplyAll();
	cout << "The product of all values is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;

/**************************************************************************************************************/

	cout << "Pushing 2\n";
	stack.push(2);
	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 4\n";
	stack.push(4);
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 6\n";
	stack.push(6);

	stack.multiplyAll();
	cout << "The product of all values is ";
	stack.pop(catchVar);

	cout << catchVar << endl << endl;
}