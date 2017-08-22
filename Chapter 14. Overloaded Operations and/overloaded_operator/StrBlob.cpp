#include "StrBlob.h"

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string & StrBlob::front() {
	// TODO: 在此处插入 return 语句
	check(0, "front on empty StrBlob");
	return data->front();
}

string & StrBlob::back() {
	// TODO: 在此处插入 return 语句
	check(0, "back on empty StrBlob");
	return data->back();
}


void StrBlob::check(size_type i, const string & msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}