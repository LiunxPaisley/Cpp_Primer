#pragma once
#include "Query.h"

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query& l, const Query& r, string s)
		: lhs(l), rhs(r), opSym(s) {
	}
	string rep() const {
		return "(" + lhs.rep() + " "
			+ opSym + " "
			+ rhs.rep() + " ";
	}
	Query lhs, rhs;
	string opSym;
};