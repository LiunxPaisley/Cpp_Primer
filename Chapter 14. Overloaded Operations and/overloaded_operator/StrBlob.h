#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
//#include "StrBlobPtr.h"
using namespace std;

class StrBlob {
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); };
	bool empty() const { return data->empty(); };

	void push_back(const string &t) { data->push_back(t); };
	void pop_back();

	string& front();
	string& back();
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
}; 





