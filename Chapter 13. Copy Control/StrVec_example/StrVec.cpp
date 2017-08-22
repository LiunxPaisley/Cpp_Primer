#pragma once
#include "StrVec.h"

StrVec::StrVec(const StrVec &s) {
	// ����alloc_n_copy����ռ���������sһ�����Ԫ��
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec && s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec & StrVec::operator=(const StrVec &rhs) {
	// TODO: �ڴ˴����� return ���
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept
{
	// ֱ�Ӽ���Ը�ֵ
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec() {
	free();
}

void StrVec::push_back(const string &s) {
	// ȷ���пռ�������Ԫ��
	chk_n_alloc();
	// ��first_freeָ���Ԫ���й���s�ĸ���
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s){
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

inline pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	// ����ռ䱣�������Χ�е�Ԫ��
	auto data = alloc.allocate(e - b);
	// ��ʼ��������һ��pair
	return{ data, uninitialized_copy(b, e, data) };
}

inline void StrVec::free() {
	// ���ܴ��ݸ�deallocateһ����ָ��
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

inline void StrVec::reallocate() {
	// ���ǽ����䵱ǰ��С�������ڴ�
	auto newcapacity = size() ? 2 * size() : 1;
	// �������ڴ�
	auto newdata = alloc.allocate(newcapacity);
	// �����ݴӾ��ڴ��ƶ������ڴ�
	auto dest = newdata; // ָ������������һ������λ��
	auto elem = elements; // ָ�����������һ��Ԫ��
	for (size_t i = 0; i != size(); i++) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free(); // һ�������ƶ���Ԫ�ؾ��ͷ��ڴ�ռ�
	// �������ݽṹ��ִ����Ԫ��
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate_(){
	// ���ǽ����䵱ǰ��С�������ڴ�
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(make_move_iterator(begin()),
		make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}


