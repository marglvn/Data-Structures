//Program 18-6.cpp (Gaddis)
//This program has been modified by Cyril Harris

//This program demonstrates the STL stack
// container adapter.
#include <iostream>
#include <vector>
#include <stack>
#include <list>//Harris edit
using namespace std;

int main()
{
   const int MAX = 8;  // Max value to store in the stack
   int count;          // Loop counter
   
   // Define an STL stack
   stack< int, vector<int> > iStack;//this is a stack adapted from a vector

   //**********************
   //Harris edit->
   //You can also declare the the following types of Standard Template Library (STL) stacks:

   stack<int> iStack2;
     //This is a stack that is based off of a dequeue. Pronounced "deck".
	 //	A Dequeue is a double ended queue.  It can expand it's size from both the beginning and end of the data structure.

   stack<int, list<int>> iStack3;
     // This is a stack that is based off of a linked list.
   //**********************

   
   // Push values onto the stack.
   for (count = 2; count < MAX; count += 2)
   {
      cout << "Pushing " << count << endl;
      iStack.push(count);
   }
   
   // Display the size of the stack.
   cout << "The size of the stack is ";
   cout << iStack.size() << endl;
   
   // Pop the values of the stack.
   for (count = 2; count < MAX; count += 2)
   {
      cout << "Popping " << iStack.top() << endl;
      iStack.pop();
   }

   system ("pause");
   return 0;
}