#pragma once
#include <string>
using namespace std;

// ��Ϊ��ָ�����
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string &s = string()) :
		ps(new string(s)), i(0), use(new size_t()) {}
	HasPtr(const HasPtr &p) :
		ps(new string(*p.ps)), i(p.i), use(p.use) {
		++*use;
	}
	// ��ӵ��ƶ����캯��
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
	HasPtr& operator=(const HasPtr &);
	// ��ֵ����������ƶ���ֵ�������Ҳ�ǿ�����ֵ�����
	// rhs����ʹ�ÿ������캯�������ƶ����캯����ʼ��
	HasPtr& operator=(HasPtr rhs);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};
