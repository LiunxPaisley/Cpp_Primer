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

inline double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0.0;
}

ostream& operator<<(ostream& os, const Sales_data &item) {
	os << item.isbn() << " "
		<< item.units_sold << " "
		<< item.revenue << " "
		<< item.avg_price();
}

istream& operator >> (istream& is, Sales_data &item) {
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is) // 检查输入是否成功
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}

