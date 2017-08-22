#ifndef _BASE_H_
#define _BASE_H_

#include "common.h"

class Base
{
	friend bool operator==(const Base&, const Base&);
public:
	Base() : b(32) {}
	int b;
	virtual void doSomeThing() {} // 虚函数使得RTTI生效，否则报错
protected:
	virtual bool equal(const Base&) const;
};


#endif