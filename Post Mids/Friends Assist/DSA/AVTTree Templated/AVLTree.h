#ifndef TEMAVLTREE_H
#define TEMAVLTREE_H

#include <iostream>
using namespace std;


template<class T>
struct BNode
{
	T data;
	BNode<T>* left;
	BNode<T>* right;
	int height;
	BNode()
	{
		left = right = nullptr;
		height = 0;
	}
	BNode(int value)
	{
		data = value;
		left = right = nullptr;
		height = 1;
	}

};

template<class T>
class AVLTree
{
private:
	BNode<T>* root;
	BNode<T>* rightRotate(BNode<T>* y);
	BNode<T>* leftRotate(BNode<T>* x);
	T max(T a,T b)
	{
		return (a > b) ? a : b;
	}
	int heightOfNode(BNode<T>* node);
	void destroyNode(BNode<T>* node);
	BNode<T>* insertNode(BNode<T>* node, T key);
	int getBalance(BNode<T>* node);
	BNode<T>* findNode(BNode<T>* node, T value);
	void display(BNode<T>* node);
	BNode<T>* findParent(BNode<T>* node, T value);
	void preintPreorder(BNode<T>* node);
	void printInorder(BNode<T>* node);
	void printPostorder(BNode<T>* node);
	void parenthesizedView(BNode<T>* node);
	void createCopy(BNode<T>*& temp, const BNode<T>* node);
	bool searchNode(BNode<T>* node, T key);
	void displayBST(BNode<T>* node);
	BNode<T>* deleteN(BNode<T>* node, T key);

public:
	AVLTree();
	~AVLTree();
	void setRoot(T value);
	T getRoot() const;
	int getheight()const;
	void insert(T key);
	void displayDiscendants(T value);
	void preOrder();
	void inOrder();
	void postOrder();
	bool search(T key);
	void deleteNode(T key);
	void display();
	BNode<T>* minValueNode(BNode<T>* node);

};

#endif



template<class T>
inline BNode<T>* AVLTree<T>::rightRotate(BNode<T>* y)
{
	BNode<T>* x = y->left;
	BNode<T>* T2 = x->right;

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

template<class T>
inline BNode<T>* AVLTree<T>::leftRotate(BNode<T>* x)
{
	BNode<T>* y = x->right;
	BNode<T>* T2 = y->left;

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

template<class T>
inline int AVLTree<T>::heightOfNode(BNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}

template<class T>
inline void AVLTree<T>::destroyNode(BNode<T>* node)
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

template<class T>
inline BNode<T>* AVLTree<T>::insertNode(BNode<T>* node, T key)
{
	if (node == nullptr)
	{
		return new BNode<T>(key);
	}
	if (key < node->data)
		node->left = insertNode(node->left, key);
	else if (key > node->data)
		node->right = insertNode(node->right, key);

	node->height = 1 + max(heightOfNode(node->left), heightOfNode(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	if (balance > 1 && key < node->left->data)
	{
		return rightRotate(node);
	}

	if (balance < -1 && key > node->right->data)
	{
		return leftRotate(node);
	}

	if (balance > 1 && key > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

template<class T>
inline int AVLTree<T>::getBalance(BNode<T>* node)
{
	if (node == nullptr)
		return 0;
	return heightOfNode(node->left) - heightOfNode(node->right);
}

template<class T>
inline BNode<T>* AVLTree<T>::findNode(BNode<T>* node, T value)
{
	BNode<T>* temp = nullptr;
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

template<class T>
inline void AVLTree<T>::display(BNode<T>* node)
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

template<class T>
inline BNode<T>* AVLTree<T>::findParent(BNode<T>* node, T value)
{
	BNode<T>* temp = nullptr;
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

template<class T>
inline void AVLTree<T>::preintPreorder(BNode<T>* node)
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

template<class T>
inline void AVLTree<T>::printInorder(BNode<T>* node)
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

template<class T>
inline void AVLTree<T>::printPostorder(BNode<T>* node)
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

template<class T>
inline void AVLTree<T>::parenthesizedView(BNode<T>* node)
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

template<class T>
inline void AVLTree<T>::createCopy(BNode<T>*& temp, const BNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	temp = new BNode<T>(node->data);
	//cout<<temp <<" " <<temp->data<< " Hello\n";

	createCopy(temp->left, node->left);

	createCopy(temp->right, node->right);

}

template<class T>
inline bool AVLTree<T>::searchNode(BNode<T>* node, T key)
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

template<class T>
inline void AVLTree<T>::displayBST(BNode<T>* node)
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

template<class T>
inline BNode<T>* AVLTree<T>::deleteN(BNode<T> * node, T key)
{
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
		if (node->left == NULL)
		{
			BNode<T>* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == NULL)
		{
			BNode<T>* temp = node->left;
			delete node;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		BNode<T>* temp = minValueNode(node->right);

		node->data = temp->data;

		node->right = deleteN(node->right, temp->data);
	}
	if (node == nullptr)
	{
		return node;
	}
	node->height = 1 + max(heightOfNode(node->left), heightOfNode(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->data)
	{
		return rightRotate(node);
	}

	if (balance < -1 && key > node->right->data)
	{
		return leftRotate(node);
	}

	if (balance > 1 && key > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;

}

template<class T>
inline AVLTree<T>::AVLTree()
{
	root = nullptr;
}

template<class T>
inline AVLTree<T>::~AVLTree()
{
	if (root)
	{
		destroyNode(root);
	}
}

template<class T>
inline  void AVLTree<T>::setRoot(T value)
{
	root = new BNode(value);
	root->left = root->right = nullptr;
}

template<class T>
inline T AVLTree<T>::getRoot() const
{
	if (root)
	{
		return root->data;
	}
	exit(0);
}

template<class T>
inline int AVLTree<T>::getheight() const
{
	if (root)
	{
		return root->height;
	}
	return 0;
}

template<class T>
inline void AVLTree<T>::insert(T key)
{
	root = insertNode(root, key);
}

template<class T>
inline void AVLTree<T>::displayDiscendants(T value)
{
	BNode<T>* temp = findNode(root, value);
	if (temp != nullptr)
	{
		//cout << "Hello\n";
		cout << temp->data << " ";
		display(temp);
	}
}

template<class T>
inline void AVLTree<T>::preOrder()
{
	preintPreorder(root);
}

template<class T>
inline void AVLTree<T>::inOrder()
{
	printInorder(root);
}

template<class T>
inline void AVLTree<T>::postOrder()
{
	printPostorder(root);
}

template<class T>
inline bool AVLTree<T>::search(T key)
{
	return searchNode(root, key);
}

template<class T>
inline void AVLTree<T>::deleteNode(T key)
{
	deleteN(root, key);
}

template<class T>
inline void AVLTree<T>::display()
{
	if (root != nullptr)
	{
		//cout << "Hello\n";
		cout << root->data << " ";
		displayBST(root);
	}

}

template<class T>
inline BNode<T>* AVLTree<T>::minValueNode(BNode<T> * node)
{
	BNode<T>* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

