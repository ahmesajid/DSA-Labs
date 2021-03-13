#include<iostream>
using namespace std;
template <typename T>
struct BSTNode
{
	T data;
	BSTNode<T> *left, *right;
public:
	BSTNode();
	BSTNode(T n);
	//~BSTNode();
};
template <typename T>
class BST
{
	BSTNode<T> * root;
	void displayDescending();
	void displayAscending();
public:
	void displayDescendingHelper(BSTNode<T> * n);
	void displayAscendingHelper(BSTNode<T> * n);
	BST();
	~BST();
	void destructorHelper(BSTNode<T> * n);
	void displayit();
	void displayHelper(BSTNode<T> * n);//VLR
	bool isEmpty();
	bool insert(T);
	bool insertHelper(BSTNode<T>*& n, T key);
	bool remove(T key);
	void clear();
	int height();
	int heigthHelper(BSTNode<T> * n);
	int noOfNodes();
	int noOfNodesHelper(BSTNode<T> * n);
	bool find(T);
	bool findHelper(BSTNode<T> * n,T key);
	void display(bool = true);
	void distinctCount();
};

template<typename T>
 BSTNode<T>::BSTNode()
{
	 data = T();
	 left = right = nullptr;
}

 template<typename T>
 BSTNode<T>::BSTNode(T n)
 {
	 data = n;
	 left = right = nullptr;
 }

 template<typename T>
 void BST<T>::displayAscending()
 {
	 displayAscendingHelper(root);
 }

 template<typename T>
 void BST<T>::displayDescending()
 {
	 displayDescendingHelper(root);
 }

 template<typename T>
 void BST<T>::displayDescendingHelper(BSTNode<T>* n)
 {
	 if (n->right != nullptr)
	 {
		 displayDescendingHelper(n->right);
	 }
	 if (n)
		 cout << n->data << " ";
	 if (n->left != nullptr)
		 displayDescendingHelper(n->left);
 }

 template<typename T>
 void BST<T>::displayAscendingHelper(BSTNode<T>* n)
 {
	 if (n->left != nullptr)
	 {
		 displayAscendingHelper(n->left);
	 }
	 if (n)
		 cout << n->data << " ";
	 if (n->right != nullptr)
		 displayAscendingHelper(n->right);
 }

 
 template<typename T>
 BST<T>::BST()
 {
	 root = nullptr;
 }

 template<typename T>
 BST<T>::~BST()
 {
	 destructorHelper(root);
 }

 template<typename T>
 void BST<T>::destructorHelper(BSTNode<T>* n)
 {
	 if (root)
	 {
		 if (n->right != nullptr)
		 {
			 destructorHelper(n->right);
		 }
		 if (n->left != nullptr)
		 {
			 destructorHelper(n->left);
		 }
		 delete n;
		 n = nullptr;
	 }
	 root = nullptr;
 }

 template<typename T>
 void BST<T>::displayit()
 {
	 displayHelper(root);
 }

 template<typename T>
 void BST<T>::displayHelper(BSTNode<T>* n)
 {
	 if (n == nullptr)
		 return;
	 if (n)
	 {
		 cout << n->data << " ";
	 }
	 displayHelper(n->left);
	 displayHelper(n->right);
 }

 template<typename T>
 bool BST<T>::isEmpty()
 {
	 if (root)
		 return true;
	 return false;
 }

 template<typename T>
 bool BST<T>::insert(T key)
 {
	 
	 return insertHelper(root,key);
 }

 template<typename T>
 bool BST<T>::insertHelper(BSTNode<T>*& n, T key)
 {
	 if (n == nullptr)
	 {
		 n = new BSTNode<T>(key);
		 return true;
	 }
	 else
	 {
		 if (n->data > key)
		 {
			 insertHelper(n->left, key);
		 }
		 else if(n->data<key)
		 {
			 insertHelper(n->right, key);
		 }
		 else 
			 return false;
	 }
 }

 template<typename T>
 void BST<T>::clear()
 {
	 if(root)
	 this->~BST();

 }

 template<typename T>
 int BST<T>::height()
 {
	  return  heigthHelper(root);
 }

 template<typename T>
 int BST<T>::heigthHelper(BSTNode<T>* n)
 {
	 if (n == nullptr)
		 return 0;
	 int leftAns = 1 + heightOfTreeHelper(n->left);
	 int rightAns = 1 + heightOfTreeHelper(n->right);
	 if (leftAns > rightAns)
		 return leftAns;
	 else
		 return rightAns;
 }

 template<typename T>
 int BST<T>::noOfNodes()
 {
	 return noOfNodesHelper(root);
 }

 /*template<typename T>
 int BST<T>::size()
 {
	 return sizeHelper(root);
 }*/

 /*template<typename T>
 int BST<T>::sizeHelper(BSTNode<T>* n)
 {
	 if (n == nullptr)
		 return 0;
	 int leftNodes = 1 + sizeHelper(n->left);
	 int rightNodes = 1 + sizeHelper(n->right);
	 cout << "Left Nodes= " << leftNodes << "\n";
	 cout << "Righ Nodes= " << rightNodes << "\n";
	 return (leftNodes+rightNodes);
 }*/

 template<typename T>
 int BST<T>::noOfNodesHelper(BSTNode<T>* n)
 {
	 if (n == nullptr)
		 return 0;
	 return (1 + noOfNodesHelper(n->left) + noOfNodesHelper(n->right));
 }

 template<typename T>
 bool BST<T>::find(T key)
 {
	 
	 return findHelper(root, key);
 }

 template<typename T>
  bool BST<T>::findHelper(BSTNode<T>* n,T key)
 {
	  if (n == nullptr)
		  return false;
	  else if (n->data == key)
	  {
		  return true;
	  }
	  else
	  {
		  return(findHelper(n->left, key) || findHelper(n->right, key));
	  }
 }

  template<typename T>
  void BST<T>::display(bool flag)
  {
	  if (flag)
		  displayAscending();
	  else
	  {
		  displayDescending();
	  }
  }

  template<typename T>
  void BST<T>::distinctCount()
  {
	  int testCases;
	  cin >> testCases;
	  if (testCases >= 1 && testCases < 50)
	  {
		  for (int i = 0; i < testCases; i++)
		  {
			  int sizeOfArray;
			  int distintCount;
			  cin >>sizeOfArray>> distintCount;
				  BST<int> a;
			  for (int j = 0; j < sizeOfArray; j++)
			  {
				  int k;
				  cin >> k;
				  a.insert(k);
			  }
			  if (a.noOfNodes() < distintCount)
				  cout << "Bad\n";
			  else if (a.noOfNodes() > distintCount)
				  cout << "Average\n";
			  else
				  cout << "Good\n";
		  }
	  }
  }
