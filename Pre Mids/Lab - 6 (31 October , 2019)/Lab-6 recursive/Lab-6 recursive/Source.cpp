#include<iostream>
#include<string>

using namespace std;
void printSeperately(int);
void printBinary(int);
bool isPalindrome(int);
bool checkPrime(int num);
bool isSubStringFound(string str1, string str2, int index1, int index2);
bool isPrime(int num, int counter);
int returnCharactersCount(string);
int assistCount(string name, int count);
void evenDigit(int num);
int main()
{
	
	string s1, s2;
	cout << "Enter first String ";
	getline(cin, s1);
	cout << "Enter second String ";
	getline(cin, s2);
	if (isSubStringFound(s1, s2, 0, 0))
	{
		cout << "Substring is present \n";
	}
	else
	{
		cout << "substring is not present " << endl;
	}

	/*int num;
	cin >> num;
	evenDigit(num);*/

	/*
	int i = returnCharactersCount("ahmerbinsajid");
	cout << i;*/
/*
    bool isPrime=checkPrime(3);
	if (isPrime)
		cout << "prime\n";
	else
		cout << "not-prime!\n";
*/

	cout << '\n';
	return 0;
}
void evenDigit(int num)
{
	int temp;
	if (num == 0)
		return;
	temp = num % 10;
	evenDigit(num / 10);
	if (temp % 2 == 0)
		cout << temp;

}


int assistCount(string name, int count)
{
	int toReturn = 0;
	if (name[count] != '\0')
	{ 
		toReturn = 1 + assistCount(name, count + 1);
	
	}
	else
	{
		return 0;

	}
	return toReturn;
}
int returnCharactersCount(string name)
{
	int counter = 0;
	counter = assistCount(name , counter);
	return counter;
}bool isSubStringFound(string str1, string str2, int index1, int index2)
{
	if (str1[index1] == '\0')
		{
			return false;
		}
	if (str1[index1] == str2[index2])
		{
			if (str2[index2 + 1] == '\0')
			{
	 			return true;
			}
			return isSubStringFound(str1, str2, index1 + 1, index2 + 1);
		}
	return isSubStringFound(str1, str2, index1 + 1,index2);
}

bool isPrime(int num, int counter)
{
	if (num%counter == 0)
	{
		return false;
	}
	else if (counter >= num / 2)
	{
		return true;
	}
	else
	{
		isPrime(num, counter + 1);
	}
}


bool checkPrime(int num)
{
	if (num == 1 || num == 0 || num==2)
	{
		return false;
	}
	int counter = 1;
	bool status = isPrime(num, counter+1);

	if (status)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void printBinary(int num) //
{
	if (num == 0)
	{
		return;
	}
	int var = num % 2;
	printBinary(num / 2);
	cout << var;
}


void printSeperately(int num) 
{
	if (num == 0)
	{
		return;
	}

	int var = num % 10;
	printSeperately(num/10);
	cout << var<<'\n';

}
