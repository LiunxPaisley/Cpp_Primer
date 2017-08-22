#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

int main() {
	/*��ʼ����̬������������*/
	int *pia = new int[10]; // δ��ʼ��
	int *pia2 = new int[10](); // ֵ��ʼ��Ϊ0
	string *psa = new string[10]; // ��string
	string *psa2 = new string[10](); // ��string

	int *pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };
	string *psa3 = new string[10]{ "deep","dark","fantacy",string(3,'x') };

	/*�ͷŶ�̬����*/
	typedef int arrT[42];
	int *p = new arrT;
	delete[] p;

	/*����ָ��Ͷ�̬����*/
	unique_ptr<int[]> up(new int[10]);
	up[0] = 1; // ָ�������unique_ptr��֧�ֵ�ͼ�ͷ���������ʹ���±������
	up.release(); // �Զ�����delete[]������ָ��

	/*shared_ptr��ֱ��֧�ֹ���̬����*/
	shared_ptr<int> sp(new int[10], [](int *p) {delete[] p; }); // Ϊ����ʹ��shared_ptr�����ṩ�Լ������ɾ����
	*(sp.get() + 2) = 1; // shared_ptrδ�����±�����������Ҳ�֧��ָ�����������
	sp.reset();
}