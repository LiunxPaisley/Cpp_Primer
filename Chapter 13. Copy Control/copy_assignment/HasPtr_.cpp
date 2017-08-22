#include "HasPtr_.h"

// 组合了析构函数和构造函数的操作
HasPtr_& HasPtr_::operator=(const HasPtr_ &rhs) {
	auto newps = new string(*rhs.ps); // 拷贝底层string
	delete ps; // 释放旧内存
	ps = newps; // 从右侧运算对象拷贝到本对象
	this->i = rhs.i;
	return *this; // 返回本对象
}

// 错误：多个HasPtr对象指向相同的内存
HasPtr_ f(HasPtr_ hp) {
	HasPtr_ ret = hp;
	return ret;
}