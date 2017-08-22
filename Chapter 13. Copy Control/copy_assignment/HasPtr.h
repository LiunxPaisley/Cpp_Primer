#pragma once
#include <string>
using namespace std;

// 行为像指针的类
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string &s = string()) :
		ps(new string(s)), i(0), use(new size_t()) {}
	HasPtr(const HasPtr &p) :
		ps(new string(*p.ps)), i(p.i), use(p.use) {
		++*use;
	}
	// 添加的移动构造函数
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
	HasPtr& operator=(const HasPtr &);
	// 赋值运算符既是移动赋值运算符，也是拷贝赋值运算符
	// rhs可以使用拷贝构造函数或者移动构造函数初始化
	HasPtr& operator=(HasPtr rhs);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};
