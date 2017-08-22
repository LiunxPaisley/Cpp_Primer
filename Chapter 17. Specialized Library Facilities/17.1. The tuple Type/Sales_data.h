#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sales_data {
public:
	Sales_data() = default;// 隐式地声明为内联的
	Sales_data(const string& s) : bookNo(s){ }
	Sales_data(const string& s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(p*n){ }
	Sales_data(const Sales_data &orig);
	Sales_data& operator=(const Sales_data& rhs);
	Sales_data& operator+=(const Sales_data& rhs);
	double avg_price() const;
	string isbn() const {
		return bookNo;
	}
	// 就地初始化
	string bookNo = "fuck"; // ISBN
	int units_sold = 1; // 销售数量
	double revenue = 0.0; // 销售收入
};

ostream& operator<<(ostream& os, const Sales_data &item) {
	os << item.isbn() << " "
		<< item.units_sold << " "
		<< item.revenue << " "
		<< item.avg_price();
	return os;
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