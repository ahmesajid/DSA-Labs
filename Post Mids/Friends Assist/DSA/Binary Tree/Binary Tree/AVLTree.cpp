#include "AVLTree.h"
#include <iostream>
using namespace std;

BNode* AVLTree::rightRotate(BNode* y)
{
	BNode* x = y->left;
	BNode* T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(heightOfNode(y->left),
		heightOfNode(y->right)) + 1;
	x->height = max(heightOfNode(x->left),
		heightOfNode(x->right)) + 1;
	return x;

}

BNode* AVLTree::leftRotate(BNode* x)
{
	BNode* y = x->right;
	BNode* T2 = y->left;

	// Perform rotation  
	y->left = x;
	x->right = T2;

	// Update heights  
	x->height = max(heightOfNode(x->left),
		heightOfNode(x->right)) + 1;
	y->height = max(heightOfNode(y->left),
		heightOfNode(y->right)) + 1;

	return y;
}

int AVLTree::heightOfNode(BNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}

void AVLTree::destroyNode(BNode* node)
{
	if (node->left != nullptr)
	{
		destroyNode(node->left);
	}
	if (node->right != nullptr)
	{
		destroyNode(node->right);
	}
	//cout << node->data << "\n";
	delete node;
	node = nullptr;
	return;
}

BNode* AVLTree::insertNode(BNode* node, int key)
{
	if (node == nullptr)
	{
		return new BNode(key);
	}
	if (key < node->data)
		node->left = insertNode(node->left, key);
	else if (key > node->data)
		node->right = insertNode(node->right, key);

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(heightOfNode(node->left), heightOfNode(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->data)
	{
		return rightRotate(node);
	}

	// Right Right Case  
	if (balance < -1 && key > node->right->data)
	{
		return leftRotate(node);
	}

	// Left Right Case  
	if (balance > 1 && key > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case  
	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;

}

int AVLTree::getBalance(BNode* node)
{
	if (node == nullptr)
		return 0;
	return heightOfNode(node->left) - heightOfNode(node->right);
}

BNode* AVLTree::findNode(BNode* node, int value)
{
	BNode* temp = nullptr;
	if (node->data == value)
	{
		//cout << node << "\n";
		//cout << "Hello\n";
		return node;
	}
	if (node->left != nullptr)
	{
		temp = findNode(node->left, value);
	}
	if (temp == nullptr && node->right != nullptr)
	{
		temp = findNode(node->right, value);
	}
	return temp;
}

void AVLTree::display(BNode* node)
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

BNode* AVLTree::findParent(BNode* node, int value)
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
	if (temp == nullptr && node->right != nullptr)
	{
		temp = findParent(node->right, value);
	}
	return temp;

}

void AVLTree::preintPreorder(BNode* node)
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

void AVLTree::printInorder(BNode* node)
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

void AVLTree::printPostorder(BNode* node)
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

void AVLTree::parenthesizedView(BNode* node)
{
	if (node == nullptr)
	{
		cout << "_)";
		return;
	}

	/* first print data of node */
	cout << node->data;


	/* then recur on left subtree */
	cout << "(";
	parenthesizedView(node->left);

	/* now recur on right subtree */
	cout << "(";
	parenthesizedView(node->right);
	if (node != root)
	{
		cout << ")";
	}
}

void AVLTree::createCopy(BNode*& temp, const BNode* node)
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

bool AVLTree::searchNode(BNode* node, int key)
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
	else if (node->data > key && check == false)
		check = searchNode(node->left, key);
	return check;
}

void AVLTree::displayBST(BNode * node)
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

BNode* AVLTree::deleteN(BNode * node, int key)
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

AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
	if (root)
	{
		destroyNode(root);
	}
}

void AVLTree::setRoot(int value)
{
	root = new BNode(value);
	root->left = root->right = nullptr;
}

int AVLTree::getRoot() const
{
	if (root)
	{
		return root->data;
	}
	exit(0);
}

int AVLTree::getheight() const
{
	if (root)
	{
		return root->height;
	}
	return 0;
}

void AVLTree::insert(int key)
{
	root = insertNode(root, key);
}

void AVLTree::displayDiscendants(int value)
{
	BNode* temp = findNode(root, value);
	if (temp != nullptr)
	{
		//cout << "Hello\n";
		cout << temp->data << " ";
		display(temp);
	}
}

void AVLTree::preOrder()
{
	preintPreorder(root);
}

void AVLTree::inOrder()
{
	printInorder(root);
}

void AVLTree::postOrder()
{
	printPostorder(root);
}

bool AVLTree::search(int key)
{
	return searchNode(root, key);
}

void AVLTree::deleteNode(int key)
{
	deleteN(root, key);
}

void AVLTree::display()
{
	if (root != nullptr)
	{
		//cout << "Hello\n";
		cout << root->data << " ";
		displayBST(root);
	}

}

BNode* AVLTree::minValueNode(BNode* node)
{
	BNode* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

