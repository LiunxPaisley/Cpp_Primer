#pragma once
#include "StrBlob.h"

class StrBlobPtr {
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	StrBlobPtr& operator++(); // ǰ�õ��������
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int); // ���õ��������
	StrBlobPtr operator--(int);
	string& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	string* operator->() const {
		return &this->operator*();
	}
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
