#include<iostream>
#include<cmath>
using namespace std;
void print(int n)
{
	if (n <= 0)
		return;
	print(n-2);
	cout << n +1 << ' ';
	print(n-1);
	cout << n+3 << ' ';
}
int calculateLength(int number)
{
	if (number == 0)
		return 1;
	int i = 0;
	while (number != 0)
	{
		i++;
		number = number / 10;
	}
	return i;
}
bool isPalindrome(int number)
{
	int len = calculateLength(number);
	int p = pow(10, len - 1);

	if (len == 1)
		return true;
	if ((number % 10) != (number / p))
		return false;
	
	return isPalindrome(((number%p)-(number%10))/10);
}
struct Node
{
	int data;
	Node*next;
	Node(int data=0)
	{
		this->data = data;
		next = NULL;
	}
};
class LinkedList
{
public:
	Node * head;
	Node*tail;	
	int getFront()
	{
		return head->data;
	}
	int getRear()
	{
		return tail->data;
	}
	void enQueue(int val)
	{
		insertTail(val);
	}
	int deQueue()
	{
		return deleteHead();
	}
	void push(int val)
	{
		insertTail(val);
	}
	int pop()
	{
		return deleteTail();
	}
	int returnTop()
	{
		return tail->data;
	}
	LinkedList()
	{
		head = tail = NULL;
	}
	void insertHead(int val)
	{
		Node*newNode = new Node(val);
		if (isEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
			tail->next = head;
		}
		cout << "Head added sucessfully!\n";

	}
	void insertTail(int val)
	{
		Node*newNode = new Node(val);
		if (!isEmpty())
		{
			tail->next = newNode;
			tail = newNode;
			tail->next = head;
		}
		else
		{
			head = tail = newNode;
		}
	}
	int deleteHead()
	{
		if (!isEmpty())
		{
			if (head != tail)
			{
				Node*temp = head;
				head = temp->next;
				tail->next = head;
				int x = temp->data;
				delete temp;
				return x;

			}
			else if (head == tail)
			{
				int x = head->data;
				delete head;
				head = tail = NULL;
				return x;
			}
			if (head == NULL)
				tail = NULL;

		}
		else
		{
			cout << "List empty\n";
			return NULL;
		}
	}
	int deleteTail()
	{
		if (!isEmpty())
		{
			if (head != tail)
			{
				Node*temp = head;
				while (temp->next != tail)
				{
					temp = temp->next;
				}

				int x = tail->data;
				delete tail;
				tail = temp;
				tail->next = head;
				return x;
			}
			else if(head==tail)
			{
				int x = head->data;
				delete tail;
				head = tail = NULL;
				return x;
			}
		}
		else
		{
			cout << "\n";
			cout << "List empty";
			cout << "\n";
			return NULL;
		}
	}
	Node*searchKey(int key)
	{
		if (!isEmpty())
		{ 
			Node*temp = head;
			if (head != tail)
			{
				while (temp != tail) //TEMP WILL TRAVERSE UPTILL TAIL , BUT WILL NOT CHECK DATA OF TAIL (LAST NODE)
				{
					if (temp->data == key)
						return temp;
					temp = temp->next;
				}
				//CHECKING LAST NODE
				if (temp->data == key)
					return temp;
			}
			else //IF THERE IS ONLY ONE NODE IN LINKED LIST
			{
				if (temp->data == key)
					return temp;
			}
			return NULL;
		}
		else //IF LINKED LIST IS EMPTY
		{
			return NULL;
		}
	}
	void insertAfter(int key, int val)
	{
		Node*target = searchKey(key);
		if (target != NULL)
		{
			Node*ptr = target->next;
			Node*newNode = new Node(val);
			newNode->next = ptr;
			target->next = newNode;
			if (target == tail)
				tail = newNode;
		}

		else
			cout << "Key not found!\n";
	}
	void insertBefore(int key,int val)
	{
		Node*target = searchKey(key);
		if (target != NULL)
		{
			Node*temp = head;
			Node*previous=nullptr ;
			if (head != tail)
			{
				while (temp != tail)
				{
					if (head->data == key)
					{
						Node*newNode = new Node(val);
						newNode->next = head;
						head = newNode;
						return;
					}
					if (temp->next->data == key)
					{
						previous = temp;
						break;
					}
					temp = temp->next;
				}
				Node*newNode = new Node(val);
				previous->next = newNode;
				newNode->next = target;
			}
			else
			{
				Node*newNode = new Node(val);
				head = newNode;
				newNode->next = target;
				if (target == head)
					head = newNode;
			}
			
		}
		else
		{
			cout << "KEY NOT FOUND!\n";
		}

	}
	void deleteAfter(int key)
	{
		Node*target = searchKey(key);
		if (target != NULL)
		{
			if (target == tail)
			{
				cout << "Key found at last node , there is no node to delete after last node!\n";
				cout << "Operation can't performed!\n";
				return;
			} // 5 8
			if (head != tail)
			{
				Node*toDel = target->next;
				Node*nextNodeToJoin = toDel->next;
				target->next = nextNodeToJoin;
				delete toDel;

				if (target->next==head)
				{
					tail = target;
					target->next = NULL;
				}

			}
			else
			{
				cout << "Only node in linked list , operation can't performed!\n";
			}
		}
		else
		{
			cout << "KEY NOT FOUND!\n";
		}
	}
	void deleteBefore(int key)
	{
		Node*target = searchKey(key);
		if (target != NULL)
		{
			if (target==head)
			{
				cout << "Key found at first node , no node before first node!\n";
				cout << "Operation can't be performed!\n";
				return;
			}
			Node*temp = head;
			if(head!=tail)
			{
				if (temp->next->data==key)
				{
					Node*temp2 = head;
					head = target;
					delete temp2;

				}
				else
				{
					while (temp != tail)
					{
						if (temp->next->next->data== key)
						{
							Node*toDel = temp->next;
							temp->next = temp->next->next;
							delete toDel;
							return;
						}
						temp = temp->next;
					}
				}
			}
		}
		else
		{
			cout << "KEY NOT FOUND!\n";
		}
	}
	int getLength()
	{
		int counter = 0;
		if (isEmpty())
		{
			return 0;
		}
		else
		{
			if (head == tail)
			{
				return 1;
			}
			else
			{
				Node*temp = head;
				while (temp != tail)
				{
					temp = temp->next;
					counter++;
				}
				return counter + 1;
			}



		}
		Node*temp = head;
	}
	void printList()
	{
		if (!isEmpty())
		{

			Node*temp = head;
			while (temp != tail)
			{
				cout << temp->data << ' ';
				temp = temp->next;
			}
			cout << temp->data << ' ';

		}
		else
			cout << "List empty!\n";
	}
	bool isEmpty()
	{
		return (head == NULL && tail == NULL);
	}
};

int main()
{





	LinkedList L1;
	L1.insertTail(5);
	L1.insertTail(6);
	
	L1.deleteAfter(5);
	L1.printList();




	


	/*L1.push(1);
	L1.push(2);
	L1.push(3);
	L1.push(4);
	L1.push(5);

	cout << "TOP : " << L1.returnTop()<<'\n';

	cout << L1.pop()<<' ';
	cout << L1.pop() << ' ';
	cout << L1.pop() << ' ';
	cout << L1.pop() << ' ';
	cout << L1.pop() << ' ';

*/

/*
	L1.enQueue(6);
	L1.enQueue(7);
	L1.enQueue(8);
	L1.enQueue(9);

	cout << "Front : " << L1.getFront()<<'\n';
	cout << "Rear : " << L1.getRear()<<'\n';

	cout << L1.deQueue()<<' ';
	cout << L1.deQueue() << ' ';
	cout << L1.deQueue() << ' ';
	cout << L1.deQueue() << ' ';
*/
	



	/*L1.insertTail(2);
	L1.insertTail(5);


	L1.insertBefore(5, -1);

	L1.printList();*/
/*
	node*n1 = l1.searchkey(17);
	if (n1 != null)
		cout << "key found!\n";
	else
		cout << "key not found!\n";*/

	//DELETING
/*
	int x = L1.deleteHead();
	while (x != NULL)
	{
		cout << x << ' ';
		x = L1.deleteHead();
	}
*/
	cout << "\n";
	return 0;

}
