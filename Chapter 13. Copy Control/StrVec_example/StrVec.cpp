#pragma once
#include "StrVec.h"

StrVec::StrVec(const StrVec &s) {
	// 调用alloc_n_copy分配空间以容纳与s一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec && s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec & StrVec::operator=(const StrVec &rhs) {
	// TODO: 在此处插入 return 语句
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept
{
	// 直接检测自赋值
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
	// 确保有空间容纳新元素
	chk_n_alloc();
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s){
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

inline pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);
	// 初始化并返回一个pair
	return{ data, uninitialized_copy(b, e, data) };
}

inline void StrVec::free() {
	// 不能传递给deallocate一个空指针
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

inline void StrVec::reallocate() {
	// 我们将分配当前大小两倍的内存
	auto newcapacity = size() ? 2 * size() : 1;
	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);
	// 将数据从旧内存移动到新内存
	auto dest = newdata; // 指向新数组中下一个空闲位置
	auto elem = elements; // 指向旧数组中下一个元素
	for (size_t i = 0; i != size(); i++) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free(); // 一旦我们移动完元素就释放内存空间
	// 更新数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate_(){
	// 我们将分配当前大小两倍的内存
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(make_move_iterator(begin()),
		make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}


