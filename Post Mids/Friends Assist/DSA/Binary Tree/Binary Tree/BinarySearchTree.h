#ifndef BST_HE
#define BST_HE

#include"BinaryTree.h"

class BinSerTre : public BinTree
{
private:
	BNode* root;
	bool searchNode(BNode* node, int key);
	void insertNode(BNode*& node, int value);
	void displayBST(BNode* node);
	BNode* deleteN(BNode* node , int key);
public:
	BinSerTre();
	~BinSerTre();
	void setRoot(int value);
	int getRoot() const;
	void insert(int value);
	bool search(int key);
	void deleteNode(int key);
	void display();
	BNode* minValueNode(BNode* node);
};
#endif