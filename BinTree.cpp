#include <iostream>

using namespace std;

template <class T>
class BinaryTree
{
	private:

		struct TreeNode
		{
			T value;
			struct TreeNode* left;
			struct TreeNode* right;
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

		void displayInOrder(TreeNode* nodePtr) const
		{
			if (nodePtr)
			{
				displayInOrder(nodePtr->left);
				cout << nodePtr->value << endl;
				displayInOrder(nodePtr->right);
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

		void displayInOrder() const
		{	displayInOrder(root);	}
};

int main()
{
	BinaryTree<int> tree;

	tree.insertNode(15);
	tree.insertNode(5);
	tree.insertNode(20);
	tree.insertNode(25);
	tree.insertNode(10);

	tree.displayInOrder();
}