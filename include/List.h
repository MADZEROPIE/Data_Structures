#pragma once
#include <iterator>
template <typename T>
class List
{
private:

	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T& data, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
public:
	class iterator : public std::iterator<std::forward_iterator_tag, T> {
	private:
		Node* curr;
	public:
		iterator();
		iterator(const iterator& b);
		iterator (Node* b) {
			curr = b;
		}
		iterator& operator=(const iterator& b) {
			curr = b.curr;
			return *this;
		}
		iterator& operator=(Node* b) {
			curr = b;
			return *this;
		}
		T& operator*() const;
		Node* operator->() const {
			return curr;
		}
		bool operator ==(const iterator& b) {
			return curr == b.curr;
		}
		bool operator !=(const iterator& b) {
			return curr != b.curr;
		}
		iterator operator++() {
			curr = curr->pNext;
			return *this;
		}
		iterator operator++(int a) {
			List<T>::iterator tmp(*this);
			curr = curr->pNext;
			return tmp;
		}


	};
public:
	List();
	List(int size);
	~List();
	int GetSize() {
		return Size;
	};
	void push_back(T& data);
	void push_front(T& data);
	void pop_front();
	void clear();
	void pop_back();
	void removeAt(int index);
	void insert(T& data, int index);
	T& operator [](const int n);

	T& reversed_ind (const int k) {
		if (k < 0 || k >= Size) throw k;
		Node* nod = head;
		Node* curr = head;
		for(int i=0;i<=k;++i) curr = curr->pNext;
		while (curr != nullptr) {
			curr = curr->pNext;
			nod = nod->pNext;
		}
		return nod->data;
		//return operator[](Size - k - 1); //простой способ
	}

	T& find_middle() {
		if (head != nullptr) {
			Node* mid = head;
			Node* curr = head;
			unsigned int count = 0, count2 = 0;
			while (curr != nullptr) {
				++count;
				curr = curr->pNext;
				if ((count >> 1) > count2) {
					++count2;
					mid = mid->pNext;
				}
			}
			return mid->data;
		}
		//return operator[](Size/2); //простой способ
	}
	iterator begin() {
		return start;
	}
	iterator end() {
		return finish;
	}


private:
	int Size;
	Node* head;
	iterator start;
	iterator finish=nullptr;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
inline List<T>::List(int size)
{
	if (size < 0) throw size;
	head = nullptr;
	for (int i = 0; i < size; ++i) {
		head = new Node(i, head);
	}
	Size = size;
}

template <typename T>
List<T>::~List()
{
	clear();

}


template<typename T>
void List<T>::push_back(T& data)
{
	if (head == nullptr) {
		head = new Node(data);
		start = head;
	}
	else {
		Node* current = this->head;
		while (current->pNext != nullptr)
			current = current->pNext;
		current->pNext = new Node(data);
	}
	++Size;
}

template<typename T>
void List<T>::push_front(T& data)
{
	head = new Node(data, head);
	start = head;
	++Size;
}

template<typename T>
void List<T>::pop_front()
{
	Node* current = this->head;
	head = head->pNext;
	++start;
	delete current;
	--Size;

}

template<typename T>
void List<T>::clear()
{
	while (head != nullptr)
		pop_front();
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (!index)
		pop_front();
	else {
		Node* previous = this->head;
		for (int i = 1; i < index; i++)
			previous = previous->pNext;
		Node* current = previous->pNext;
		previous->pNext = current->pNext;
		delete current;
		--Size;
	}

}

template<typename T>
void List<T>::insert(T& data, int index)
{
	if (!index)
		push_front(data);
	else {
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		previous->pNext = new Node(data, previous->pNext);
		++Size;
	}
}

template<typename T>
T& List<T>::operator[](const int n)
{
	if (n < 0 || n >= Size) throw n;
	Node* current = this->head;
	for (int i = 0; i < n; i++)
		current = current->pNext;
	return current->data;
}

template<typename T>
inline List<T>::iterator::iterator()
{
	curr = nullptr;
}

template<typename T>
inline List<T>::iterator::iterator(const iterator& b)
{
	curr = b.curr;
}

template<typename T>
inline T& List<T>::iterator::operator*() const
{
	return curr->data;
}


