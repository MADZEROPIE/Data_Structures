#include <iostream>
#include "tstack.h"
#include "tqueue.h"
#include "List.h"
#include <algorithm>



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	List<int> lis;
	for (int i = 0; i <18; ++i) lis.push_front(i);
	//cout<<lis.find_middle()<<endl; //5
	//cout << lis.reversed_ind(3) << endl; //6
	//cout << lis.reversed_ind(8); //1
	for (auto it = lis.begin(); it != lis.end(); ++it) cout << it->data<<' ';
	//std::sort(lis.begin(), lis.end());
	std::cout << std::endl;
	for (auto it = lis.begin(); it != lis.end(); ++it) cout << *it << ' ';
	return 0;
}

