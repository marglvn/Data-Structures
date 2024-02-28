//	Implementation file for the IntStack class
#include <iostream>
#include "IntStack.h"

using namespace std;

//************************************************
//	Constructor									 *
//	This constructor creates an empty stack. The *
//	size parameter is the size of the stack		 *
//************************************************

IntStack::IntStack(int size)
{
	stackArray = new int[size];
	stackSize = size;
	top = -1;
}

//************************************************
//	Copy constructor							 *
//************************************************

IntStack::IntStack(const IntStack& obj)
{
	//	Create the stack array
	if (obj.stackSize > 0)
	{
		stackArray = new int[obj.stackSize];
	}
	else
	{
		stackArray = nullptr;
	}

	//	Copy the stackSize attribute
	stackSize = obj.stackSize;

	//	Copy the stack contents
	for (int count = 0; count < stackSize; count++)
		stackArray[count] = obj.stackArray[count];

	//	Set the top of the stack
	top = obj.top;
}

//
//
//