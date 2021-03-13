#include <iostream>
using namespace std;
class BNode
{
public:
	int data;
	BNode * right;
	BNode * left;
	BNode()
	{
		left = right = nullptr;
	}
	BNode(int x)
	{
		data = x;
		left = right = nullptr;
	}
};
struct BinaryTree
{
private:
	BNode * root;
	void preOrderHelper(BNode * n);
	void postOrderHelper(BNode * n);
	void inOrderHelper(BNode * n);
	void copy(BNode*& temp, const BNode* node);
	void removeHelper(BNode* node);
	BNode* findHelper(BNode* n, int v);
	BNode* findParentHelper(BNode* n, int v);
	void displayHelper(BNode * n);
	void displayParenthesizedViewHelper(BNode * node);
	int heightOfTreeHelper(BNode * node);
	void printGivenLevel(BNode* n, int level);
public:
	BinaryTree();
	~BinaryTree();
	void setRoot(int v);
	BNode* getRoot();
	void setLeftChild(int parent, int child);
	void setRightChild(int parent, int child);
	int getParent(int node);
	void displayDescendents(int n);
	void remove(int node);
	void preOrder();
	void postOrder();
	void inOrder();
	void visit(BNode * n)
	{
		cout << "n-> data" <<"\n";
	}
	bool findNode(int node);
	bool isInternalNode(int);
	bool isExternalNode(int );
	int findNodeSiblings(int );
	int heightOfTree();
	void levelOrder();
	BinaryTree & operator=(const BinaryTree &ref);
	void displayParethesizedView();
};
BinaryTree::BinaryTree()
{
	root = nullptr;
}
BinaryTree:: ~BinaryTree()
{
	if (root != nullptr)
	{
		removeHelper(root);
		root = nullptr;
	}
}
void BinaryTree::removeHelper(BNode* node)
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
	return;
}
void BinaryTree:: setRoot(int v)
{
	if (root == nullptr)
	{
		root = new BNode(v);
		root->left = nullptr;
		root->right = nullptr;
	}
}
BNode* BinaryTree::getRoot()
{
	if (root != nullptr)
	{
		return root;
	}
}
void BinaryTree::setLeftChild(int parent, int child)
{
	BNode *  temp;
	if (root != nullptr)
	{
		temp = findHelper(root, parent);
	}
	if (temp->left == nullptr)
	{
		temp->left = new BNode(child);
	}
}
BNode* BinaryTree::findHelper(BNode* n,int v)
{
	BNode * temp = nullptr;
	if (n->data == v)
	{
		return n;
	}
	if (n->left != nullptr)
	{
		temp = findHelper(n->left, v);
	}
	if (temp == nullptr && n->right != nullptr)
	{
		temp = findHelper(n->right, v);
	}
	return temp;
}
void BinaryTree::setRightChild(int parent, int child)
{
	BNode *  temp;
	if (root != nullptr)
	{
		temp = findHelper(root, parent);
	}
	if (temp->right == nullptr)
	{
		temp->right = new BNode(child);
	}
}
int BinaryTree::getParent(int node)
{
	BNode * temp = findParentHelper(root, node);
	return temp->data;
}
BNode* BinaryTree::findParentHelper(BNode* n, int v)
{
	if (n == nullptr || root->data==v)
	{
		return nullptr;
	}
	if (n->left != nullptr)
	{
		if (n->left->data == v)
		{
			return n;
		}
		findParentHelper(n->left, v);
	}
	if (n->right != nullptr)
	{
		if (n->right->data == v)
		{
			return n;
		}
		findParentHelper(n->right, v);
	}
}
void BinaryTree::displayDescendents(int n)
{
	BNode* temp = findHelper(root, n);
	if (temp != nullptr)
	{
		displayHelper(temp);
	}
}
void BinaryTree::displayHelper(BNode* n)
{
	if (n == nullptr)
	{
		return;
	}
	cout << n->data << "\n";
	displayHelper(n->left);
	displayHelper(n->right);
}
void  BinaryTree::displayParethesizedView()
{
	if (root != nullptr)
	{
		displayParenthesizedViewHelper(root);
	}
}
void BinaryTree::displayParenthesizedViewHelper(BNode * node)
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
		cout << ",";
		if (node->right != nullptr)
		{
			displayParenthesizedViewHelper(node->right);
			cout << ")";
		}
	}
}
void BinaryTree::preOrderHelper(BNode * n)
{
	if (n == nullptr) return;
	preOrderHelper(n ->left);
	visit(n);
	preOrderHelper(n->right);
}
void BinaryTree::postOrderHelper(BNode * n)
{
	if (n == nullptr) return;
	visit(n);
	postOrderHelper(n->left);
	postOrderHelper(n->right);
}
void BinaryTree::inOrderHelper(BNode * n)
{
	if (n == nullptr) return;
	inOrderHelper(n->left);
	inOrderHelper(n->right);
	visit(n);
}
void BinaryTree::preOrder()
{
	preOrderHelper(root);
}
void BinaryTree::postOrder()
{
	postOrderHelper(root);
}
void BinaryTree::inOrder()
{
	inOrderHelper(root);
}
void BinaryTree::levelOrder()
{
	int h = heightOfTree();
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
	}
}
void BinaryTree::printGivenLevel(BNode* node, int level)
{
	if (node == nullptr)
		return;
	if (level == 1)
		cout << node->data << " ";
	else if (level > 1)
	{
		printGivenLevel(node->left, level - 1);
		printGivenLevel(node->right, level - 1);
	}
}
bool BinaryTree::findNode(int node)
{
	BNode * temp;
	temp = findHelper(root,node);
	if (temp != nullptr)
	{
		return true;
	}
	return false;
}
bool BinaryTree::isInternalNode(int v)
{
	BNode * temp = findHelper(root, v);
	if (temp->left != nullptr || temp->right != nullptr)
	{
		return true;
	}
	return false;
}
bool BinaryTree::isExternalNode(int v)
{
	BNode * temp = findHelper(root, v);
	if (temp->left == nullptr && temp->right == nullptr)
	{
		return true;
	}
	return false;
}
int BinaryTree::findNodeSiblings(int n)
{
	BNode * temp = findParentHelper(root, n);
	if (temp ->left != nullptr && temp->left->data != n)
	{
		return temp->left->data;
	}
	else if (temp->right != nullptr && temp->right->data != n)
	{
		return temp->right->data;
	}
	return 0;
}
int BinaryTree::heightOfTree()
{
	return heightOfTreeHelper(root);
}
int BinaryTree::heightOfTreeHelper(BNode * node)
{
	if (node == nullptr)
		return 0;
	else
	{
		int leftDepth = heightOfTreeHelper(node->left);
		int rightDepth = heightOfTreeHelper(node->right);
		if (leftDepth > rightDepth)
		{
			return (leftDepth + 1);
		}
		else
		{
			return (rightDepth + 1);
		}
	}
}
void BinaryTree:: remove(int node)
{
	BNode * temp = findHelper(root, node);
	BNode * parent;
	if (temp != nullptr)
	{
		parent = findParentHelper(root, node);
		removeHelper(temp);
		if (parent->right == temp)
		{
			parent->right = nullptr;
		}
		if (parent->left == temp)
		{
			parent->left = nullptr;
		}
	}
}
void BinaryTree::copy(BNode*& temp, const BNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	temp = new BNode(node->data);
	copy(temp->left, node->left);
	copy(temp->right, node->right);
}
BinaryTree & BinaryTree:: operator=(const BinaryTree &ref)
{
	if (this != &ref && ref.root != nullptr)
	{
		this->~BinaryTree();
		this->copy(this->root, ref.root);
	}
	else
	{
		this->root = nullptr;
	}
	return *this;
}