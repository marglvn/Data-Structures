#pragma once
#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack
{
	private:
		int* stackArray; //	Pointer to the stack array
		int stackSize;	//	The stack size
		int top;

	public:
		//	Constructor
		IntStack(int);

		//	Copy Constructor
		IntStack(const IntStack&);

		//	Destructor
		~IntStack();

		//	Stack operations
		void push(int);
		void pop(int&);
		bool isFull() const;
		bool isEmpty() const;
};

#endif // !INTSTACK_H
