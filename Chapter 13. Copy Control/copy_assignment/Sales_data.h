#pragma once
#include <string>
using namespace std;

class Sales_data {
public:
	// �ʽ������Ϊ������
	Sales_data() = default;
	Sales_data(const Sales_data &orig);
	Sales_data& operator=(const Sales_data &rhs);
	string& getBookNo() {
		return bookNo;
	}
private:
	string bookNo = "fuck";// �ƺ�ֻ���ÿ�����ʼ��
	int units_sold = 1;
	double revenue = 0.0;
};