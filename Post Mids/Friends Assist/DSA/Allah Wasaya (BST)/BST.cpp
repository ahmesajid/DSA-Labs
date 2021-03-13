#include <iostream>
#include "BST.h"
using namespace std;
template <typename T>
void BST<T>::leftRotation(T key)
{
	BSTNode<T>*z = this->search(key);
	BSTNode<T>*temp1 = z->right;
	BSTNode<T>*temp2 = temp1->left;
	temp1->left = z;
	z->right = temp2;
	this->root = temp1;
}
template <typename T>
void BST<T>::levelTraversal()
{
	this->levelOrderTraversal(root);
}
template <typename T>
BST<T>::BST()
{
	this->root = nullptr;
}
template <typename T>
BST<T>::~BST()
{
	this->destroy_BST(this->root);
}
template <typename T>
bool BST<T>::empty()
{
	if (this->root == nullptr)
		return true;
	return false;
}

template <typename T>
BSTNode<T> *BST<T>::search(int key)
{
	return search(key, root);
}
template <typename T>
bool BST<T>::insert(T key)
{
	return checkAndInsert(key,root);
}
template <typename T>
void BST<T>::clear()
{
	this->destroy_BST();
}
template <typename T>
int BST<T>::getHeightOfBST()
{
	return heightOfBST(root);
}
template <typename T>
bool BST<T>:: find(T key)
{
	if (this->search(key) == nullptr)
		return false;
	return true;
}

template <typename T>
void BST<T>::display(bool flag)
{
	if (flag == true)
	{
		this->displayAscending(root);
	}
	else if(flag==false)
	{
		this->displayDescending(root);
	}
}
template <typename T>
void BST<T>::deleteNode(T val)
{
	deleteNode(this->root, val);
}