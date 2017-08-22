#pragma once
#include <iostream>
using namespace std;


class SmallInt {
public:
	SmallInt(int i = 0) : val(i) {
		if (i < 0 || i>255) {
			throw out_of_range("Bad SmallInt value");
		}
	}
	// 显式的类型转换运算符
	explicit operator int() const { return val; }
private:
	size_t val;
};