#include<iostream>
using namespace std;
template<class T>
class MinHeap
{
	T * data;
	int noOfElements;
	int capacity;
	const int INITIAL_CAP = 10;
public:
	MinHeap();
	~MinHeap();
	void insert(T a);
	int getParent(int currentIndex);
	int getLeft(int i);
	int getRight(int i);
	void swap(int * a, int * b);
	bool isFull();
	void resize();
	void heapifyUp(int curr);
	void heapifyDown(int curr);
	T extractMin();
	//void insert(int a);
	void display();
	void decreaseKey(int i, T new_val);
	T getMin();
	void deleteKey(int index);
	bool isValidIndex(int index);
};

template<class T>
MinHeap<T>::MinHeap()
{
	data = new T[INITIAL_CAP];
	noOfElements = 0;
	capacity = INITIAL_CAP;
}

template<class T>
MinHeap<T>::~MinHeap()
{
	delete[]  data ;
	data = nullptr;
	noOfElements = 0;
	capacity = 0;
}

template<class T>
void MinHeap<T>::insert(T a)
{
	if (isFull())
		throw"Tree is Full";
	data[noOfElements] = a;
	heapifyUp(noOfElements);
	noOfElements++;
}

template<class T>
int MinHeap<T>::getParent(int i)
{
	if(i>0)
	{
		int index = (i - 1) / 2;
		if (index >= 0 && index < noOfElements)
		{
			return index;
		}
		throw"Out of Bound";
	}
	return i;
}

template<class T>
int MinHeap<T>::getLeft(int i)
{
	int index = (i * 2) + 1;
	if (index >= 0 && index < noOfElements)
	{
		return index;
	}
	return -1;

}

template<class T>
int MinHeap<T>::getRight(int i)
{
	int index = (i * 2) + 2;
	if (index >= 0 && index < noOfElements)
	{
		return index;
	}
	return -1;
}

template<class T>
void MinHeap<T>::swap(int * a, int * b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
bool MinHeap<T>::isFull()
{
	return (noOfElements == (capacity - 1));
}

template<class T>
void MinHeap<T>::resize()
{
	T * newData = new T[capacity + 10];
	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}
	capacity = capacity + 10;
	delete[]  data;
	data = newData;
}

template<class T>
void MinHeap<T>::heapifyUp(int curr)
{
	int i = curr;
	int p = getParent(i);
	while ((i > 0) && (data[p] > data[i]))
	{
		swap(&data[p], &data[i]);
		i = p;
		p = getParent(i);
	}
}

template<class T>
void MinHeap<T>::heapifyDown(int curr)
{
	int c = curr;
	int leftChild = getLeft(curr);
	int rightChild = getRight(curr);
	while ((rightChild!=-1 && leftChild!=-1) && (data[c]>data[leftChild] || data[c]>data[rightChild]) && c<noOfElements )
	{
		if (data[leftChild] < data[rightChild])
		{
			swap(&data[c], &data[leftChild]);
			c = leftChild;
		}
		else
		{
			swap(&data[c], &data[rightChild]);
			c = rightChild;
		}
		leftChild = getLeft(c);
		rightChild = getRight(c);
	}
	if (leftChild == -1 and rightChild != -1)
	{
		if (data[c] > data[rightChild])
			swap(&data[c], &data[rightChild]);
	}
	else if (leftChild != -1 and rightChild == -1)
	{
		if (data[c] > data[leftChild])
			swap(&data[c], &data[leftChild]);
	}
}

template<class T>
T MinHeap<T>::extractMin()
{
	if (noOfElements == 0)
		throw"Tree Empty ";
	else
	{
		swap(&data[0], &data[(noOfElements-1)]);
		noOfElements--;
		heapifyDown(0);
		return data[noOfElements];
	}
}

template<class T>
void MinHeap<T>::display()
{
	for (int i = 0; i < noOfElements; i++)
	{
		cout << data[i] << " ";
	}
}

template<class T>
T MinHeap<T>::getMin()
{
	if (noOfElements == 0)
		throw"Tree Empty";
	return data[0];
}

template<class T>
void MinHeap<T>::deleteKey(int i)
{
	if (i < noOfElements && noOfElements>0)
	{
		swap(&data[i], &data[noOfElements - 1]);
		noOfElements--;
		heapifyDown(i);
		//swap(&data[0], &data[i]);
		//swap(&data[0], &data[noOfElements-1]);
		//noOfElements--;
		//heapifyDown(0);
	}
	else
	{
		throw"Invalid Inddex to remove";
	}
}

template<class T>
bool MinHeap<T>::isValidIndex(int index)
{
	if (index > 0 && index < noOfElements)
		return true;
	return false;
}

template<class T>
void MinHeap<T>::decreaseKey(int i,T new_val)
{
	if (i < noOfElements && i >= 0)
	{
		if (new_val > data[getLeft(i)] || new_val > data[getRight(i)])
		{
			data[i] = new_val;
			heapifyDown(i);
		}
		else if ((new_val) < (data[getParent(i)]))
		{
			data[i] = new_val;
			heapifyUp(i);
		}
	}
	else
		throw"Invalid INdex to remove";
}
