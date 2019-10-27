#pragma once

#include "tstack.h"

template<typename T>
class TQueue_by_Stack {
protected:
	TStack<T> st1, st2;
public:
	TQueue(int Size = 15) :st1(Size), st2(Size) {}
	~TQueue() {}
	void push(const T& Val) {
		st1.push(Val);
	}
	void pop(void) {
		shift();
		return st2.pop();
	}
	T top(void) {
		shift();
		return st2.top();
	}
	void shift() { //����������� ��������� �� 1 ����� �� ������
		if (st2.IsEmpty()) {
			while (!st1.IsEmpty())
			st2.push(st1.top());
			st1.pop();
		}
	}
};

template<typename T>
class TQueue {

};