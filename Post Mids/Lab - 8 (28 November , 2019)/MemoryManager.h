#ifndef MEMORYMANAGER
#define MEMORYMANAGER
#include<iostream>
using namespace std;
struct MemoryBlock {
		int address;
		int length;
		MemoryBlock * next;
		MemoryBlock * prev;
		MemoryBlock(int add , int len) {
			this->address = add;
			this->length = len;
			this->next = nullptr;
			this->prev = nullptr;
		}
};
class MemoryManager {
private:
	int totalMemory;
	MemoryBlock * head;
	MemoryBlock * tail;
public:
	MemoryManager() {
		this->totalMemory = 0;
		this->head = this->tail = nullptr;
	}
	MemoryManager(int memory) {
		this->totalMemory = memory;
		this->head = this->tail = nullptr;
	}
	bool allocateMemory(int size) {
		if (size <= this->totalMemory) {
			if (isEmpty()) {
				MemoryBlock * newBlock = new MemoryBlock(1, size);
				this->head = this->tail = newBlock;
				return true;
			}
			else {
				MemoryBlock * temp = this->head;
				int memAvailable = 0 , endAddress;
				if (temp->address != 1) {
					memAvailable = temp->address - 1;
					if (memAvailable >= size) {
						MemoryBlock * newBlock = new MemoryBlock(1, size);
						newBlock->next = temp;
						temp->prev = newBlock;
						this->head = newBlock;
						return true;
					}
				}
				while (temp != this->tail) {
					endAddress = temp->address + temp->length - 1;
					memAvailable = temp->next->address - endAddress - 1;
					if (memAvailable >= size) {
							MemoryBlock * newBlock = new MemoryBlock(endAddress + 1, size);
							newBlock->next = temp->next;
							temp->next->prev = newBlock;
							temp->next = newBlock;
							newBlock->prev = temp;
							return true;
					}
					else
						temp = temp->next;
				}
				if (temp == this->tail) {
					endAddress = temp->address + temp->length - 1;
					memAvailable = this->totalMemory - endAddress;
					if (memAvailable >= size) {
						MemoryBlock * newBlock = new MemoryBlock(endAddress + 1, size);
						newBlock->next = temp->next;
						temp->next = newBlock;
						newBlock->prev = temp;
						this->tail = newBlock;
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
	bool deAllocateMemory(int add) {
		if (add > 0 && add <= this->totalMemory) {
			if (isEmpty()) {
				return false;
			}
			else {
				MemoryBlock * temp = this->head;
				int memAvailable = 0, endAddress;
				while (temp->address != add && temp != nullptr) {
					temp = temp->next;
				}
				if (temp->address == add) {
					if (temp == this->head) {
						if (this->head == this->tail) {
							delete temp;
							this->head = this->tail = nullptr;
						}
						else
						{
							temp->next->prev = nullptr;
							this->head = temp->next;
							delete temp;
						}
					}
					else if (temp == this->tail) {
						temp->prev->next = nullptr;
						this->tail = temp->prev;
						delete temp;
					}
					else {
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						delete temp;
					}
					return true;
				}
				else
					return false;
			}
		}
		return false;
	}
	bool isEmpty()const {
		return this->head == nullptr;
	}
	void displayMemory()const {
		if (!isEmpty()) {
			MemoryBlock * temp = this->head;
			while (temp != nullptr) {
				cout << "Add:" << temp->address << "   Length:" << temp->length << "\n";
				temp = temp->next;
			}
			cout << "\n";
		}
	}
	void enQueue(int val)
	{
		insertTail(val);
	}
	/*int deQueue()
	{
	return deleteHead();
	}*/
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
			head = tail = newNode;
		else
		{
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
			tail->next = head;
			head->previous = tail;
		}
	}
	void insertTail(int val)
	{
		Node*newNode = new Node(val);
		if (!isEmpty())
		{

			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
			tail->next = head;
			head->previous = tail;
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
			int x = head->data;
			if (head == tail)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Node*temp = head->next;
				head = temp->next;
				tail->next = head;
				head->previous = tail;
				delete temp;

			}
			if (head == tail && head != NULL)
			{
				head->previous = NULL;
				head->next = NULL;
			}
			if (head == NULL)
				tail = NULL;
			return x;
		}
		else
		{
			cout << "List empty\n";
			return NULL;
		}
	}
	int deleteTail()
	{
		if (isEmpty())
		{
			cout << "List empty\n";
			return NULL;
		}
		else
		{
			int x = tail->data;
			if (head == tail)
			{
				delete tail;
				head = tail = NULL;
				return x;
			}
			else
			{
				Node*temp = tail->previous;
				temp->next = head;
				head->previous = temp;
				delete tail;
				tail = temp;
			}
			if (head == tail && head != NULL)
			{
				head->next = NULL;
				head->previous = NULL;
			}
			if (head->previous == NULL)
			{
				head->next = NULL;

			}
			return x;

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
	void insertBefore(int key, int val)
	{
		Node*target = searchKey(key);
		if (target != NULL)
		{
			Node*temp = head;
			Node*previous = nullptr;
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

				if (target->next == head)
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
			if (target == head)
			{
				cout << "Key found at first node , no node before first node!\n";
				cout << "Operation can't be performed!\n";
				return;
			}
			Node*temp = head;
			if (head != tail)
			{
				if (temp->next->data == key)
				{
					Node*temp2 = head;
					head = target;
					delete temp2;

				}
				else
				{
					while (temp != tail)
					{
						if (temp->next->next->data == key)
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
			return 0;
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
};

#endif