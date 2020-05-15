#include <iostream>
#include "tree.h"
#include <algorithm>

//class a {	int a;};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	//Tree<a, int> b; ERROR TEST
	AVL_tree tr;
	for (int i = 0; i < 12; ++i)
		tr.insert(i);
	
	std::cout << std::boolalpha << tr.checkTree()<<'\n';
	std::cout << tr <<"\n\n\n";
	tr.erase(0);
	std::cout << std::boolalpha << tr.checkTree() << '\n';
	std::cout << tr << "\n\n\n";
	//tr.insert(7);
	//std::cout << tr << "\n\n\n";
	tr.erase(1);
	std::cout << std::boolalpha << tr.checkTree() << '\n';
	std::cout << tr << "\n\n\n";
	tr.insert(1);
	std::cout << std::boolalpha << tr.checkTree() << '\n';
	std::cout << tr << "\n\n\n";
	return 0;
}

