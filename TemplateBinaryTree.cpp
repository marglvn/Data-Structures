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
			//root;
			if (nodePtr)
			{
				displayInOrder(nodePtr->left);		//					[2]
				cout << nodePtr->value << " ";		//				   /   \				//
				displayInOrder(nodePtr->right);		//				[1]     [3]
			}
		}

		void displayPreOrder(TreeNode* nodePtr) const
		{
			if (nodePtr)
			{
				cout << nodePtr->value << " ";		//					[1]
				displayPreOrder(nodePtr->left);		//				   /
				displayPreOrder(nodePtr->right);	//				[2]-----[3]
			}
		}

		void displayPostOrder(TreeNode* nodePtr) const
		{
			if (nodePtr)
			{
				displayPostOrder(nodePtr->left);	//					[3]
				displayPostOrder(nodePtr->right);	//						\				//
				cout << nodePtr->value << " ";		//				[1]-----[2]
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
		{
			displayInOrder(root);
			cout << endl;
		}

		void displayPreOrder() const
		{
			displayPreOrder(root);
			cout << endl;
		}

		void displayPostOrder() const
		{
			displayPostOrder(root);
			cout << endl;
		}


};

int main()
{
	BinaryTree<int> arbol;

	arbol.insertNode(50);
	arbol.insertNode(25);
	arbol.insertNode(100);
	arbol.insertNode(10);
	arbol.insertNode(200);
	arbol.insertNode(300);
	

	cout << "Displaying InOrder:\n";
	arbol.displayInOrder();
	cout << endl;
	cout << "Displaying PreOrder:\n";
	arbol.displayPreOrder();
	cout << endl;
	cout << "Displaying PostOrder:\n";
	arbol.displayPostOrder();
	cout << endl;

	arbol.remove(15);
	arbol.displayInOrder();

	
}