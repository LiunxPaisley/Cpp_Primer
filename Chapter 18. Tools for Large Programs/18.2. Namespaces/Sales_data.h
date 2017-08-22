#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include <string>
#include <iostream>
namespace cplusplus_primer
{
	class Sales_data {/*...*/};
	Sales_data operator+(const Sales_data&, const Sales_data&);
	std::istream& operator>>(std::istream& in, Sales_data& s);
}

#endif
