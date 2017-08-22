#include "TextQuery.h"

class TextQuery::QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>);
	//QueryResult();
	static int static_mem;
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

TextQuery::QueryResult::QueryResult(string s, 
	shared_ptr<set<line_no>> p, 
	shared_ptr<vector<string>> f)
	: sought(s), lines(p), file(f) { }

int TextQuery::QueryResult::static_mem = 1024;

TextQuery::QueryResult TextQuery::query(const string & sought) const
{
	string s;
	shared_ptr<set<line_no>> ssl;
	shared_ptr<vector<string>> svs;
	return QueryResult(s, ssl, svs);
}
