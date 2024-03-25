#include <iostream>

using namespace std;

template <class T>
class BinaryTree
{
	private:
		struct TreeNode
		{
			T value;
			TreeNode* left;
			TreeNode* right;
		};

		TreeNode* root;

		void insert(TreeNode*& nodePtr, TreeNode*& newNode)
		{
			if (nodePtr == nullptr)
				nodePtr = newNode;
			else if (newNode->value < nodePtr->value)
				insert(nodePtr->left, newNode);
			else
				insert(nodePtr->right, newNode);
		}

		void deleteNode(T index, TreeNode*& nodePtr)
		{
			if (index < nodePtr->value)
				deleteNode(index, nodePtr->left);
			else if (index > nodePtr->value)
				deleteNode(index, nodePtr->right);
			else
				makeDeletion(nodePtr);
		}

		void makeDeletion(TreeNode*& nodePtr)
		{
			TreeNode* tempNodePtr = nullptr;

			if (nodePtr == nullptr)
			{
				cout << "Cannot delete empty node.\n";
			}
			else if (nodePtr->right == nullptr)
			{
				tempNodePtr = nodePtr;
				nodePtr = nodePtr->left;
				delete tempNodePtr;
			}
			else if (nodePtr->left == nullptr)
			{
				tempNodePtr = nodePtr;
				nodePtr = nodePtr->right;
				delete tempNodePtr;
			}
			else
			{
				tempNodePtr = nodePtr->right;

				while (tempNodePtr->left)
					tempNodePtr = tempNodePtr->left;

				tempNodePtr->left = nodePtr->left;

				tempNodePtr = nodePtr;

				nodePtr = nodePtr->right;

				delete tempNodePtr;
			}
		}

		void displayInOrder(TreeNode* nodePtr) const
		{
			if (nodePtr)
			{
				displayInOrder(nodePtr->left);
				cout << nodePtr->value << endl;
				displayInOrder(nodePtr->right);
			}
		}

		void displayPreOrder(TreeNode* nodePtr) const
		{
			if (nodePtr)
			{
				cout << nodePtr->value << endl;
				displayPreOrder(nodePtr->left);
				displayPreOrder(nodePtr->right);
			}
		}

		void displayPostOrder(TreeNode* nodePtr) const
		{
			if (nodePtr)
			{
				displayPostOrder(nodePtr->left);
				displayPostOrder(nodePtr->right);
				cout << nodePtr->value << endl;
			}
		}

	public:

		BinaryTree()
		{	root = nullptr;	}

		void insertNode(T index)
		{
			TreeNode* newNode;

			newNode = new TreeNode;
			newNode->value = index;
			newNode->left = newNode->right = nullptr;

			insert(root, newNode);
		}

		void remove(T index)
		{
			deleteNode(index, root);
		}

		void displayInOrder() const
		{	displayInOrder(root);	}

		void displayPreOrder() const
		{	displayPreOrder(root);	}

		void displayPostOrder() const
		{	displayPostOrder(root);	}


};

int main()
{
	BinaryTree<int> arbol;

	arbol.insertNode(5);
	arbol.insertNode(10);
	arbol.insertNode(15);
	arbol.insertNode(20);
	arbol.insertNode(25);

	arbol.displayInOrder();
	cout << endl;
	arbol.displayPreOrder();
	cout << endl;
	arbol.displayPostOrder();
	cout << endl;

	arbol.remove(15);
	arbol.displayInOrder();

	
}