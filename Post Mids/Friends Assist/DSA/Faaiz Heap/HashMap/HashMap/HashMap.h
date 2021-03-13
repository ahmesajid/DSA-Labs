#include"LinkedList.h"
#include<iostream>
#include<string>
#include<math.h>
#include<ctime>
using namespace std;
struct Pair
{
    string key;
	string value;
	Pair(string &k, string &v)
	{
		key = k;
		value = v;
	}
};
class StringHash
{

	LinkedList<Pair> hashTAble[256];
	int noOFElements;
//protected:
public:
	int getHash(const string & key);
	StringHash();
	bool insert(string & key, string & value);
	bool remove(const string & key);
	bool find(const string & value);
	bool empty();
	bool clear();
	int size();
	string & operator[](const string & key);
	~StringHash();
	void encodeURL(string & url,int key);
	Pair decodeURl(int key);
	
	
	
	int * storeArray(int i, int nOE);
	const int getBytes(int i);
	int * reverseArray(int * n, int noe);
	//int getCheckSum(int * i, int noe);
	//int binaryToDecimal(int * n, int noe);
	//int decimalToBinary(int n);

	int * asciArray(int i, int noOfBytes);
	

		




	int getAsciiSum(const char * n);
	
	//~StringHash();
	/*void insert(const char * n, double cgpa);
	void deleteRecord(const char * n);
	void getRecord(const char * n);*/
	
};


int StringHash::getHash(const string & key)
{
	int asciiSum = 0;
	int i = 0;
	while (key[i]!='\0')
	{
		//cout << (int)key[i] << "\n";
		asciiSum = asciiSum + (int)key[i];
		i++;
	}
	//cout << asciiSum << "\n";
	if (asciiSum < 256)
	{
		return asciiSum;
	}
	else
	{
		
		while (asciiSum > 255)
		{
			const int noOfBytes = getBytes(asciiSum);
			//calccout << noOfBytes << "\n";
			int * binaryArray = new int[noOfBytes];
			int j = 0;
			while (asciiSum >= 2)
			{
				binaryArray[j] = asciiSum % 2;
				asciiSum = asciiSum / 2;
				j++;
			}
			binaryArray[j] = asciiSum;
	
			int *reversedArrray = reverseArray(binaryArray, noOfBytes);		
			/*cout << "hey";
			for (int k = 0; k < noOfBytes; k++)
			{
				cout << reversedArrray[k] << " ";
			}*/
			//cout << "\n\n";
				int rightExtSum = 0;
				int index = noOfBytes - 1;
				for (int i = 0; i < 8; i++)
				{
					rightExtSum = rightExtSum + (reversedArrray[index] * pow(2, i));
				}
				//cout << "\nhhh=" << rightExtSum << "\n";
				int leftOverBytes = noOfBytes - 8;
				int leftExtrSum = 0;
				for (int i = 0; i < leftOverBytes; i++)
				{
					leftExtrSum = leftExtrSum + (reversedArrray[i] * pow(2, i));
				}
				//cout << "jj=" << leftExtrSum << "\n";
				asciiSum = leftExtrSum + rightExtSum;
				
		}
		return asciiSum;
	}
}
	




StringHash::StringHash()
{
	noOFElements = 0;
}

bool StringHash::insert(string & key, string & value)
{
	
	int hashV = getHash(key);
	if (hashTAble[hashV].isEmpty())
	{
		hashTAble[hashV].addElement(Pair(key, value));
		noOFElements++;
		return true;
	}
	return false;
}

bool StringHash::remove(const string & key)
{
	int hashV = getHash(key);
	if (hashTAble[hashV].isEmpty() == false)
	{
		hashTAble[hashV].~LinkedList();
	}
}

bool StringHash::find(const string & value)
{
	int hashV = getHash(value);
	if (hashTAble[hashV].isEmpty())
		return false;
	return true;
}

//bool StringHash::remove(const string & key)
//{
//	for (int i = 0; i < noOFElements; i++)
//	{
//		if(key==hashTAble[i].)
//	}
//
//
//
//}


bool StringHash::empty()
{
	return noOFElements;
}

bool StringHash::clear()
{
	if (noOFElements == 0)
		return false;
	else
	{
		this->~StringHash();
	}
	
}

int StringHash::size()
{
	int totalStrings = 0;
	for (int i = 0; i < 256; i++)
	{
		totalStrings = totalStrings + hashTAble[i].length();
	}
	return totalStrings;
}

string & StringHash::operator[](const string & key)
{
	int hashV = getHash(key);
	if(hashTAble[hashV].isEmpty()==false)
		

}

StringHash::~StringHash()
{
	for (int i = 0; i < 256; i++)
	{
		if (hashTAble[i].isEmpty() == false)
			hashTAble[i].~LinkedList();
	}
}

void StringHash::encodeURL(string & url,int key)
{
	srand(time(0));
	//int value = rand() % 256;
	string m;
	for (int i = 0; i < 4; i++)
	{
		m[i] = (char)(rand() % 256);
	}
	
	hashTAble[key] = m;
}

 Pair StringHash::decodeURl(int key)
{
	 if (hashTAble[key].isEmpty() == false)
		 return hashTAble[key].getElement(0);
}

int * StringHash::storeArray(int i, int nOE)
{
	int * n = new int[nOE];
	return NULL;

}

const int StringHash::getBytes(int i)
{
	int count = 0;
	while (i>=2)
	{
		i = i / 2;
		count++;
	}
	count++;
	return count;
}

int * StringHash::reverseArray(int * n, int noe)
{
	int * k = new int[noe];
	for (int i = 0,j=noe-1; i < noe;i++,j--)
	{
		k[i] = n[j];
	}
	return k;
}

//int StringHash::getCheckSum(int * i, int noe)
//{
//	int sum = binaryToDecimal(i, noe);
//	while (sum>256)
//	{
//
//
//
//	}
//	
//
//
//}

int StringHash::binaryToDecimal(int * n, int noe)
{
	int sum = 0;
	for (int i = noe - 1, j = 0; j < noe; j++,i--)
	{
		sum = sum + (n[i] * pow(2, j));
	}
	return sum;
}

int * StringHash::asciArray(int i, int noOfBytes)
{
	int * n = new int[noOfBytes];
	int j = 0;
	while (i>=2)
	{
		n[j] = i % 2;
		j++;
		i = i / 2;
	}
	n[j] = i;
	int * reverseedArray = reverseArray(n, noOfBytes);
	return reverseedArray;
}

//void StringHash::insert(const char * n, double cgpa)
//{
//	int sum = getAsciiSum(n);
//	hashTAble[(sum % 16)].addElement(cgpa);
//}
//
//void StringHash::deleteRecord(const char * n)
//{
//	int sum = getAsciiSum(n);
//	map[sum % 16].~LinkedList();
//
//}
//
//void StringHash::getRecord(const char * n)
//{
//	 map[getAsciiSum(n) % 16].display();
//}

int StringHash::getAsciiSum(const char * n)
{
	int sum = 0;
	int i = 0;
	while (n[i] != '\0')
	{
		sum = sum + (int)(n[i]);
		i++;
	}
	return sum;
}


