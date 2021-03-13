#include "BinaryTree.h"
#include<iostream>
using namespace std;

BNode * BinTree::findNode(BNode * node, int value)
{
	BNode* temp = nullptr;
	if (node->data == value)
	{
		//cout << node << "\n";
		//cout << "Hello\n";
		return node;
	}
	if(node->left != nullptr)
	{
		 temp = findNode(node->left, value);
	}
	if (temp == nullptr &&node->right != nullptr)
	{
		 temp = findNode(node->right, value);
	}
	return temp;
}

void BinTree::display(BNode * node)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		return;
	}
	if (node->left != nullptr)
	{
		cout << node->left->data << " ";
		display(node->left);
	}
	if (node->right != nullptr)
	{
		cout << node->right->data << " ";
		display(node->right);
	}
}

BNode * BinTree::findParent(BNode* node ,int value)
{
	BNode* temp = nullptr;
	if ((node->left != nullptr && node->left->data == value) || (node->right != nullptr && node->right->data == value))
	{
		//cout << node << "\n";
		//cout << "Hello\n";
		return node;
	}
	if (node->left != nullptr)
	{
		temp = findParent(node->left, value);
	}
	if (temp == nullptr &&node->right != nullptr)
	{
		temp = findParent(node->right, value);
	}
	return temp;

}

void BinTree::preintPreorder(BNode * node)
{
	if (node == nullptr)
	{
		return;
	}

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left sutree */
	preintPreorder(node->left);

	/* now recur on right subtree */
	preintPreorder(node->right);

}

void BinTree::printInorder(BNode * node)
{
	if (node == nullptr)
	{
		return;
	}

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

void BinTree::printPostorder(BNode * node)
{
	if (node == nullptr)
	{
		return;
	}

	// first recur on left subtree 
	printPostorder(node->left);

	// then recur on right subtree 
	printPostorder(node->right);

	// now deal with the node 
	cout << node->data << " ";
}

void BinTree::parenthesizedView(BNode * node)
{
	if (node == nullptr)
	{
		cout << "_)";
		return;
	}

	/* first print data of node */
	cout << node->data ;


	/* then recur on left subtree */
	cout<< "(";
	parenthesizedView(node->left);

	/* now recur on right subtree */
	cout << "(";
	parenthesizedView(node->right);
	if (node != root)
	{
		cout << ")";
	}
}

void BinTree::createCopy(BNode*& temp ,const BNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	temp = new BNode(node->data);
	//cout<<temp <<" " <<temp->data<< " Hello\n";

	createCopy(temp->left, node->left);

	createCopy(temp->right, node->right);
}

bool BinTree::isBinSerTre(BNode * node)
{
	bool check = false;
	if (node == nullptr)
	{
		return true;
	}
	else if ((node->left != nullptr && node->right != nullptr) && (node->left->data > node->data || node->right->data < node->data))
	{
		return false;
	}
	else if (node->right == nullptr && (node->left != nullptr && node->left->data > node->data))
	{
		return false;
	}
	else if (node->left == nullptr && (node->right != nullptr && node->right->data < node->data))
	{
		return false;
	}
	check = isBinSerTre(node->left);
	if (check)
	{
		isBinSerTre(node->right);
	}
	return check;
}

BinTree::BinTree()
{
	root = nullptr;
}

void BinTree::setRoot(int value)
{
	root = new BNode(value);
}

int BinTree::getRoot() const
{
	return root->data;
}

BNode* BinTree::getRootNode() const
{
	return root;
}

void BinTree::setLeftChild(int parent, int child)
{
	BNode *temp = findNode(root, parent);
	//cout << temp << "\n";
	//cout << temp << " " << temp->data << "\n";

	if (temp != nullptr && temp->left == nullptr)
	{
		temp->left = new BNode(child);
		//cout << temp->left->data << "\n";
	}
	else if(temp != nullptr)
	{
		temp->left->data = child;
	}
}

void BinTree::setRightChild(int parent, int child)
{
	BNode *temp = findNode(root, parent);
	//cout << temp << " " << temp->data << "\n";
	if( temp != nullptr&& temp->right == nullptr)
	{
		temp->right = new BNode(child);
		//cout << temp->right->data << "\n";

	}
	else if(temp != nullptr)
	{
		temp->right->data = child;
	}
}

void BinTree::displayDiscendants(int value)
{
	BNode* temp = findNode(root, value);
	if (temp != nullptr)
	{
		//cout << "Hello\n";
		cout << temp->data << " ";
		display(temp);
	}
	
}

int BinTree::getParent(int value)
{
	BNode*temp = findParent(root, value);
	return temp->data;
}

void BinTree::preOrder()
{
	preintPreorder(root);
}

void BinTree::inOrder()
{
	printInorder(root);
}

void BinTree::postOrder()
{
	printPostorder(root);
}

void BinTree::displayParenthesizedView()
{
	//cout << "(";
	parenthesizedView(root);
}

bool BinTree::findNodE(int value)
{
	if (findNode(root , value))
	{
		return true;
	}
	return false;
}

int BinTree::findSibiling(int value)
{
	BNode* parent = findParent(root, value);
	if (parent)
	{
		if (parent->left != nullptr && parent->left->data == value && parent->right != NULL)
		{
			return parent->right->data;
		}
		else if(parent->left != NULL)
		{
			return parent->left->data;
		}
		else
		{
			cout << "Has no sibiling\n";
			exit(0);
		}
	}
	cout << "Node not found\n";
	exit(0);
}

BinTree & BinTree::operator=(const BinTree & ref)
{
	if (this != &ref && ref.root != NULL)
	{
		this->~BinTree();
		this->createCopy(this->root,ref.root);
	}
	else
	{
		this->root = nullptr;
	}
	return *this;
}

bool BinTree::isBST()
{
	return isBinSerTre(this->root);
}

