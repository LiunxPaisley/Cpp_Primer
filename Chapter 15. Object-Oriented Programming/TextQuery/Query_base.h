#pragma once
#include "QueryResult.h"

class Query_base {
	friend class Query;
public:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};