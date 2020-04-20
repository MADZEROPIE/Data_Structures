#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Sorry, but there'll be a lot of comments on "English"...
//More than "a lot"

template<typename T>
class Prior_Elem {
public:
	int prior = 0; // Well... Probably it would be better to be private (or protected)... But I'm pretty lazy
	T elem;

public:
	Prior_Elem(T el, int pr=0) { elem = el; prior = pr; }
};

template<typename T>
class TPriority_queue {
private:
	vector<Prior_Elem<T> > vec; //That's LAME.
	const int d; //Quanity of childs. That's not the best way to deal with it, but ...
private:
	int minChild(int i) { // Well... Someday I'll make all names in one style. But not today...

		int first_child = i * d + 1;
		if (first_child >= vec.size()) return 0;
		int last_child = (((i + 1) * d) < (vec.size() - 1)) ? ((i + 1) * d) : (vec.size() - 1); // Brackets... I'm sick of them
		Prior_Elem<T> tmp=vec[first_child];
		int t = first_child;

		for (int i = first_child+1; i <= last_child; ++i) {
			if (vec[i].prior < tmp.prior) {
				tmp = vec[i]; t = i;
			}
		}
		return t;
	}

	void diving(int i) {
		int j = minChild(i);
		while (j != 0 && vec[i].prior > vec[j].prior) {
			std::swap(vec[i], vec[j]);
			i = j;
			j = minChild(j);
		}
	}

	void emersion(int i) {
		int j = (i-1) / d;
		while (j != 0 && vec[i].prior < vec[j].prior) {
			std::swap(vec[i], vec[j]);
			i = j;
			j /= d;
		}
	}

	void makeHeap()	{
		for (int i = (int)vec.size() - 1; i >= 0; --i) diving(i); //Why not? Error when vec.size()>=2^32(?), but hey! where is no way for such big data (NEED FIX)
	}



public:
	TPriority_queue(int _d = 2) : d(_d) {} 
	TPriority_queue(const vector<Prior_Elem<T> >& b, int _d = 2) : vec(b) , d(_d){
		//NOW It's TIME TO MAKE IT SORTED
		makeHeap();
	}
	
	void insert(const Prior_Elem<T>& b) {
		vec.push_back(b);
		emersion(vec.size() - 1);
	}
	
	void delMin() {
		vec[0] = vec[vec.size() - 1]; // std::move will be good too.
		vec.pop_back();
		diving(0);
	}
	static void heapSort(vector<Prior_Elem<T> >& b) {
		TPriority_queue<T> qu(b);
		for (int i = 0; i < b.size(); ++i) {
			b[i] = qu.vec[0];
			qu.delMin();
		}

	}	
	
};