#pragma once

template <typename T>
class List
{
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
		return operator[](Size - k - 1);
	}
	T& find_middle() {
		return operator[](Size/2);
	}

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

	int Size;
	Node* head;
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
	if (head == nullptr)
		head = new Node(data);
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
	++Size;
}

template<typename T>
void List<T>::pop_front()
{
	Node* current = this->head;
	head = head->pNext;
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