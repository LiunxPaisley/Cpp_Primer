#include "StrBlobPtr.h" 

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret) {
		throw runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw out_of_range(msg);
	}
	return ret;
}

string & StrBlobPtr::deref() const {
	// TODO: 在此处插入 return 语句
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr & StrBlobPtr::incr() {
	// TODO: 在此处插入 return 语句
	check(curr, "increment past end of StrBlobOtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() { 
	return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}