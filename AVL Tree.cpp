/*
AVL Tree
Original Source = https://www.geeksforgeeks.org/implementation-of-avl-
tree-using-graphics-in-cpp/
tree-using-graphics-in-cpp/
Edited by: Cyril Harris
The GeeksForGeeks code was editted.
Modifications made by Cyril Harris:
1. avlTree destructor added
2. avl_node is defined in the avlTree class
3. avlTree class definitions are all inline (instead of using the ::
operator)
4. The following header files are not used:
#include <algorithm>
#include <bits/stdc++.h>
#include <graphics.h>
#include <sstream>
5. The data in the avlTree is of type float, not of type int.
checkInput(string str) ensures that the data is of type float (not
int).
6. * root, *temp1; are encapsulated in the avlTree class
7. Display_Menu was added to the avlTree class
8. Try Catch blocks for Exception Handling
9. Removed height member from avl_node definition
10. Removed *temp1
11. Changed avl_node* avlTree::insert(avl_node* root, int value) to
avl_node* insert(avl_node* nodePtr, float value)
*/
#include <iostream>
#include <string>
using namespace std;
class avlTree
{
private:
	// Node Declaration
	struct avl_node
	{
		float data;
		avl_node* left;
		avl_node* right;
	};
public:
	avl_node* root;
	avlTree()
	{
		root = nullptr;
	}
	int height(avl_node* temp)
	{
		int h = 0;
		if (temp != nullptr)
		{
			int l_height = height(temp->left);
			int r_height = height(temp->right);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}
		return h;
	}
	int diff(avl_node* temp)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int b_factor = l_height - r_height;
		return b_factor;
	}
	avl_node* rr_rotation(avl_node* parent)
	{
		avl_node* temp;
		temp = parent->right;
		parent->right = temp->left;
		temp->left = parent;
		return temp;
	}
	avl_node* ll_rotation(avl_node* parent)
	{
		avl_node* temp;
		temp = parent->left;
		parent->left = temp->right;
		temp->right = parent;
		return temp;
	}
	avl_node* lr_rotation(avl_node* parent)
	{
		avl_node* temp;
		temp = parent->left;
		parent->left = rr_rotation(temp);
		return ll_rotation(parent);
	}
	avl_node* rl_rotation(avl_node* parent)
	{
		avl_node* temp;
		temp = parent->right;
		parent->right = ll_rotation(temp);
		return rr_rotation(parent);
	}
	avl_node* insert(avl_node* nodePtr, float value)
	{
		if (nodePtr == nullptr)
		{
			nodePtr = new avl_node;
			nodePtr->data = value;
			nodePtr->left = nullptr;
			nodePtr->right = nullptr;
			return balance(nodePtr); // Apply balancing after insertion
		}
		if (value < nodePtr->data)
		{
			nodePtr->left = insert(nodePtr->left, value);
		}
		else if (value > nodePtr->data)
		{
			nodePtr->right = insert(nodePtr->right,
				value);
		}
		else
		{
			cout << "\n Value already"
				<< " exists!" << endl;
		}
		return balance(nodePtr); // Apply balancing after insertion
	}
	avl_node* balanceTree(avl_node* nodePtr)
	{
		if (nodePtr == nullptr)
		{
			return nullptr;
		}
		nodePtr->left = balanceTree(nodePtr->left);
		nodePtr->right = balanceTree(nodePtr->right);
		return balance(nodePtr); // Apply balancing to the entire tree
	}
	avl_node* balance(avl_node* temp)
	{
		int bal_factor = diff(temp);
		if (bal_factor > 1)
		{
			if (diff(temp->left) > 0)
			{
				temp = ll_rotation(temp);
			}
			else {
				temp = lr_rotation(temp);
			}
		}
		else if (bal_factor < -1)
		{
			if (diff(temp->right) > 0)
			{
				temp = rl_rotation(temp);
			}
			else
			{
				temp = rr_rotation(temp);
			}
		}
		return temp;
	}
	void display(avl_node* ptr, int level)
	{
		int i;
		if (ptr != nullptr)
		{
			display(ptr->right, level + 1);
			cout << endl;
			if (ptr == root)
				cout << "Root -> ";
			for (i = 0; i < level && ptr != root; i++)
			{
				cout << " ";
			}
			cout << ptr->data;
			display(ptr->left, level + 1);
		}
	}
	void inorder(avl_node* nodePtr)
	{
		if (nodePtr == nullptr)
			return;
		inorder(nodePtr->left);
		cout << nodePtr->data << " ";
		inorder(nodePtr->right);
	}
	void preorder(avl_node* nodePtr)
	{
		if (nodePtr == nullptr)
			return;
		cout << nodePtr->data << " ";
		preorder(nodePtr->left);
		preorder(nodePtr->right);
	}
	void postorder(avl_node* nodePtr)
	{
		if (nodePtr == nullptr)
			return;
		postorder(nodePtr->left);
		postorder(nodePtr->right);
		cout << nodePtr->data << " ";
	}
	bool validate(string str)//Validate that str is a floating point number
	{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if ((str[i] != '.' && !isdigit(str[i])) && (i != 0 || str[i] != '-'))
			return false;
	}
		return true;
	}
		~avlTree()
	{
		destroyTree(root);
	}
	void clear()
	{
		destroyTree(root);
		root = nullptr;
	}
	void destroyTree(avl_node* node)
	{
		if (node != nullptr)
		{
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}
	void Display_Menu()
	{
		cout << endl;
		cout << "---------------------" << endl;
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.PreOrder traversal" << endl;
		cout << "3.InOrder traversal" << endl;
		cout << "4.PostOrder traversal" << endl;
		cout << "5.Clear Tree" << endl; // Added option to clear the tree
		cout << "6.Exit" << endl;
		cout << "---------------------" << endl;
	}
	bool validateMenuItemInput(string input)
	{
		try
		{
			int choice = stoi(input);
			return choice >= 1 && choice <= 6;
		}
		catch (const invalid_argument& e)
		{
			return false;
		}
	}
	bool validateFloatInput(string input)
	{
		try
		{
			stof(input);
			return true;
		}
		catch (const invalid_argument& e)
		{
			return false;
		}
	}
};
int main()
{
	cout << "---------------------" << endl;
	cout << "AVL Tree" << endl;
	cout << "---------------------" << endl;
	avlTree avl;
	while (true)
	{
		avl.Display_Menu();
		string input;
		cout << endl;
		cout << "Enter your Choice: ";
		cin >> input;
		if (avl.validateMenuItemInput(input))
		{
			int choice = stoi(input);
			if (choice == 1)
			{
				string str;
				cout << "Enter the value to be inserted: ";
					cin >> str;
				if (avl.validateFloatInput(str))
				{
					float item = stof(str);
					avl.root =
						avl.insert(avl.root, item);
					cout << "Tree after insertion: ";
						avl.inorder(avl.root);
					cout << endl;
				}
				else
				{
					cout << endl << "Invalid Input!" << endl;
				}
			}
			else if (choice == 2)
			{
				cout << "Preorder Traversal: ";
				avl.preorder(avl.root);
				cout << endl;
			}
			else if (choice == 3)
			{
				cout << "Inorder Traversal:" << endl;
				avl.inorder(avl.root);
				cout << endl;
			}
			else if (choice == 4)
			{
				cout << "Postorder Traversal:" << endl;
				avl.postorder(avl.root);
				cout << endl;
			}
			else if (choice == 5)
			{
				avl.clear();
				cout << "Tree cleared." << endl;
			}
			else if (choice == 6)
			{
				exit(0);
			}
		}
		else
		{
			cout << "Invalid Choice! Please enter a valid	menu option(1 - 6)." << endl;
		}
	}
	return 0;
}