#include<iostream>
#include"MemoryManager.h"
using namespace std;
int main()
{
	MemoryManager manager(20);
	cout<<manager.allocateMemory(21);
	cout << manager.allocateMemory(7);
	cout << manager.allocateMemory(7);
	cout << manager.allocateMemory(1);
	cout << "\n";
	manager.displayMemory();
	manager.deAllocateMemory(1);
	manager.deAllocateMemory(13);
	manager.displayMemory();
	manager.allocateMemory(3);
	manager.allocateMemory(6);
	manager.displayMemory();

	cout << "Press Enter key to continue...\n";
	cin.get();
	return 0;
}