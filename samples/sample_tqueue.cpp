#include <iostream>
#include "tstack.h"
#include "tqueue.h"
#include "List.h"
#include "heap.h"
#include <algorithm>

const int N = 15;


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	std::vector<Prior_Elem<int> > a, b;
	for (int i = 0; i < N; ++i) {
		int r = i;// std::rand();
		a.push_back(Prior_Elem<int>(r, r));
		//b.push_back(Prior_Elem<int>(r, r));
	}
	TPriority_queue<int>::heapSort(a);
	for (int i = 0; i < N; ++i) {
		std::cout << a[i].elem << '\n';
	}
	return 0;
}

