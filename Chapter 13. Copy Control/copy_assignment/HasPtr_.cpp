#include "HasPtr_.h"

// ��������������͹��캯���Ĳ���
HasPtr_& HasPtr_::operator=(const HasPtr_ &rhs) {
	auto newps = new string(*rhs.ps); // �����ײ�string
	delete ps; // �ͷž��ڴ�
	ps = newps; // ���Ҳ�������󿽱���������
	this->i = rhs.i;
	return *this; // ���ر�����
}

// ���󣺶��HasPtr����ָ����ͬ���ڴ�
HasPtr_ f(HasPtr_ hp) {
	HasPtr_ ret = hp;
	return ret;
}