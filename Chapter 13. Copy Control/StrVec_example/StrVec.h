#pragma once
#include <memory>
#include <string>
#include <utility>
using namespace std;

class StrVec {
public:
	StrVec():
		elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(const StrVec&);
	StrVec(StrVec &&) noexcept;
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec &&) noexcept;
	~StrVec();
	void push_back(const string&);
	void push_back(string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }
private:
	static allocator<string> alloc;
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void reallocate_();
	string *elements;
	string *first_free;
	string *cap;
};


