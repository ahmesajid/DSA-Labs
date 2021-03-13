#include<iostream>
using namespace std;
//#include "binaryTree.cpp"
class Node
{
public:
	int data;
	Node * left;
	Node * right;
	Node()
	{
		left = right = nullptr;
	}
	Node(int x)
	{
		data = x;
		left = right = nullptr;
	}
};
class BST
{
	Node * root;
	Node * getParentHelper(Node * node, int child);
	void displayHelper(Node * node);
	void displayDescendentsHelper(Node * node);
	void displayAscendentsHelper(Node * node, Node* stop);
	void insertHelper(Node * &node, int val);
	void displayParenthesizedViewHelper(Node * node);
public:
	BST(); //1
	BST(const BST &toCopy);//1
	~BST(); //1
	void setRoot(int val); //2
	Node* getRoot(); //3
	void insert(int x); //4
	Node * getLeftChild(Node * node); //5
	Node * getRightChild(Node * node); //6
	Node * searchNode(Node * node, int value); //7
	void removeNode(Node * node); //8
	void displayPostOrder(); //9
	//bool isBST(BinaryTree b); //10
	//bool isBSTHelper(BNode *node);
	int getNodeDegree(Node* node);//11
	int getTreeDegree();//12
	int getTreeDegreeHelper(Node* node);
	void display(); //13
	void displayParenthesizedView();//13
	bool isEqual(Node* first, Node* second); //14
	bool isInternalNode(Node* node); //15
	bool isExternalNode(Node* node); //16;
	int height(); //17
	int heightHelper(Node * node);
	void displayDescendents(int parent); //18
	void displayAscendents(int child); //19
	void mirror(Node* node);//20
	int getNodeCount(Node* node);//21
	int findMinMax(int flag);//22
	void displayAscending(); //23 sorted tree

	bool empty();
	void displayPostOrderHelper(Node * node);
	int getParent(int child);
	
	Node* copyHelper(const Node *toCopy);
	void displayAscendingHelper(Node * node);
	bool search(int key);
	bool searchHelper(Node* node, int key);
};
BST::BST()
{
	root = nullptr;
}
BST::BST(const BST &copy) 
{
	root = copyHelper(copy.root);
}
Node* BST::copyHelper(const Node *toCopy) 
{
	if (toCopy == NULL)
		return NULL;
	Node *copyNode = new Node;
	copyNode->data = toCopy->data;
	copyNode->left = copyHelper(toCopy->left);
	copyNode->right = copyHelper(toCopy->right);
	return copyNode;
}
BST::~BST()
{
	if (root != nullptr)
	{
		removeNode(this->root);
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
	if (!root)
	{
		root = new Node;
		root->data = x;
		root->left = root->right = nullptr;
	}
}

Node* BST::getRoot()
{
	return root;
}
void BST::displayParenthesizedViewHelper(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data;
	if (node->left != nullptr)
	{
		cout << "(";
		displayParenthesizedViewHelper(node->left);
		if (node->right != nullptr)
		{
			cout << ",";
			displayParenthesizedViewHelper(node->right);
			cout << ")";
		}
		else
		{
			cout << ")";
		}
		
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
Node * BST::getLeftChild(Node * node)
{
	if (node)
	{
		return node->left;
	}
	return nullptr;
}
Node * BST::getRightChild(Node * node)
{
	if (node)
	{
		return node->right;
	}
	return nullptr;
}
void BST::displayPostOrder()
{
	displayPostOrderHelper(root);
}
void BST::displayPostOrderHelper(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	displayPostOrderHelper(node->left);
	displayPostOrderHelper(node->right);
	cout << node->data <<" : ";
}
int BST::getNodeDegree(Node* node)
{
	int degree = 0;
	if (node)
	{
		if (node->left)
		{
			degree++;
		}
		if (node->right)
		{
			degree++;
		}
		return degree;
	}
	return -1;
}
int BST::getTreeDegree()
{
	if (root)
	{
		return getTreeDegreeHelper(root);
	}
	return -1;
}
int BST::getTreeDegreeHelper(Node* node)
{
	int degree = 0;
	if (node)
	{
		if (degree == 2)
		{
			return degree;
		}
		if (getNodeDegree(node) == 2)
		{
			degree = 2;
		}
		else if (getNodeDegree(node) == 1)
		{
			degree = 1;
		}
		getTreeDegreeHelper(node->left);
		getTreeDegreeHelper(node->right);
	}
	return degree;
}
void BST:: mirror(Node* node)
{
	if (node == NULL)
		return;
	else
	{
		Node* temp;
		mirror(node->left);
		mirror(node->right);

		/* swap the pointers in this node */
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
void BST::insert(int val)
{
	insertHelper(root, val);
}
/*
bool BST::isBSTHelper(BNode *node)
{
	BNode * temp = node;
	BNode* l;
	BNode* r;
	l = temp->left;
	r = temp->right;
	if (temp == nullptr)
	{
		return true;
	}
	if (temp->data < temp->left->data || temp->data > temp->right->data)
	{
		return false;
	}
}
bool BST::isBST(BinaryTree b)
{
	return isBSTHelper(b.getRoot());
}*/
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
int BST::height()
{
	return heightHelper(root);
}
int BST::heightHelper(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lDepth = heightHelper(node->left);
		int rDepth = heightHelper(node->right);
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}
bool BST::isInternalNode(Node* node)
{
	if (getNodeDegree(node) == 0)
	{
		return false;
	}
	return true;
}
bool BST::isExternalNode(Node* node)
{
	if (getNodeDegree(node) == 0)
	{
		return true;
	}
	return false;
}
void BST::displayAscendents(int child)
{
	Node * temp = searchNode(root,child);
	if (temp)
	{
		displayAscendentsHelper(root, temp);
	}
}
void BST::displayAscendentsHelper(Node * node, Node* stop)
{
	Node * temp = node;
	if (temp == stop)
	{
		return;
	}
	cout << temp->data << "\n";
	displayAscendentsHelper(temp->left,stop);
	displayAscendentsHelper(temp->right, stop);
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
void BST::removeNode(Node * node)
{
	if (node->left != nullptr)
	{
		removeNode(node->left);
	}
	if (node->right != nullptr)
	{
		removeNode(node->right);
	}
	delete node;
	node = nullptr;
}

void BST::displayParenthesizedView()
{
	displayParenthesizedViewHelper(root);
}
bool BST:: isEqual(Node* first, Node* second)
{
	if (first && second)
	{
		if (first->data != second->data)
		{
			return false;
		}
		isEqual(first->left, second->left);
		isEqual(first->right, second->right);
	}
	if (first == nullptr && second == nullptr)
	{
		return true;
	}
	return false;
}
void BST::displayDescendents(int parent)
{
	Node * node = searchNode(root, parent);
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
Node * BST::searchNode(Node * node, int value)
{
	Node * temp = nullptr;
	if (node->data == value)
	{
		return node;
	}
	else if (node->left != nullptr)
	{
		temp = searchNode(node->left, value);
	}
	else if (node->right != nullptr && temp != nullptr)
	{
		temp = searchNode(node->right, value);
	}
	return temp;
}
bool BST::search(int key)
{
	return searchHelper(root, key);
}
bool BST::searchHelper(Node* node, int key)
{
	if (node == nullptr)
		return false;
	else if (node->data == key)
		return true;
	else if (node->data > key)
		return searchHelper(node->left, key);
	else if (node->data < key)
		return searchHelper(node->right, key);
}
int BST::getNodeCount(Node* node)
{
	int count = 0;
	if (node)
	{
		count++;
		getNodeCount(node->left);
		getNodeCount(node->right);
	}
	return count;
}
int BST::findMinMax(int flag)
{
	Node* max = root;
	Node* min = root;
	while (min->left != nullptr)
	{
		min = min->left;
	}
	while (max->right != nullptr)
	{
		max = max->right;
	}
	if (flag == 0)
	{
		return min->data;
	}
	else if (flag == 1)
	{
		return max->data;
	}
}
int main()
{
	BST a;
	a.insert(5);
	a.insert(10);
	a.insert(2);
	a.insert(1);
	a.display();
	cout << "\n";
	//a.mirror(a.getRoot());
	a.displayAscending();
	cout << "\n";
	return 0;
}