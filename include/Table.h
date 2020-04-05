//#include <vector> Already used in polynom.h
#include "polynom.h"



class Table {
public:
	virtual void Insert(const Named_Polynom& pol) = 0;
	virtual void Delete(Key key) = 0;
	virtual Named_Polynom Search(Key key) = 0;
	virtual void clear() = 0;
};

class UnsTable : public Table {
private:
	std::vector<Named_Polynom> vec;
public:
	void Insert(const Named_Polynom& pol) {
		vec.push_back(pol);
	}
	void Delete(Key _key) {
		vec.erase(
			std::find_if(vec.begin(), vec.end(), [&_key](const Named_Polynom& pol) { // RU: Да, слишком сложно, но давно хотел попробовать...
				return pol.GetKey() == _key;
			})
		);
	}
	Named_Polynom Search(Key _key) {	
		auto it = std::find_if(vec.begin(), vec.end(), [&_key](const Named_Polynom& pol) {
			return pol.GetKey() == _key;
			});
		if (it == vec.end()) throw "Polynom doesn't exist";
		return *it;
	}
	void clear() { vec.clear(); }
};

class SorTable : public Table {
private:
	std::vector<Named_Polynom> vec;

	//int search_pos(const Key& _key) { //RU: std::binary_search возвращает bool
	//	int left = 0;
	//	int right = vec.size();
	//	while (left<right)
	//	{
	//		int mid = left + (left + right) / 2;
	//		if (vec[mid].GetKey() < _key) {
	//			right = mid;
	//		}
	//		else if (vec[mid].GetKey() == _key) {
	//			return mid;
	//		}
	//		else left = mid+1;
	//	}
	//	return -left - 1; //RU: Если left==0
	//}

public:
	void Insert(const Named_Polynom& pol) {
		//int pos = search_pos(pol.GetKey());
		//if (pos < 0) pos = -pos - 1;
		//vec.insert(vec.begin() + pos,pol);
		vec.insert(
			std::lower_bound(
				vec.begin(), vec.end(),
				pol,
				[](const Named_Polynom& p1, const Named_Polynom& p2) {return p1.GetKey()<p2.GetKey(); }
			),
			pol);
	}

	void Delete(Key _key) {
		//int pos = search_pos(_key);
		//if (pos < 0) throw "Polynom doesn't exist";
		//vec.erase(vec.begin() + pos);
		auto it = std::lower_bound(
			vec.begin(), vec.end(),
			_key,
			[] (const Named_Polynom& p, const Key& k) {return p.GetKey() < k; }
		);
		if((it+1)==vec.end()||(!(it->GetKey()==_key))) throw "Polynom doesn't exist";
		vec.erase(it);
	}

	Named_Polynom Search(Key _key) {
		//int pos = search_pos(_key);
		//if (pos<0) throw "Polynom doesn't exist";
		//return vec[pos];
		auto it = std::lower_bound(
			vec.begin(), vec.end(),
			_key,
			[](const Named_Polynom& p, const Key& k) {return p.GetKey()<k; }
		);
		if ((it + 1) == vec.end() || (!(it->GetKey() == _key))) throw "Polynom doesn't exist";
		return *it;
	}
	void clear() { vec.clear(); }
};