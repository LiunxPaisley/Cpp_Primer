#include "Sales_data.h"

Sales_data::Sales_data()
{}

// �������캯��
// ������ʼ��ͨ��ʹ�ÿ������캯�����
Sales_data::Sales_data(const Sales_data &orig) :
	bookNo(orig.bookNo),
	units_sold(orig.units_sold),
	revenue(orig.revenue)
{}

// �ȼ��ںϳɿ��������
Sales_data& Sales_data::operator=(const Sales_data &rhs) {
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}