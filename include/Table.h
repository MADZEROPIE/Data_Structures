//#include <vector> Already used in polynom.h
#include "polynom.h"

//RU: Я знаю, что реализацию надо перенести в .cpp, но мне лень. Перенесу после хэш-таблиц

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
		auto it = std::find_if(vec.begin(), vec.end(), [&_key](const Named_Polynom& pol) { // RU: Да, слишком сложно, но давно хотел попробовать...
				return pol.GetKey() == _key;
		});
		if (it == vec.end()) throw "Polynom doesn't exist";
		*it = std::move(*(vec.end() - 1));
		vec.pop_back();
	}
	Named_Polynom Search(Key _key) {	
		auto it = std::find_if(vec.begin(), vec.end(), [&_key](const Named_Polynom& pol) { // RU: Да, слишком сложно, но давно хотел попробовать...
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


public:
	void Insert(const Named_Polynom& pol) { // RU: Да, слишком сложно, но давно хотел попробовать...
		vec.insert(
			std::lower_bound(
				vec.begin(), vec.end(),
				pol,
				[](const Named_Polynom& p1, const Named_Polynom& p2) {return p1.GetKey()<p2.GetKey(); }
			),
			pol);
	}

	void Delete(Key _key) {
		auto it = std::lower_bound( // RU: Да, слишком сложно, но давно хотел попробовать...
			vec.begin(), vec.end(),
			_key,
			[] (const Named_Polynom& p, const Key& k) {return p.GetKey() < k; }
		);
		if (it == vec.end() || !(it->GetKey() == _key)) throw "Polynom doesn't exist";
		vec.erase(it);
	}

	Named_Polynom Search(Key _key) {
		auto it = std::lower_bound( // RU: Да, слишком сложно, но давно хотел попробовать...
			vec.begin(), vec.end(),
			_key,
			[](const Named_Polynom& p, const Key& k) {return p.GetKey()<k; }
		);
		if (it==vec.end() ||!(it->GetKey() == _key)) throw "Polynom doesn't exist";
		return *it;
	}
	void clear() { vec.clear(); }
};