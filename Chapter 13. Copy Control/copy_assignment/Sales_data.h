#pragma once
#include <string>
using namespace std;

class Sales_data {
public:
	// 瘾式地声明为内联的
	Sales_data() = default;
	Sales_data(const Sales_data &orig);
	Sales_data& operator=(const Sales_data &rhs);
	string& getBookNo() {
		return bookNo;
	}
private:
	string bookNo = "fuck";// 似乎只能用拷贝初始化
	int units_sold = 1;
	double revenue = 0.0;
};