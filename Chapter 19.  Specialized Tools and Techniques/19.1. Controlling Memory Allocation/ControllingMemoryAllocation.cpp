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
	// ��λnew��������new���������Ĳ���
	string *sp1 = new (nothrow) string("another value"); 
	// ��ʽ������������
	sp1->~string();
}