#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Tokens {INLINE = 128, VIRTUAL = 129};
void ff(Tokens);
void ff(int);
void newf(unsigned char);
void newf(int);

int main()
{
	// 不限定作用域的枚举类型
	enum color { red, yellow, green };
	//enum stoplight { red, yellow, green };
	// 限定了作用域的枚举类型，枚举成员被隐藏
	enum class peppers { red, yellow, green };

	color eyes = green;
	//peppers p = green;
	color hair = color::red; // 显式访问枚举成员
	peppers p2 = peppers::red; // 访问成员

	// 指定enum的大小
	enum class intTypes
	{
		charTyp = 8, shortTyp = 16, intTyp = 16, 
		longTyp = 32, long_longTyp = 64
	};
	constexpr intTypes charbits = intTypes::charTyp;
	int i = color::red;
	// int j = peppers::red; // 限定作用域的枚举类型不会隐式转换

	// 枚举类型的前置声明
	enum intValues : unsigned long long;// 不限定作用域的，必须指定成员类型
	enum class open_modes;//限定作用域的枚举类型可以使用默认成员类型int

	// 形参匹配和枚举类型
	Tokens curTok = INLINE;
	ff(128);
	ff(INLINE);
	ff(curTok);
	unsigned char uc = VIRTUAL;
	newf(VIRTUAL);
	newf(uc);
	return 0;
}