#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include "common.h"

class TextQuery
{
public:
	typedef size_t line_no;
	class QueryResult;
	QueryResult query(const string& sought) const;
};

#endif
