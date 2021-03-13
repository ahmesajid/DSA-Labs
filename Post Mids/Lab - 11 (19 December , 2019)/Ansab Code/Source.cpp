#include<iostream>
#include"StudentMaxHeap.h"
using namespace std;
int main()
{
	StudentMaxHeap s(15);
	s.insert(31, "ashar", 3.67);
	s.insert(12, "abdullah", 3.42);
	s.insert(15, "Ali", 3.75);
	s.insert(34, "haris", 3.54);
	s.insert(30, "saeed", 2.7);

	s.insert(33, "butt", 2.65);
	s.insert(32, "azan", 3.32);
	s.insert(24, "joji", 2.65);
	s.insert(56, "AbdulRehman", 2.75);
	s.insert(36, "muneeb", 2.9);

	s.insert(1, "ahsan", 2.85);
	s.insert(5, "zain", 3.3);
	s.insert(10, "azaz", 3.6);
	s.insert(26, "abubakar", 2.9);
	s.insert(29, "usama", 3.1);

	/*

	cout << "Enter size you want to make array\n";
	int n;
	cin >> n;
	StudentMaxHeap s(n);*/

	int c;
	do
	{
		cout << "1. Enter a new student\n";
		cout << "2. remove and display student with max cgpa\n";
		cout << "3. display list of student descending\n";
		cout << "4. display list in level order\n";
		cout << "5. exit\n";

		cout << "\n Enter your choice:\n";
		cin >> c;
		if (c == 1)
		{
			string name;
			cout << "Enter name of student\n";
			cin >> name;
			double cgpa;
			cout << "Enter cgpa of student\n";
			cin >> cgpa;
			int rl;
			cout << "Enter roll no. of student\n";
			cin >> rl;
			bool f=s.insert(rl, name, cgpa);
			system("cls");
			if (f)
				cout << "\n\n\n\t\t\tStudent data inserted sucessfully\n\n\n\n";
			else
				cout << "\n\n\n\t\t\tStudent data NOT inserted \n\n\n\n";
		}
		else if (c == 2)
		{
			Student st= s.extractTopper();
			cout << "Name : \t" << st.getName() << "\n";
			cout << "CGPA : \t" << st.getCGPA() << "\n";
			cout << "Roll Number : \t" << st.getRollNumber() << "\n";

			system("pause");
			system("cls");
		}
		else if (c == 3)
		{
			s.displayStudentList();
			system("pause");
			system("cls");
		}
		else if (c == 4)
		{
			s.printHeap();
			system("pause");
			system("cls");
		}
		else
		{
			system("pause");
			exit(0);
		}
	} while (true);
	system("pause");
	return 0;
}