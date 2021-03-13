#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;
class Student
{
	friend class StudentMinHeap;
private:
	string name;
	double cgpa;
	int rollNumber;
public:
	Student()
	{

	}
	Student(string n, double c, int rn)
	{
		name = n;
		cgpa = c;
		rollNumber = rn;
	}
	string getName()
	{
		return name;
	}
	double getCGPA()
	{
		return cgpa;
	}
	int getRollNumber()
	{
		return rollNumber;
	}
};

#endif // !STUDENT_H
