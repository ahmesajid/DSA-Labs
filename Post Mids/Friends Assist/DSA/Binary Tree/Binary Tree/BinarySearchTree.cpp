#include "BinarySearchTree.h"
#include<iostream>
using namespace std;


bool BinSerTre::searchNode(BNode* node, int key)
{
	bool check = false;
	if (node == nullptr)
		return false;
	if (node->data == key)
		return true;

	// Key is greater than root's key 
	if (node->data < key)
		check = searchNode(node->right, key);

	// Key is smaller than root's key 
	else if(node->data > key && check == false)
	    check = searchNode(node->left, key);
	return check;
}

void BinSerTre::insertNode(BNode*& node, int value)
{
	if (node == nullptr)
	{
		node = new BNode(value);
		return;
	}
		
	if (value < node->data)
	{
		insertNode(node->left, value);
	}
	else if (value > node->data)
	{
		insertNode(node->right, value);
	}
}

void BinSerTre::displayBST(BNode* node)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		return;
	}
	if (node->left != nullptr)
	{
		cout << node->left->data << " ";
		displayBST(node->left);
	}
	if (node->right != nullptr)
	{
		cout << node->right->data << " ";
		displayBST(node->right);
	}

}

BNode* BinSerTre::deleteN(BNode* node, int key)
{
	// base case 
	if (node == NULL) return node;

	// If the key to be deleted is smaller than the node's key, 
	// then it lies in left subtree 
	if (key < node->data)
		node->left = deleteN(node->left, key);

	// If the key to be deleted is greater than the node's key, 
	// then it lies in right subtree 
	else if (key > node->data)
		node->right = deleteN(node->right, key);

	// if key is same as node's key, then This is the node 
	// to be deleted 
	else
	{
		// node with only one child or no child 
		if (node->left == NULL)
		{
			BNode* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == NULL)
		{
			BNode* temp = node->left;
			delete node;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		BNode* temp = minValueNode(node->right);

		// Copy the inorder successor's content to this node 
		node->data = temp->data;

		// Delete the inorder successor 
		node->right = deleteN(node->right, temp->data);
	}
	return node;
}

BinSerTre::BinSerTre()
{
	root = nullptr;
}

BinSerTre::~BinSerTre()
{
	if (root != nullptr)
	{
		destroyNode(this->root);
	}
}

void BinSerTre::setRoot(int value)
{
	root = new BNode(value);
}

int BinSerTre::getRoot() const
{
	return root->data;
}

void BinSerTre::insert(int value)
{
	insertNode(root, value);
}

bool BinSerTre::search(int key)
{
	return searchNode(root , key);
}

void BinSerTre::deleteNode(int key)
{
	deleteN(root, key);
}

void BinSerTre::display()
{
	if (root != nullptr)
	{
		//cout << "Hello\n";
		cout << root->data << " ";
		displayBST(root);
	}

}

BNode* BinSerTre::minValueNode(BNode* node)
{
	BNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
