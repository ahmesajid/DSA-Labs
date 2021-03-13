#include "e:\Software Engineering\C++ Programs( Visual Studio)\Data Structures & algorithms ( DSA )\Sessional\MinHeap\MinHeap\MinHeap.h"
#ifndef HEAP_H
#define HEAP_H
#include<iostream>
using namespace std;

template<class T>
class MinHeap
{
private:
	int size;
	int capacity;
	T* data;
protected:
	int parent(int key);
	int leftChild(int par);
	int rightChild(int par);
	void swap(T* x, T* y);
	bool isFull();
	bool isEmpty();
	void reSize();
	void bubbleUp(int index);
public:
	MinHeap();
	~MinHeap();
	MinHeap(int cap);
	void insert(T key);
	void display();
	int getSize() const;
	void decreasekey(int index ,T key);
	T extract();
	void heapify(int index);
	void deleteIndex(int index);
	void replace(int index, T key);
};

#endif

template<class T>
inline int MinHeap<T>::parent(int key)
{
	return (key-1)/2;
}

template<class T>
inline int MinHeap<T>::leftChild(int par)
{
	return (2*par + 1);
}

template<class T>
inline int MinHeap<T>::rightChild(int par)
{
	return (par * 2 + 2);
}

template<class T>
inline void MinHeap<T>::swap(T* x, T* y)
{
	T temp = *y;
	*y = *x;
	*x = temp;
}

template<class T>
inline bool MinHeap<T>::isFull()
{
	return size == capacity;
}

template<class T>
inline bool MinHeap<T>::isEmpty()
{
	return size == 0;
}

template<class T>
inline void MinHeap<T>::reSize()
{
	MinHeap<T> newMH(int(capacity * 1.5));
	newMH.size = this->size;
	for (int i = 0 ; i < this->size ; i++)
	{
		newMH.data[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newMH.data;
	this->size = newMH.size;
	this->capacity = newMH.capacity;
	newMH.data = nullptr;
}

template<class T>
inline void MinHeap<T>::bubbleUp(int index)
{
	int par = parent(index);
	while (index >= 0 && data[par] > data[index])
	{
		swap(&data[par], &data[index]);
		index = par;
		par = parent(index);
	}
}

template<class T>
inline MinHeap<T>::MinHeap()
{
	size = 0; 
	capacity = 0;
	data = nullptr;
}

template<class T>
inline MinHeap<T>::~MinHeap()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
	}
}

template<class T>
inline MinHeap<T>::MinHeap(int cap)
{
	if (cap > 0)
	{
		size = 0;
		capacity = cap;
		data = new T[capacity];
	}
	else
	{
		size = 0;
		capacity = 0;
		data = nullptr;
	}
}

template<class T>
inline void MinHeap<T>::insert(T key)
{
	if (!isFull() && this->data)
	{
		data[size] = key;
		int i = size;
	 	size++;
		int par = parent(i);
		while (i >= 0 && data[i] < data[par])
		{
			swap(&data[i], &data[par]);
			i = par;
			par = parent(i);
		}
	}
}

template<class T>
inline void MinHeap<T>::display()
{
	if (data)
	{
		for (int i = 0 ; i < size ; i++)
		{
			cout << data[i] << " ";
		}
	}
}

template<class T>
inline int MinHeap<T>::getSize() const
{
	return size;
}

template<class T>
inline void MinHeap<T>::decreasekey(int index, T key)
{
	if (data && index >= 0 && index < size)
	{
		data[index] = key;
		int i = index;
		int par = parent(i);
		while (i >= 0 && data[i] < data[par])
		{
			swap(&data[i], &data[par]);
			i = parent(i);
			par = parent(i);
		}
	}
}

template<class T>
inline T MinHeap<T>::extract()
{
	if (data && size == 1)
	{
		size--;
		return data[size];
	}
	else if (data)
	{
		T val = data[0];
		int i = size - 1;
		data[0] = data[i];
		size--;
		heapify(0);
		return val;
	}
}

template<class T>
inline void MinHeap<T>::heapify(int index)
{
	if (index >= 0 && index < size)
	{
		int temp = index;
		int l = leftChild(index);
		int r = rightChild(index);
		if (index < size && l < size && data[index]> data[l])
		{
			temp = l;
		}
		if (index < size && r < size && data[index] > data[r])
		{
			temp = r;
		}
		if (index != temp)
		{
			swap(&data[index], &data[temp]);
			heapify(temp);
		}
	}
}

template<class T>
inline void MinHeap<T>::deleteIndex(int index)
{
	if (data && index >0 && index < size)
	{
		data[index] = data[--size];
		swap(&data[0], &data[index]);
		heapify(0);
	}
}

template<class T>
inline void MinHeap<T>::replace(int index, T key)
{
	if (data && index >= 0 && index < size)
	{
		data[index] = key;
		bubbleUp(index);
		heapify(index);
	}
}
