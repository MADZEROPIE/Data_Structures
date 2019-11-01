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
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	void pop_back();
	void removeAt(int index);
	void insert(T data, int index);
	T& operator [](const int n);

private:

	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data, Node* pNext = NULL) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = NULL;
}

template<typename T>
inline List<T>::List(int size)
{
	if (size < 0) throw size;
	head = NULL;
}

template <typename T>
List<T>::~List()
{
	clear();

}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == NULL)
		head = new Node<T>(data);
	else {
		Node<T>* current = this->head;
		while (current->pNext != NULL)
			current = current->pNext;
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* current = this->head;
	head = head->pNext;
	delete current;
	Size--;

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
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		Node<T>* current = previous->pNext;
		previous->pNext = current->pNext;
		delete current;
		Size--;
	}

}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (!index)
		push_front(data);
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
T& List<T>::operator[](const int n)
{
	Node<T>* current = this->head;
	for (int i = 0; i < n; i++)
		current = current->pNext;
	return current->data;
}