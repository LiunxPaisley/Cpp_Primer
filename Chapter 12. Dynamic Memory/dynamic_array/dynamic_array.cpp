#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

int main() {
	/*初始化动态分配对象的数组*/
	int *pia = new int[10]; // 未初始化
	int *pia2 = new int[10](); // 值初始化为0
	string *psa = new string[10]; // 空string
	string *psa2 = new string[10](); // 空string

	int *pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };
	string *psa3 = new string[10]{ "deep","dark","fantacy",string(3,'x') };

	/*释放动态数组*/
	typedef int arrT[42];
	int *p = new arrT;
	delete[] p;

	/*智能指针和动态数组*/
	unique_ptr<int[]> up(new int[10]);
	up[0] = 1; // 指向数组的unique_ptr不支持点和箭头运算符，需使用下标运算符
	up.release(); // 自动调用delete[]销毁其指针

	/*shared_ptr不直接支持管理动态数组*/
	shared_ptr<int> sp(new int[10], [](int *p) {delete[] p; }); // 为了能使用shared_ptr，需提供自己定义的删除器
	*(sp.get() + 2) = 1; // shared_ptr未定义下标运算符，并且不支持指针的算术运算
	sp.reset();
}