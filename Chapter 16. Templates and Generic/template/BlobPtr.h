#pragma once
#include <string>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
class BlobPtr {
public:
	BlobPtr() : curr(0) { };
	BlobPtr(Blob<T> &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {
	}
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr & operator++(int);
	BlobPtr & operator--(int);
	
private:
	shared_ptr<vector<T>> check(size_t, const string&) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};
