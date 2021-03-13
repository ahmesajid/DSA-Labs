#include<iostream>
#include "BinarySearchTree.h"
using namespace std;
BST::BST() 
{
	root = nullptr;
}

BST::~BST()
{
	if (root != nullptr)
	{
		removeHelper(this->root);
	}
}

bool BST::empty()
{
	if (root == nullptr)
	{
		return true;
	}
	return false;
}
void BST::displayHelper(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << " ";
	displayHelper(node->left);
	displayHelper(node->right);
}
Node * BST::getParentHelper(Node * node, int child)
{
	Node * temp = nullptr;
	if ((node->left != nullptr && node->left->data == child) || (node->right != nullptr && node->right->data == child))
	{
		return node;
	}
	else if (node->left != nullptr)
	{
		temp = getParentHelper(node->left, child);
	}
	else if (node->right != nullptr && temp != nullptr)
	{
		temp = getParentHelper(node->right, child);
	}
	return temp;
}
void BST::setRoot(int x)
{
	root = new Node;
	root->data = x;
	root->left = root->right = nullptr;
}

int BST::getRoot()
{
	return root->data;
}
void BST::displayParenthesizedViewHelper(Node * node)
{
	if (node == nullptr)
	{
		cout << "_)";
		return;
	}
	cout << node->data;

	cout << "(";
	displayParenthesizedViewHelper(node->left);

	cout << "(";
	displayParenthesizedViewHelper(node->right);

	if (node != root)
	{
		cout << ")";
	}
}
void BST::displayDescendentsHelper(Node * node)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		return;
	}
	if (node->left != nullptr)
	{
		cout << node->left->data << " ";
		displayDescendentsHelper(node->left);
	}
	if (node->right != nullptr)
	{
		cout << node->right->data << " ";
		displayDescendentsHelper(node->right);
	}
}
void BST::insert(int val)
{
	insertHelper(root,val);
}
void BST::displayAscending()
{
	displayAscendingHelper(root);
}
void BST::displayAscendingHelper(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	displayAscendingHelper(node->left);
	cout << node->data << " ";
	displayAscendingHelper(node->right);
}
//void BST::removeAnode(int x)
//{
//	removeAnodeHelper(root, x);
//}
int BST::hei()
{
	return height(root);
}
int BST::height(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = height(node->left);
		int rDepth = height(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}
//void BST::removeAnodeHelper(Node * &node, int val)
//{
//	Node * temp = returnNode(node, val);
//	Node * parent = getParentHelper(node, val);
//	if (temp!=nullptr && temp->left == nullptr && temp->right == nullptr)
//	{
//		delete temp;
//		temp = nullptr;
//	}
//	else if ((temp != nullptr) && (temp->left == nullptr || temp->right == nullptr))
//	{
//		if ((temp->left != nullptr) && (temp->data > parent->data))
//		{
//			parent->right = temp->left;
//			delete temp;
//			temp = nullptr;
//		}
//	}
//}
void BST::displayDescending()
{
	displayDescendingHelper(root);
}
void BST::displayDescendingHelper(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	displayDescendingHelper(node->right);
	cout << node->data << " ";
	displayDescendingHelper(node->left);
}
void BST::insertHelper(Node * & node, int val)
{
	if (node == nullptr)
	{
		node = new Node(val);
		return;
	}
	if (node->data < val)
	{
		insertHelper(node->right, val);
	}
	if (node->data > val)
	{
		insertHelper(node->left, val);
	}
}
void BST::removeHelper(Node * node)
{
	if (node->left != nullptr)
	{
		removeHelper(node->left);
	}
	if (node->right != nullptr)
	{
		removeHelper(node->right);
	}
	delete node;
	node = nullptr;
}

void BST::displayParenthesizedView()
{
	displayParenthesizedViewHelper(root);
}
int BST::findNodeSiblings(int child)
{
	Node * parent = getParentHelper(root, child);
	if (parent)
	{
		if (parent->left != nullptr && parent->left->data == child && parent->right != nullptr)
		{
			return parent->right->data;
		}
		else if (parent->left != nullptr)
		{
			return parent->left->data;
		}
		else
		{
			cout << "Sibling doesn't exist.";
			exit(0);
		}
	}
	cout << "Node was unavailable";
	exit(0);
}
void BST::displayDescendents(int parent)
{
	Node * node = returnNode(root, parent);
	displayDescendentsHelper(node);
}
int BST::getParent(int child)
{
	Node * temp = getParentHelper(root, child);
	return temp->data;
}

void BST::display()
{
	displayHelper(root);
}
Node * BST::returnNode(Node * node, int value)
{
	Node * temp = nullptr;
	if (node->data == value)
	{
		return node;
	}
	else if (node->left != nullptr)
	{
		temp = returnNode(node->left, value);
	}
	else if (node->right != nullptr && temp != nullptr)
	{
		temp = returnNode(node->right, value);
	}
	return temp;
}