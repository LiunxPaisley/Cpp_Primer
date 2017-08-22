#include "common.h"

union Token
{
	char cval;
	int ival;
	double dval;
};
int main()
{
	Token first_token = { 'a' };
	Token last_token;
	Token *pt = new Token;
	last_token.cval = 'z';
	pt->ival = 42;
}