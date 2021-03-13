#include"MinHeap.h"
using namespace std;
int main()
{
	try {
		MinHeap<int> a;
		a.insert(1);
		a.insert(5);
		a.insert(6);
		a.insert(8);
		a.insert(9);
		a.insert(11);
		a.insert(12); 
		
		//a.display();


		cout << "\n";
		a.deleteKey(1);

		a.display();
		
		cout << "\n";
		//a.display();
	}
	catch (const char * n)
	{
		cout << n;
	}
	//system("pause");
	return 0;
}
