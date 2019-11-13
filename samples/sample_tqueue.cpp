#include <iostream>
#include "tstack.h"
#include "tqueue.h"
#include "List.h"



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	List<int> lis;
	for (int i = 9; i >0; --i) lis.push_front(i);
	cout<<lis.find_middle()<<endl; //5
	cout << lis.reversed_ind(3) << endl; //6
	cout << lis.reversed_ind(8); //1
	return 0;
}

