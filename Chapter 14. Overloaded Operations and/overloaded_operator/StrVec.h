#pragma once
#include <memory>
#include <string>
#include <utility>

using namespace std;

class StrVec {
public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(StrVec &&) noexcept;
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec &&) noexcept;// 移动赋值运算符
	StrVec& operator=(initializer_list<string>);
	string& operator[](size_t n) { return elements[n]; }
	const string& operator[](size_t n) const { return elements[n]; } // 后一个const能区分重载
	~StrVec();
	void push_back(const string&);
	void push_back(string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }
private:
	static allocator<string> alloc;
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void reallocate_(); // 使用对象移动
	string *elements;
	string *first_free;
	string *cap;
};
