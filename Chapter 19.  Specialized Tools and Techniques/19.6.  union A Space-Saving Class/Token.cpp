#include "Token.h"

Token & Token::operator=(const Token &t)
{
	// TODO: 在此处插入 return 语句
	if (tok == STR && t.tok != STR) sval.~string();
	if (tok == STR && t.tok == STR)
	{
		sval = t.sval;
	}
	else
	{
		copyUnion(t);
	}
	tok = t.tok;
	return *this;
}

Token & Token::operator=(const string &s)
{
	// TODO: 在此处插入 return 语句
	if (tok == STR)
	{
		sval = s;
	}
	else
	{
		new(&sval) string(s);
	}
	tok = STR;
	return *this;
}

Token & Token::operator=(int i)
{
	// TODO: 在此处插入 return 语句
	if (tok == STR)
	{
		sval.~basic_string();
	}
	ival = i;
	tok = INT;
	return *this;
}

void Token::copyUnion(const Token &t)
{
	switch (t.tok)
	{
		case Token::INT: ival = t.ival; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::DBL: dval = t.dval; break;
		case Token::STR: new(&sval) string(t.sval); break;
	}
}
