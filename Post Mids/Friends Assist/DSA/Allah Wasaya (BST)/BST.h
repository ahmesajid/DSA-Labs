#ifndef BINARY_TREE_H
#define BINARY_TREE_H
template <typename T>
struct BSTNode
{
	T key_value;
	BSTNode<T> *left;
	BSTNode<T> *right;
	BSTNode()
	{
		left = nullptr;
		right = nullptr;
	}
};
template <typename T>
class BST
{
private:
	BSTNode<T>*root;
	void destroy_BST(BSTNode<T> *root)
	{
		if (root!= NULL)
		{
			destroy_BST(root->left);
			destroy_BST(root->right);
			delete root;
		}
	}
	
	BSTNode<T> *search(T key, BSTNode<T> *leaf)
	{
		if (leaf != NULL)
		{
			if (key == leaf->key_value)
			{
				return leaf;
			}
			else
			{
				BSTNode<T>*a = nullptr;
				a = search(key, leaf->left);
				BSTNode<T>*b = nullptr;
				b = search(key, leaf->right);
				if (a != nullptr)
				{
					return a;
				}
				else if (b != nullptr)
				{
					return b;
				}
				else
				{
					return nullptr;
				}
			}
		}
		else return nullptr;
	}
	bool levelCounter(BSTNode<T>* root, int level)
	{
		if (root == nullptr)
			return false;

		if (level == 0)
		{
			return true;
		}
		bool left = levelCounter(root->left, level - 1);
		bool right = levelCounter(root->right, level - 1);
		return left || right;
	}
	int  heightOfBST(BSTNode<T>* root)
	{
		int level = 0;
		while (levelCounter(root, level))
			level++;
		return level;
	}
	bool printLevel(BSTNode<T>* root, int level)
	{
		if (root == nullptr)
			return false;

		if (level == 1)
		{
			cout << root->key_value << ' ';
			return true;
		}
		bool left = printLevel(root->left, level - 1);
		//cout << endl;
		bool right = printLevel(root->right, level - 1);
		
		return left || right;
	}
	void levelOrderTraversal(BSTNode<T>* root)
	{
		int level = 1;
		while (printLevel(root, level))
		{
			level++;
			cout << endl;
		}
			
	}
	bool checkAndInsert(T key, BSTNode<T> *leaf)
	{
		if (this->search(key) != nullptr)
			return false;
		insert(key, leaf);
		return true;
	}

	void insert(T key, BSTNode<T> *leaf)
	{
		if (this->root == nullptr)
		{
			this->setRoot(key);
		}
		else if (key< leaf->key_value)
		{
			if (leaf->left != NULL)
				insert(key, leaf->left);
			else
			{
				leaf->left = new BSTNode<T>;
				leaf->left->key_value = key;
				leaf->left->left = NULL;    //Sets the left child of the child node to null
				leaf->left->right = NULL;   //Sets the right child of the child node to null
			}
		}
		else if (key >= leaf->key_value)
		{
			if (leaf->right != NULL)
			{
				insert(key, leaf->right);
			}
			else
			{
				leaf->right = new BSTNode<T>;
				leaf->right->key_value = key;
				leaf->right->left = NULL;  //Sets the left child of the child node to null
				leaf->right->right = NULL; //Sets the right child of the child node to null
			}
		}
	}
	void setRoot(T val)
	{
		if (root == nullptr)
		{
			root = new BSTNode<T>;
			root->key_value = val;
		}
	}
	void displayAscending(BSTNode<T>*root)
	{
		if (root== NULL)
			return;
		displayAscending(root->left);
		cout << root->key_value << " ";
		displayAscending(root->right);
	}
	void displayDescending(BSTNode<T>*root)
	{
		if (root == NULL)
			return;
		displayDescending(root->right);
		cout << root->key_value << " ";
		displayDescending(root->left);
	}
	BSTNode<T>* minValueNode(BSTNode<T>* node)
	{
		BSTNode<T>* current = node;
		while (current && current->left != NULL)
			current = current->left;

		return current;
	}
	BSTNode<T>* deleteNode(BSTNode<T>* root, int key)
	{
		if (root == nullptr) 
			return root;
		if (key < root->key_value)
		root->left = deleteNode(root->left, key);
		else if (key > root->key_value)
			root->right = deleteNode(root->right, key);
		else
		{
			if (root->left == nullptr)
			{
				BSTNode<T> *temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == nullptr)
			{
				BSTNode<T>*temp = root->left;
				free(root);
				return temp;
			}
			BSTNode<T>* temp = minValueNode(root->right);
			root->key_value = temp->key_value;
			root->right = deleteNode(root->right, temp->key_value);
		}
		return root;
	}
	void leftRotation(BSTNode<T>*z)
	{
		BSTNode<T>*temp1 = z->right;
		BSTNode<T>*temp2 = temp1->left;
		temp1->left = z;
		z->right = temp2;
	}
public:
	void leftRotation(T key);
	BST();
	~BST();
	bool empty();
	bool insert(T key);
	BSTNode<T>* search(int key);
	void clear();
	int getHeightOfBST();
	bool find(T key);
	void display(bool flag = true);
	void deleteNode(T val);
	void levelTraversal();

};
#endif
