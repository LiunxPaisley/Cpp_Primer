#include "HasPtr.h"

// ��������������͹��캯���Ĳ���
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	// �ȵ����Ҳ���������������ݼ�����������������������Ը�ֵ
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

// ע��rhs�ǰ�ֵ���ݵģ���ζ��HasPtr�Ŀ������캯��
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

HasPtr::~HasPtr() {
	if (--*use == 0) {// ���ô���ֻ��1�Σ���ֻ�иö�������
		delete ps;
		delete use;
	}
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}