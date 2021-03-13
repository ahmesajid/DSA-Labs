#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<queue>
using namespace std;
class Graph
{
private:
	int noOfVertices;
	int** graph;
	void depthFirst(int startVertex, bool flag[])
	{
		if (!flag[startVertex-1])
		{
			cout << "v" << startVertex << " ";
			flag[startVertex-1] = true;
		}
		else
		{
			return;
		}
		for (int i = 0; i < noOfVertices; i++)
		{
			if (graph[startVertex-1][i])
			{
				depthFirst(i + 1, flag);
			}
		}
	}
	void breathFirst(int startVertex, bool flag[])
	{
		queue<int> q;
		q.push(startVertex);

		int index = -1;
		while (!q.empty())
		{
			index = q.front();
			q.pop();
			if (!flag[index - 1])
			{
				cout << "v" << index << " ";
				flag[index - 1] = true;
				for (int i = 0; i < noOfVertices; i++)
				{
					if (graph[index - 1][i])
					{
						q.push(i + 1);
					}
				}
			}
		}
	}
public:
	Graph(int vertices) 
	{
		if (vertices < 0)
		{
			noOfVertices = 0;
		}
		else
		{
			noOfVertices = vertices;
		}
		graph = new int*[noOfVertices];
		for (int i = 0; i < noOfVertices; i++)
		{
			graph[i] = new int[noOfVertices];
		}
		for (int i = 0; i < noOfVertices; i++)
		{
			for (int j = 0; j < noOfVertices; j++)
			{
				graph[i][j] = 0;
			}
		}
	}
	void addEdge(int v1, int v2)
	{
		if ((v1 > 0 && v1 <= noOfVertices) && (v2 > 0 && v2 <= noOfVertices))
		{
			graph[v1-1][v2-1] = 1;
			graph[v2-1][v1-1] = 1;
		}
		else
		{
			cout << "\n\n\t\tInvalid Vertice\n\n";
		}
	}
	void deleteEdge(int v1, int v2)
	{
		if ((v1 > 0 && v1 <= noOfVertices) && (v2 > 0 && v2 <= noOfVertices))
		{
			graph[v1-1][v2-1] = 0;
			graph[v2-1][v1-1] = 0;
		}
		else
		{
			cout << "\n\n\t\tInvalid Vertice\n\n";
		}
	}
	void display()
	{
		for (int i = 0; i < noOfVertices; i++)
		{
			cout << "v" << i + 1<<" : ";
			for (int j = 0; j < noOfVertices; j++)
			{
				if (graph[i][j])
				{
					cout << "v" << j + 1 << "  ";
				}
			}
			cout << endl;
		}
	}
	void depthFirst(int startVertex)
	{
		if (startVertex > 0 && startVertex <= noOfVertices)
		{
			bool *flag = new bool[noOfVertices];
			for (int i = 0; i < noOfVertices; i++)
			{
				flag[i] = false;
			}
			depthFirst(startVertex, flag);
		}
		else
		{
			cout << "Invalid Index\n";
		}
	}
	void breathFirst(int startVertex)
	{
		if (startVertex > 0 && startVertex <= noOfVertices)
		{
			bool *flag = new bool[noOfVertices];
			for (int i = 0; i < noOfVertices; i++)
			{
				flag[i] = false;
			}
			breathFirst(startVertex, flag);
		}
		else
		{
			cout << "Invalid Index\n";
		}
	}
	~Graph()
	{
		if (noOfVertices)
		{
			for (int i = 0; i < noOfVertices; i++)
			{
				delete[]graph[i];
				graph[i] = nullptr;
			}
			delete[] graph;
			graph = nullptr;
		}
	}
};
#endif // !GRAPH_H
