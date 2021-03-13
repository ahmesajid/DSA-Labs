#include "BinaryTree.h"
#include<iostream>
using namespace std;
Node * BinaryTree::getParentHelper(Node * node, int child)
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
void BinaryTree::dislayHelper(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << " ";
	dislayHelper(node->left);
	dislayHelper(node->right);
}
void BinaryTree::dislayDescendentsHelper(Node * node)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		return;
	}
	if (node->left != nullptr)
	{
		cout << node->left->data << " ";
		dislayDescendentsHelper(node->left);
	}
	if (node->right != nullptr)
	{
		cout << node->right->data << " ";
		dislayDescendentsHelper(node->right);
	}
}
void BinaryTree::displayParenthesizedViewHelper(Node * node)
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
void BinaryTree::setLeftChildHelper(Node * node, int  parent, int child)
{
	if (node == nullptr)
		return;
	if (node->data == parent)
	{
		if (node->left == nullptr)
		{
			node->left = new Node;
			node->left->data = child;
			return;
		}
		else
		{
			node->left->data = child;
			return;
		}
	}
	setLeftChildHelper(node->left, parent, child);
	setLeftChildHelper(node->right, parent, child);
}
void BinaryTree::setRightChildHelper(Node * node, int parent, int child)
{
	if (node == nullptr)
		return;
	if (node->data == parent)
	{
		if (node->right == nullptr)
		{
			node->right = new Node;
			node->right->data = child;
			return;
		}
		else
		{
			node->right->data = child;
			return;
		}
	}
	setRightChildHelper(node->left, parent, child);
	setRightChildHelper(node->right, parent, child);
}
BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::~BinaryTree()
{
	if (root != nullptr)
	{
		removeHelper(root);
		root = nullptr;
	}
}

void BinaryTree::setRoot(int x)
{
	root = new Node;
	root->data = x;
	root->left = root->right = nullptr;
}

int BinaryTree::getRoot()
{
	return root->data;
}

void BinaryTree::setLeftChild(int parent, int child)
{
	setLeftChildHelper(root, parent, child);
}
void BinaryTree::setRightChild(int parent, int child)
{
	setRightChildHelper(root, parent, child);
}

int BinaryTree::getParent(int child)
{
	Node * temp = getParentHelper(root, child);
	return temp->data;
}

int BinaryTree::findNodeSiblings(int child)
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

void BinaryTree::displayDescendents(int parent)
{
	Node * node = returnNode(root, parent);
	dislayDescendentsHelper(node);
}

void BinaryTree::display()
{
	dislayHelper(root);
}

void BinaryTree::remove(int data)
{
	Node * temp = returnNode(root, data);
	if (temp)
	{
		Node * parent = getParentHelper(root, data);
		removeHelper(temp);
		if (parent->left == temp)
		{
			temp->left = nullptr;
		}
		else
		{
			temp->right = nullptr;
		}
	}

}

void BinaryTree::removeHelper(Node * node)
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

void BinaryTree::displayParenthesizedView()
{
	displayParenthesizedViewHelper(root);
}

Node * BinaryTree::returnNode(Node * node, int value)
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

