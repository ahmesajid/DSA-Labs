#include<iostream>
using namespace std;
template <typename T>
class Stack {
private:
	T*data;
	int capacity;
	int top;
	void reSize(int);
public:
	Stack();
	Stack(const Stack<T> &);
	Stack & operator = (const Stack<T> & f);
	~Stack();


	bool isFull() const;
	bool isEmpty() const;
	T stackTop();
	int getCapacity() const;
	int getNumberOfElements() const;
	void push(T f);
	T pop();
};
template <class F>
class LinkedList
{
	struct Node
	{
		F value;
		Node * next;
		Node(F a, Node * ptr)
		{
			value = a;
			next = ptr;
		}
	};
	Node * head;
public:
	LinkedList();
	LinkedList(const LinkedList & ref);
	~LinkedList();
	void addElement(F a);
	void display();
	int length();
	void remove(int index);
	void reverse();
	void sort();
	void insertAtHead(F a);
	void removeFromHead();
	F getElement(int index);
	bool isEmpty();
	
	
	F findKthLastElement(int k);
	bool isPalindrome();
	bool insertBefore(F element,F insert);
	F findMiddleOne();
	void partioning(F x);
	void detectLoop();
	F getMinValue();
};
template <class F>
LinkedList<F>::LinkedList(const LinkedList & ref)
{
	if (ref.head == nullptr)
		head = nullptr;
	else
	{
		head = new Node(ref.head->value, nullptr);
		Node * ptr = head;
		Node * temp = ref.head->next;
		while (temp != nullptr)
		{
			ptr->next = new Node(temp->value, nullptr);
			temp = temp->next;
			ptr = ptr->next;
		}
	}
}
template <class F>
LinkedList<F>::LinkedList()
{
	head = nullptr;
}
template <class F>
void LinkedList<F>::addElement(F a)
{
	if (head == nullptr)
		head = new Node(a, nullptr);
	else
	{
		Node * ptr = head;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = new Node(a, nullptr);
	}
}
template <class F>
void LinkedList<F>::display()
{
	if (head == nullptr)
		throw"List Empty";
	else
	{
		Node * ptr = head;
		while (ptr != nullptr)
		{
			cout << ptr->value << " ";
			ptr = ptr->next;
		}
	}
}
template <class F>
int LinkedList<F>::length()
{
	if (head == nullptr)
		return 0;
	else
	{
		int length = 1;
		Node * ptr = head;
		while (ptr->next != nullptr)
		{
			length++;
			ptr = ptr->next;
		}
		return length;
	}
}
template <class F>
void LinkedList<F>::remove(int index)
{
	if (index > this->length() || index <= 0 || head == nullptr)
		throw"Index Doesnt Exist";
	else
	{
		if (index == 1 && head->next != nullptr)
		{
			Node *  temp = head->next;
			delete head;
			head = temp;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			int counter = 1;
			Node * ptr = head->next;
			Node * prev = head;
			while (ptr->next != nullptr && index - 1 > counter)
			{
				ptr = ptr->next;
				prev = prev->next;
				counter++;
			}
			if (ptr->next == nullptr) //Removed element is last one.
			{
				delete prev->next;
				prev->next = nullptr;
			}
			else
			{
				Node * temp = ptr->next;//Some element from centre.
				delete ptr;
				prev->next = temp;
			}
		}
	}
}
template <class F>
 void LinkedList<F>::reverse()
{
	 
	 if (head->next == nullptr)
		 return;
	 else
	 {
		 Node * temp = head->next;
		 Node * ptr = head;
		 head->next = nullptr;
		 Node * curr = temp->next;
		 while (curr!=nullptr)
		 {
			 temp->next = ptr;
			 ptr = temp;
			 temp = curr;
			 curr = curr->next;
		 }
		 temp->next = ptr;
		 head = temp;
	 }
	 	 


	 
	 
	 
	 
	 
	 
	 /*if (head->next == nullptr)
		 return;
	 else
	 {

		 Stack<Node *> s;
		 Node * ptr = head;
		 while (ptr != nullptr)
		 {
			 s.push(ptr);
			 ptr = ptr->next;
		 }
		 head = s.pop();
		 ptr = head;
		 Node * n = s.pop();
		 head->next = n;
		 while (!s.isEmpty())
		 {
			 ptr = s.pop();
			 n->next = ptr;
			 n = ptr;
		 }
		 n->next = nullptr;
	 }*/
}
 template <class F>
F LinkedList<F>::findKthLastElement(int k)
{
	int length = this->length();
	if (k <= 0 || k>length)
		throw"Invalid LAst ELement";
	else
	{
		int noOfSteps = length-k;
		int counter = 0;
		Node * ptr = head;
		while (counter < noOfSteps)
		{
			ptr = ptr->next;
			counter++;
		}
		return ptr->value;
	}
}
template <class F>
bool LinkedList<F>::isPalindrome()
{
	Stack<F> a;
	Node * ptr = head;
	while (ptr!=nullptr)
	{
		a.push(ptr->value);
		ptr = ptr->next;
	}
	ptr = head;
	while (ptr!=nullptr)
	{
		if ((a.pop()) != (ptr->value))
			return false;
		ptr = ptr->next;
	}
	return true;
}
template <class F>
bool LinkedList<F>::insertBefore(F element, F insert)
{
	Node * prev = head;
	Node * curr = head->next;
	int index = 0;
	if (element == prev->value)
	{
		head = new Node(insert, prev);
		return true;
	}
	else
	{
		while (curr != nullptr  && curr->value != element  )
		{
			curr = curr->next;
			prev = prev->next;
			index++;
		}
		if (curr == nullptr)
			return false;
		else
		{
			prev->next = new Node(insert, curr);
			return true;
		}
	}
}
template <class F>
F LinkedList<F>::findMiddleOne()
{
	Stack<F> a;
	int count = 1;
	Node * ptr = head;
	while (ptr!=nullptr)
	{
		a.push(ptr->value);
		ptr = ptr->next;
		count++;
	}
	count = count - 1;
	int noOfPops = count / 2;
	while (noOfPops>0)
	{
		a.pop();
		noOfPops--;
	}
	return (a.pop());
}
template <class F>
void LinkedList<F>::partioning(F x)
{
	Stack<Node *> a;
	Stack<F> b;
	Node * ptr = head;
	Node * val = head;
	while (ptr!=nullptr)
	{
		a.push(ptr);
		b.push(ptr->value);
		ptr = ptr->next;
	}
	ptr = head;
	int countOfMissed = 0;
	while (!b.isEmpty())
	{
		F m = b.pop();
		if (m > x)
		{
			Node * temp= a.pop();
			temp->value = m;
		}
		else if (m == x)
		{
			countOfMissed++;
		}
		else
		{
			ptr->value = m;
			ptr = ptr->next;
		}
	}
	while (countOfMissed!=0)
	{
		ptr->value = x;
		ptr = ptr->next;
		countOfMissed--;
	}
}
template <class F>
void LinkedList<F>::detectLoop()
{
	
}


template <class F>
void LinkedList<F>::sort()
{
	Node * temp = head;
	Node * ptr = head;
	while (temp != nullptr)
	{
		ptr = temp;
		Node * address = ptr;
		F data = ptr->value;
		ptr = ptr->next;
		while ((ptr->next != nullptr) && (data < ptr->value))
		{
			ptr = ptr->next;
		}
		if (data > ptr->value)
		{
			address->value = ptr->value;
			ptr->value = data;
		}
		temp = temp->next;
	}
}

template<class F>
 void LinkedList<F>::insertAtHead(F a)
{
	 if (head == nullptr)
		 head = new Node(a, nullptr);
	 else
	 {
		 Node * temp = head;
		 head = new Node(a, temp);
	 }
}

 template<class F>
  void LinkedList<F>::removeFromHead()
 {
	  if (head == nullptr)
		  throw"LisT Empty";
	  else
	  {
		  Node * temp = head->next;
		  delete head;
		  head = temp;
	  }
 }

  template<class F>
   F LinkedList<F>::getElement(int index)
  {
	   if (index <= 0)
		   throw"Invalid Index";
	   else if (!head)
		   throw"List Empty";
	   else
	   {
		   Node * ptr = head;
		   while (ptr != nullptr && index-1 > 0)
		   {
			   ptr = ptr->next;
			   index--;
		   }
		   if (ptr == nullptr)
			   throw"Invalid Index";
		   else
		   {
			   return ptr->value;
		   }
	   }
  }

   template<class F>
   bool LinkedList<F>::isEmpty()
   {
	   if (head == nullptr)
		   return true;
	   return false;
   }




template<class F>
F LinkedList<F>::getMinValue()
{
	static Node* ptr = head;
	static F min = head->value;
	if (ptr->next == nullptr)
		return min;
	ptr = ptr->next;
	if (ptr->value < min)
		min = ptr->value;
	getMinValue();
}

template <class F>
LinkedList<F>::~LinkedList()
{
	while (head != nullptr)
	{
		Node * prev = head;
		Node * ptr = head->next;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
				prev = prev->next;
			}
			delete ptr;
			prev->next = nullptr;
		}
	}
}
template<typename T>
void Stack<T>::reSize(int t)
{
	T * temp = new T[(t*2)];
	for (int i = 0; i <= top; i++)
	{
		temp[i] = data[i];
	}
	capacity = capacity * 2;
	delete[] data;
	data = temp;
}

template<typename T>
Stack<T>::Stack()
{
	data = new T[5];
	capacity = 5;
	top = -1;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
	if (ref.data)
	{
		top = ref.top;
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i <= top; i++)
		{
			data[i] = ref.data[i];
		}
	}
}

template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T>& f)
{
	delete[] data;
	data = new T[f.capacity];
	for (int i = 0; i <= f.top; i++)
	{
		data[i] = f.data[i];
	}
	top = f.top;
	capacity = f.capacity;
	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	if (data)
		delete[] data;
	data = (T *)0;
	top = -1;
	capacity = 0;
}

template<typename T>
bool Stack<T>::isFull()const
{
	if (top == (capacity - 1))
		return true;
	else
		return false;

}

template<typename T>
bool Stack<T>::isEmpty()const
{
	if (top == -1)
	{
		return true;
	}
	return false;
}

template<typename T>
T Stack<T>::stackTop()
{
	if (data && (!isEmpty()))
		return data[top];
}

template<typename T>
int Stack<T>::getCapacity()const
{
	return capacity;
}

template<typename T>
int Stack<T>::getNumberOfElements()const
{
	return (top + 1);
}

template<typename T>
void Stack<T>::push(T f)
{
	if (isFull())
		reSize(capacity);
	top = top + 1;
	data[top] = f;
}

template<typename T>
T Stack<T>::pop()
{
	//cout << "Here";
	if (!isEmpty())
	{
		top = top - 1;
		return (data[top + 1]);
	}
	throw"Stack EMpty\n";
}