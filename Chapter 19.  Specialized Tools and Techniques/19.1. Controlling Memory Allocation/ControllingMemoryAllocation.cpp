#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string *sp = new string("a value");
	string *arr = new string[10];
	delete sp;
	delete[] arr;
	// 定位new，允许向new传递其他的参数
	string *sp1 = new (nothrow) string("another value"); 
	// 显式析构函数调用
	sp1->~string();
}