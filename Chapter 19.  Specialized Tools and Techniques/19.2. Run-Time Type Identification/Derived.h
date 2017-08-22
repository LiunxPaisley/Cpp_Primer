#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "Base.h"
#include "common.h"

class Derived : public Base
{
public:
	Derived()
		:Base(), d(42) {}
	int d;
protected:
	bool equal(const Base&) const override;
};

#endif
