#ifndef BINTRE_H
#define BINTRE_H

class BNode
{
public:
	int data;
	BNode* left;
	BNode* right;
	BNode()
	{
		left = right = nullptr;
	}
	BNode(int value)
	{
		data = value;
		left = right = nullptr;
	}
};


class BinTree
{
private:
	BNode *root;
protected:
	void destroyNode(BNode* node)
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
	BNode* findNode(BNode* node, int value);
	void display(BNode* node);
	BNode* findParent(BNode* node , int value);
	void preintPreorder(BNode * node);
	void printInorder(BNode* node);
	void printPostorder(BNode* node);
	void parenthesizedView(BNode* node);
	void createCopy(BNode*& temp, const BNode* node);
	bool isBinSerTre(BNode* node);
public:
	BinTree();
	~BinTree()
	{
		if (this->root != nullptr)
		{
			destroyNode(root);
			root = nullptr;
		}
	}
	void setRoot(int value);
	int getRoot() const;
	BNode* getRootNode()const;
	void setLeftChild(int parent, int child);
	void setRightChild(int parent, int child);
	void displayDiscendants(int value);
	int getParent(int value);
	void remove(int value)
	{
		BNode*temp = findNode(root, value);
		if (temp != nullptr)
		{
			BNode*parent = findParent(root, value);
			destroyNode(temp);
			if (parent->right == temp)
			{
				parent->right = nullptr;
			}
			else
			{
				parent->left = nullptr;
			}

		}
	}
	void preOrder();
	void inOrder();
	void postOrder();
	void displayParenthesizedView();
	bool findNodE(int value);
	int findSibiling(int value);
	BinTree& operator = (const BinTree& ref);
	bool isBST();
};
#endif
