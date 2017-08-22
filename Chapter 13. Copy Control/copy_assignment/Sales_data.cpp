#include "Sales_data.h"

Sales_data::Sales_data()
{}

// 拷贝构造函数
// 拷贝初始化通常使用拷贝构造函数完成
Sales_data::Sales_data(const Sales_data &orig) :
	bookNo(orig.bookNo),
	units_sold(orig.units_sold),
	revenue(orig.revenue)
{}

// 等价于合成拷贝运算符
Sales_data& Sales_data::operator=(const Sales_data &rhs) {
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}