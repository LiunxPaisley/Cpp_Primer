#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include "custom_exception_class.h"
#include <string>

using std::string;
using std::size_t;

class Sales_data
{
public:
	Sales_data() {}
	Sales_data& operator+=(const Sales_data& rhs);
	string isbn() const { return bookNo; }
	size_t units_sold;
	double revenue;
private:
	string bookNo;
};

#endif
