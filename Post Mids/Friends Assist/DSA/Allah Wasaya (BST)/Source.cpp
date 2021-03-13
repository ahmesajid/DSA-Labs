#include <iostream>
#include "BST.cpp"
#include "BST.h"
using namespace std;

int main()
{
	BST<int>a;
	a.insert(5);
	a.insert(7);
	a.insert(9);
	a.deleteNode(9);
	a.levelTraversal();
	a.leftRotation(5);
	cout << "After \n";
	a.levelTraversal();
	//cout << 'h' << endl;
	
	return 0;
}