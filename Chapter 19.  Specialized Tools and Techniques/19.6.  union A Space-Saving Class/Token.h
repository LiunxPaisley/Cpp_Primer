#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "common.h"

class Token
{
public:
	Token() : tok(INT), ival{0} { }
	Token(const Token &t) : tok(t.tok) { copyUnion(t); }
	Token &operator=(const Token&);
	~Token() { if (tok == STR) sval.~string(); }
	Token &operator=(const string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
private:
	enum{INT, CHAR, DBL, STR} tok;
	union
	{
		char cval;
		int ival;
		double dval;
		string sval;
	};
	void copyUnion(const Token&);
};


#endif

