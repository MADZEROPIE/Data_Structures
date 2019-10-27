#pragma once
#include <iostream>

using namespace std;

template <typename T>
class TStack {
protected: // поля
	T* pMem; // указатель на массив элементов
	int MemSize; // размер памяти 
	int DataCount; // количество элементов

public:
	TStack (int Size = 15);//конструктор
	TStack(const TStack& st);
	~TStack(); //деструктор
	int IsEmpty ( void ) const ; // контроль пустоты
	int IsFull ( void ) const ; // контроль переполнения
	void push ( const T& Val );// добавить значение
	void clear() { DataCount = 0; }
	int size() { return DataCount; }
	TStack<T>& operator=(const TStack& st);
	T top() {
		if (IsEmpty()) throw "No elements here.";
		return pMem[DataCount - 1]; }
	void pop ( void ) ; // извлечь значение
};



template<typename T>
inline TStack<T>::TStack(int Size)
{
	if (Size < 0) throw exception();
	pMem = new T[Size];
	DataCount = 0;
	MemSize = Size;
}

template<typename T>
inline TStack<T>::TStack(const TStack<T>& st)
{
	MemSize = st.MemSize; DataCount = st.DataCount;
	pMem = new T[st.MemSize];
	for (int i = 0; i < DataCount; ++i) pMem[i] = st.pMem[i];
}

template<typename T>
inline TStack<T>::~TStack()
{
	delete[] pMem;
}

template<typename T>
inline int TStack<T>::IsEmpty(void) const
{
	return (DataCount==0);
}

template<typename T>
inline int TStack<T>::IsFull(void) const
{
	return (DataCount == MemSize);
}

template<typename T>
inline void TStack<T>::push(const T& Val)
{
	if (IsFull()) {
		MemSize = MemSize + MemSize / 3 + 1;
		T* tmp = new T[MemSize];
		for (int i = 0; i < DataCount; ++i) tmp[i]= pMem[i];
		delete[] pMem;
		pMem = tmp;
	}
	pMem[DataCount++] = Val;
}

template<typename T>
inline TStack<T>& TStack<T>::operator=(const TStack& st)
{	
	if (this != &st) {
		DataCount = st.DataCount;
		if (MemSize != st.MemSize) {
			delete[] pMem;
			pMem = new T[st.MemSize];
			MemSize = st.MemSize;
		}
		for (int i = 0; i < MemSize; ++i) pMem[i] = st.pMem[i];
	}
	return *this;
}

template<typename T>
inline void TStack<T>::pop(void)
{
	if (IsEmpty()) throw "No elements here";
	--DataCount;
	if (DataCount < (3 * MemSize / 4)) { 
		MemSize = 3 * MemSize / 4 + 1;
		T* tmp = new T[MemSize];
		for (int i = 0; i < DataCount;++i) tmp[i] = pMem[i];
		delete[] pMem;
		pMem = tmp;
	}

	
}