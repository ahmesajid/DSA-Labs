#include"HashMap.h"
#include<iostream>
using namespace std;
int main()
{
	try {
		StringHash a;
		string k = "BSEF17M";
		cout << a.getHash(k);
		
	}
	catch (const char * n)
	{
		cout << n;
	}
	return 0;
}