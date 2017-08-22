#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sales_data {
public:
	Sales_data() = default;// 隐式地声明为内联的
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

