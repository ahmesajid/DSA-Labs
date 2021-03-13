#include<iostream>
#include"AVLTree.h"

using namespace std;

int main()
{
	{
		AVLTree<int> avlt;
		avlt.insert(10);
		avlt.insert(20);
		avlt.insert(30);
		avlt.insert(40);
		avlt.insert(50);
		avlt.insert(25);
		avlt.deleteNode(25);
		avlt.preOrder();
	}

	system("pause");
	return 0;
}

