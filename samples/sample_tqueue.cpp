#include <iostream>
#include "heap.h"
#include <algorithm>

const int N = rand()%150;


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	std::vector<Prior_Elem<int> > a, b;
	for (int i = 0; i < N; ++i) {
		int r = std::rand();
		a.push_back(Prior_Elem<int>(r, r));
		b.push_back(Prior_Elem<int>(r, r));
	}
	TPriority_queue<int>::heapSort(a);
	std::sort(b.begin(), b.end(), [](const Prior_Elem<int>& c, const Prior_Elem<int>& d) {return c.prior < d.prior; });
	for (int i = 0; i < N; ++i) {
		std::cout << a[i].elem << "\t\t\t"<< b[i].elem<<'\n';
	}
	return 0;
}

