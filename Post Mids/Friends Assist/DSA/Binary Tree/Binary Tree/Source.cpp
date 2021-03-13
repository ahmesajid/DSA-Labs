#include<iostream>
#include"BinaryTree.h"
//#include"BinarySearchTree.h"
//#include"AVLTree.h"

using namespace std;

int main()
{
	/*{
	AVLTree avlt;
	avlt.insert(10);
	avlt.insert(20);
	avlt.insert(30);
	avlt.insert(40);
	avlt.insert(50);
	avlt.insert(25);
	avlt.preOrder();
	*/
	//{
	//	BinSerTre bst1;
	//	bst1.setRoot(4);
	//	bst1.insert(2);
	//	bst1.insert(6);
	//	bst1.insert(7);
	//	bst1.insert(5);
	//	bst1.insert(1);
	//	bst1.insert(3);
	//	bst1.deleteNode(4);
	//	bst1.display();
	//	//cout << bst1.search(9) << "\n";
	//}	//bst1.displayDiscendants(4);

	/*BinTree bt1;
	bt1.setRoot(4);
	bt1.setLeftChild(4, 2);
	bt1.setRightChild(4, 6);
	bt1.setLeftChild(2, 1);
	bt1.setRightChild(2, 3);
	bt1.setLeftChild(6, 5);
	bt1.setRightChild(6, 7);
	bt1.setLeftChild(1, 2);
	bt1.setRightChild(1, 0);
	BNode* root = bt1.getRootNode();
	printSecondLargest(root);*/
	//bt1.setLeftChild(1,2);
	//bt1.setRightChild(1,3);
	//bt1.setLeftChild(2, 4);
	//bt1.setRightChild(2, 5);
	//bt1.setLeftChild(3, 6);
	//bt1.setRightChild(3, 7);
	//bt1.setLeftChild(5, 8);
	//bt1.setRightChild(6, 9);
	//cout << bt1.getParent(9)<< "\n";
	//bt1.displayDiscendants(1);
	//bt1.remove(2);
	//bt1.displayDiscendants(1);
	//bt1.preOrder();
	//cout << "\n";
	//bt1.inOrder();
	//cout << "\n";
	//bt1.postOrder();
	//cout << "\n";
	//bt1.displayParenthesizedView();
	//cout <<bt1.findSibiling(10)<< "\n";
	/*cout << bt1.findSibiling(2) << "\n";
	*/
	//BinTree bt2;
	//bt2 = bt1;
	//bt2.displayDiscendants(1);
	//cout<<bt1.isBST()<<"\n";
	BinTree bt1
		bt1.setRoot(4);
	bt1.setLeftChild(4, 2);
	bt1.setRightChild(4, 6);
	bt1.setLeftChild(2, 1);
	bt1.setRightChild(2, 3);
	bt1.setLeftChild(6, 5);
	bt1.setRightChild(6, 7);
	bt1.setLeftChild(1, 2);
	bt1.setRightChild(1, 0);
	bt1.displayParenthesizedView();
	system("pause");
	return 0;
}

int main();

void printSecondLargest(BNode* root);
void finLargest(BNode* node , int &max);
void findSecondLargest(BNode* node, int max , int &temp);

void printSecondLargest(BNode* root)
{
	int max = INT_MIN, secMax = INT_MIN, temp;
	finLargest(root, max);
	cout << max << "\n";
	findSecondLargest(root, max, secMax);
	cout << secMax << "\n";
}

void finLargest(BNode* node, int& max)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->data > max)
	{
		max = node->data;
	}
	finLargest(node->left, max);
	finLargest(node->right, max);
}

void findSecondLargest(BNode* node, int max, int& temp)
{
	if (node == nullptr) 
		return;
	if (node->data > temp && node->data < max)
		temp = node->data;
	findSecondLargest(node->left, max, temp);
	findSecondLargest(node->right, max, temp);
}
