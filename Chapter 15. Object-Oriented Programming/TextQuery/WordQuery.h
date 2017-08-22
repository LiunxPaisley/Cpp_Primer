#pragma once
#include "Query.h"

class WordQuery {
	friend class Query;
	WordQuery(const string& s) :query_word(s) {}
	QueryResult eval(const TextQuery& t) const {
		return t.query(query_word);
	}
	string rep() const {
		return query_word;
	}
	string query_word;
};

inline Query::Query(const string &s)
	: q(new WordQuery(s)) {
}