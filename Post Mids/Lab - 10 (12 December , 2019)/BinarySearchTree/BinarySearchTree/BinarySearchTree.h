#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE
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
	void displayParenthesizedViewHelper(Node * node);
public:
	BST();
	~BST();
	bool empty();
	void insert(int x);
	void insertHelper(Node * &node, int val);
	void setRoot(int val);
	int getRoot();
	int getParent(int child);
	int findNodeSiblings(int child);
	Node * returnNode(Node * node, int value);
	void displayDescendents(int parent);
	void display();
	void removeHelper(Node * node);
	void displayParenthesizedView();
	void displayAscending();
	void displayAscendingHelper(Node * node);
	void displayDescending();
	void displayDescendingHelper(Node * node);
	//void removeAnode(int T);
	//void removeAnodeHelper(Node * &node, int val);
	int hei();
	int height(Node * node);
};
#endif 