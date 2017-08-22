#include "StrBlobPtr.h"

int main() {
	/*Ĭ�ϳ�ʼ��*/
	int *pi = new int;
	string *ps = new string;
	/*ֵ��ʼ��*/
	int *pi_ = new int(1024);
	string *ps_ = new string(10, '9');
	/*�б��ʼ��*/
	vector<int> *pv = new vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i, *pi1 = &i, *pi2 = nullptr;
	double *pd = new double(33.0), *pd2 = pd;
	/**
	* ����ʾ��
	* delete i; // i����ָ��
	* delete pi1; // pilָ��һ���ֲ���������deleteӦ���ͷŶ��е��ڴ棬������ջ���ڴ�
	*/
	delete pd;
	delete pi2; // �ͷſ�ָ������û���
	const int *pci = new const int(1024);
	delete pci; // �ͷ�һ��constant����

	/*shared_ptr��new���ʹ��*/
	shared_ptr<double> p1;
	shared_ptr<int> p2(new int(42));
	// shared_ptr<int> p2 = new int(1024); // ���󣺱���ʹ��ֱ�ӳ�ʼ��

	/*unique_ptr*/
	unique_ptr<double> p3;
	unique_ptr<int> p4(new int(42));
	unique_ptr<string> p5(new string("Stegosaurus"));
	// unique_ptr<string> p6(p5); // ��֧�ֿ���
	unique_ptr<string> p7;
	// p7 = p5; // ��֧�ָ�ֵ
	unique_ptr<string> p8(p5.release()); // release��p5�ÿգ�����ָ��
	unique_ptr<string> p9(new string("Text"));
	p8.reset(p9.release()); // ����Ȩ��p9ת�Ƶ�p8

	/*weak_ptr*/
	shared_ptr<int> p = make_shared<int>(42);
	weak_ptr<int> wp(p); // ʹ��shared_ptr����ʼ��

	if (shared_ptr<int> np = wp.lock()) {} // weak_ptr����ֱ�ӷ��ʶ��󣬱������lock������������򷵻ض����shared_ptr

	return 0;
}

