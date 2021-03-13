#include<iostream>
#include"MinHeap.h"

using namespace std;

int main()
{
	MinHeap<int> mh(10);
	mh.insert(1);
	mh.insert(2);
	mh.insert(-2);
	mh.insert(3);
	mh.insert(5);
	mh.insert(-9);
	mh.decreasekey(5 ,-10);
	//mh.extract();
	//mh.deleteIndex(2);
	mh.replace(0, -15);
	mh.display();
	system("pause");
	return 0;
}