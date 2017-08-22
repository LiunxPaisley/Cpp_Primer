#pragma once
#include <string>
using namespace std;

// 行为像值的类
class HasPtr_ {
public:
	HasPtr_(const string &s = string()) :
		ps(new string(s)), i(0) {}
	HasPtr_(const HasPtr_ &p) :
		ps(new string(*p.ps)), i(p.i) {}
	HasPtr_& operator=(const HasPtr_ &);
	~HasPtr_() { delete ps; }
private:
	string *ps;
	int i;
};