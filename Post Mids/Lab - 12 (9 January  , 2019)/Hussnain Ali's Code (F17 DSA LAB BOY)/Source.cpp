#include<iostream>
using namespace std;
#include"Graph.h"
int main()
{
	cout << "Enter number of vertices: ";
	int n;
	cin >> n;
	Graph g(n);
	while (1)
	{
		cout << "Press 1 to add edge.\n";
		cout << "Press 2 to remove edge.\n";
		cout << "Press 3 to display edge.\n";
		cout << "Press 4 to display depth first.\n";
		cout << "Press 5 to display breath first.\n";
		cout << "Press any key to exit\n\n\n";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter number of first vertice : ";
			int v1, v2;
			cin >> v1;
			cout << "Enter number of second vertice : ";
			cin >> v2;
			g.addEdge(v1, v2);
			cout << "\n\n\n";
		}
		else if (choice == 2)
		{
			cout << "Enter number of first vertice : ";
			int v1, v2;
			cin >> v1;
			cout << "Enter number of second vertice : ";
			cin >> v2;
			g.deleteEdge(v1,v2);
			cout << "\n\n\n";
		}
		else if (choice == 3)
		{
			g.display();
			cout << "\n\n\n";
		}
		else if (choice == 4)
		{
			cout << "Enter number of vertice where you want to start: ";
			int v1;
			cin >> v1;
			g.depthFirst(v1);
			cout << "\n\n\n";
		}
		else if (choice == 5)
		{
			cout << "Enter number of vertice where you want to start: ";
			int v1;
			cin >> v1;
			g.breathFirst(v1);
			cout << "\n\n\n";
		}
		else
			break;
	}


	system("pause");
	return 0;
}