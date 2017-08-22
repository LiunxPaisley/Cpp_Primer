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
	// ��ʽ������ת�������
	explicit operator int() const { return val; }
private:
	size_t val;
};