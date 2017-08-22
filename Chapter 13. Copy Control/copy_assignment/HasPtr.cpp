#include "HasPtr.h"

// 组合了析构函数和构造函数的操作
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	// 先递增右侧运算对象计数，后递减左侧运算对象计数，来处理自赋值
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	use = rhs.use;
	i = rhs.i;
	return *this;
}

// 注意rhs是按值传递的，意味着HasPtr的拷贝构造函数
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

HasPtr::~HasPtr() {
	if (--*use == 0) {// 引用次数只有1次，即只有该对象引用
		delete ps;
		delete use;
	}
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}