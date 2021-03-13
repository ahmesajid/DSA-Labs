#include"BinarySearchTree.h"
#include<iostream>
using namespace std;
int main()
{
	BST bst;
	bst.setRoot(9);
	bst.insert(6);
	bst.insert(10);
	bst.insert(3);
	bst.insert(7);
	bst.insert(1);
	bst.insert(111);
	bst.insert(2);
	bst.insert(0);
	bst.insert(99);
//	bst.removeAnode(111);
	bst.displayDescending();
	int x=bst.hei();
	cout << x;
}