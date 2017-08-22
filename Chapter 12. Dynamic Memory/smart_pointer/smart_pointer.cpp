#include "StrBlobPtr.h"

int main() {
	/*默认初始化*/
	int *pi = new int;
	string *ps = new string;
	/*值初始化*/
	int *pi_ = new int(1024);
	string *ps_ = new string(10, '9');
	/*列表初始化*/
	vector<int> *pv = new vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i, *pi1 = &i, *pi2 = nullptr;
	double *pd = new double(33.0), *pd2 = pd;
	/**
	* 错误示范
	* delete i; // i不是指针
	* delete pi1; // pil指向一个局部变量，即delete应当释放堆中的内存，而不是栈中内存
	*/
	delete pd;
	delete pi2; // 释放空指针总是没错的
	const int *pci = new const int(1024);
	delete pci; // 释放一个constant对象

	/*shared_ptr和new结合使用*/
	shared_ptr<double> p1;
	shared_ptr<int> p2(new int(42));
	// shared_ptr<int> p2 = new int(1024); // 错误：必须使用直接初始化

	/*unique_ptr*/
	unique_ptr<double> p3;
	unique_ptr<int> p4(new int(42));
	unique_ptr<string> p5(new string("Stegosaurus"));
	// unique_ptr<string> p6(p5); // 不支持拷贝
	unique_ptr<string> p7;
	// p7 = p5; // 不支持赋值
	unique_ptr<string> p8(p5.release()); // release将p5置空，返回指针
	unique_ptr<string> p9(new string("Text"));
	p8.reset(p9.release()); // 所有权从p9转移到p8

	/*weak_ptr*/
	shared_ptr<int> p = make_shared<int>(42);
	weak_ptr<int> wp(p); // 使用shared_ptr来初始化

	if (shared_ptr<int> np = wp.lock()) {} // weak_ptr不能直接访问对象，必须调用lock，若对象存在则返回对象的shared_ptr

	return 0;
}

