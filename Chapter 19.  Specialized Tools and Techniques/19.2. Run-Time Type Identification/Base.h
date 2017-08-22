#ifndef _BASE_H_
#define _BASE_H_

#include "common.h"

class Base
{
	friend bool operator==(const Base&, const Base&);
public:
	Base() : b(32) {}
	int b;
	virtual void doSomeThing() {} // �麯��ʹ��RTTI��Ч�����򱨴�
protected:
	virtual bool equal(const Base&) const;
};


#endif