#ifndef AVLTREE_H
#define AVLTREE_H

struct BNode
{
	int data;
	BNode* left;
	BNode* right;
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

class AVLTree 
{
private:
	BNode* root;
	BNode* rightRotate(BNode* y);
	BNode* leftRotate(BNode* x);
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	int heightOfNode(BNode* node);
	void destroyNode(BNode* node);
	BNode* insertNode(BNode* node, int key);
	int getBalance(BNode* node);
	BNode* findNode(BNode* node, int value);
	void display(BNode* node);
	BNode* findParent(BNode* node, int value);
	void preintPreorder(BNode* node);
	void printInorder(BNode* node);
	void printPostorder(BNode* node);
	void parenthesizedView(BNode* node);
	void createCopy(BNode*& temp, const BNode* node);
	bool searchNode(BNode* node, int key);
	void displayBST(BNode* node);
	BNode* deleteN(BNode* node, int key);

public:
	AVLTree();
	~AVLTree();
	void setRoot(int value);
	int getRoot() const;
	int getheight()const;
	void insert(int key);
	void displayDiscendants(int value);
	void preOrder();
	void inOrder();
	void postOrder();
	bool search(int key);
	void deleteNode(int key);
	void display();
	BNode* minValueNode(BNode* node);

};

#endif
