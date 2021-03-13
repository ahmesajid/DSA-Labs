#ifndef STUDENTMINHEAP_H
#define STUDENTMINHEAP_H
#include"Student.h"
#include<iostream>
#include<stack>
#include<cmath>
#include<string>
using namespace std;
class StudentMinHeap
{
	Student *arr; 
	int curSize; 
	int maxSize; 
public:
	StudentMinHeap(int size)
	{
		maxSize = size;
		curSize = 0;
		arr = new Student[size];
	}
	bool isEmpty()
	{
		return curSize == 0 ? true: false;
	}
	bool isFull()
	{
		return curSize == maxSize ? true : false;
	}
	StudentMinHeap& operator = (StudentMinHeap & ref)
	{
		for (int i = 0; i < ref.curSize; i++)
		{
			ref.arr[i].cgpa = arr[i].cgpa;
			ref.arr[i].name = arr[i].name;
			ref.arr[i].rollNumber = arr[i].rollNumber;
		}
	}
	bool insert(int rn, string n, double c)
	{
		if (!isFull())
		{
			arr[curSize].cgpa = c;
			arr[curSize].name = n;
			arr[curSize].rollNumber = rn;
			curSize++;
			int i = curSize-1;
			while (true)
			{
				if ((i - 1) / 2 >= 0)
				{
					if (c > arr[(i - 1) / 2].cgpa)
					{
						double temp1;
						temp1 = arr[i].cgpa;
						arr[i].cgpa = arr[(i - 1) / 2].cgpa;
						arr[(i - 1) / 2].cgpa = temp1;
						string n;
						n = arr[i].name;
						arr[i].name = arr[(i - 1) / 2].name;
						arr[(i - 1) / 2].name = n;
						int temp;
						temp = arr[i].rollNumber;
						arr[i].rollNumber = arr[(i - 1) / 2].rollNumber;
						arr[(i - 1) / 2].rollNumber = temp;
						i = (i - 1) / 2;
					}
					else
					{
						break;
					}
				}
			}
			return true;
		}
		return false;
	}
	Student extractTopper()
	{
		if (isEmpty())
		{
			cout << "No student\n";
			system("pause");
			exit(0);
		}
		double temp1;
		temp1 = arr[0].cgpa;
		arr[0].cgpa = arr[curSize-1].cgpa;
		arr[curSize-1].cgpa = temp1;
		string n;
		n = arr[0].name;
		arr[0].name = arr[curSize-1].name;
		arr[curSize-1].name = n;
		int temp;
		temp = arr[0].rollNumber;
		arr[0].rollNumber = arr[curSize-1].rollNumber;
		arr[curSize-1].rollNumber = temp;
		curSize--;
		int i = 0;
		while (true)
		{
			if ((2*i)+2<curSize)
			{
				if (arr[(2*i)+1].cgpa > arr[(2*i)+2].cgpa)
				{
					double temp1;
					temp1 = arr[i].cgpa;
					arr[i].cgpa = arr[(2 * i) + 1].cgpa;
					arr[(2 * i) + 1].cgpa = temp1;
					string n;
					n = arr[i].name;
					arr[i].name = arr[(2 * i) + 1].name;
					arr[(2 * i) + 1].name = n;
					int temp;
					temp = arr[i].rollNumber;
					arr[i].rollNumber = arr[(2 * i) + 1].rollNumber;
					arr[(2 * i) + 1].rollNumber = temp;
					i = (2 * i) + 1;
				}
				else
				{
					double temp1;
					temp1 = arr[i].cgpa;
					arr[i].cgpa = arr[(2 * i) + 2].cgpa;
					arr[(2 * i) + 2].cgpa = temp1;
					string n;
					n = arr[i].name;
					arr[i].name = arr[(2 * i) + 2].name;
					arr[(2 * i) + 2].name = n;
					int temp;
					temp = arr[i].rollNumber;
					arr[i].rollNumber = arr[(2 * i) + 2].rollNumber;
					arr[(2 * i) + 2].rollNumber = temp;
					i = (2 * i) + 2;
				}
			}
			else if ((2 * i) + 1 < curSize)
			{
				double temp1;
				temp1 = arr[i].cgpa;
				arr[i].cgpa = arr[(2 * i) + 1].cgpa;
				arr[(2 * i) + 1].cgpa = temp1;
				string n;
				n = arr[i].name;
				arr[i].name = arr[(2 * i) + 1].name;
				arr[(2 * i) + 1].name = n;
				int temp;
				temp = arr[i].rollNumber;
				arr[i].rollNumber = arr[(2 * i) + 1].rollNumber;
				arr[(2 * i) + 1].rollNumber = temp;
				i = (2 * i) + 1;
			}
			else
			{
				break;
			}
		}
		return arr[curSize];
	}
	void displayStudentList()
	{
		double*a = new double[curSize];
		string *st = new string[curSize];
		int *r = new int[curSize];
		for (int i = 0; i < curSize; i++)
		{
			a[i] = arr[i].cgpa;
			st[i] = arr[i].name;
			r[i] = arr[i].rollNumber;
		}
		for (int i = 0; i < curSize-1; i++)
		{
			for (int j = i+1; j < curSize; j++)
			{
				if (a[i] < a[j])
				{
					double temp = a[i];
					string t = st[i];
					int rn = r[i];
					a[i] = a[j];
					st[i] = st[j];
					r[i] = r[j];
					a[j] = temp;
					st[j] = t;
					r[j] = rn;
				}
				if (a[i] == a[j] && r[j]<r[i])//two student with same cgpa will be place according roll number.
				{
					double temp = a[i];
					string t = st[i];
					int rn = r[i];
					a[i] = a[j];
					st[i] = st[j];
					r[i] = r[j];
					a[j] = temp;
					st[j] = t;
					r[j] = rn;
				}
			}
		}
		for (int i = 0; i < curSize; i++)
		{
			cout << st[i] << "\n";
		}
		cout << endl;
	}
	void printHeap()
	{
		int j = 1;
		for (int i = 0; i < curSize; i++)
		{
			if (i == pow(2, j)-1)
			{
				cout << endl;
				j++;
			}
			cout << arr[i].cgpa << " ";
		}
	}
	~StudentMinHeap()
	{
		delete[]arr;
		arr = nullptr;
	}
};
#endif // !STUDENTMAXHEAP_H
