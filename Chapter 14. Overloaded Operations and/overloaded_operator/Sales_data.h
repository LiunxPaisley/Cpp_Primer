#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sales_data {
public:
	Sales_data() = default;// ��ʽ������Ϊ������
	Sales_data(const Sales_data &orig);
	Sales_data& operator=(const Sales_data& rhs);
	Sales_data& operator+=(const Sales_data& rhs);
	double avg_price() const;
	string isbn() const {
		return bookNo;
	}
	// �͵س�ʼ��
	string bookNo = "fuck"; // ISBN
	int units_sold = 1; // ��������
	double revenue = 0.0; // ��������
};

