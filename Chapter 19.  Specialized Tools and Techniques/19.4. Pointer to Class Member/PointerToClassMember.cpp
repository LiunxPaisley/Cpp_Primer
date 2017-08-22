#include "common.h"
#include "Screen.h"

using namespace std;

int main()
{
	/*初始化一个成员指针或为成员指针赋值时，该指针并没有指向任何数据*/
	const string Screen::* pdata;
	pdata = &Screen::contents;
	// c++11中最简单的方法
	// auto pdata = &Screen::contents;
	Screen myScreen;
	Screen* pScreen = &myScreen;
	auto s = myScreen.*pdata;
	s = pScreen->*pdata;

	const string Screen::* pdata1 = Screen::data();
	auto s1 = myScreen.*pdata1;

	/*成员函数指针*/
	auto pmf = &Screen::get_cursor;
	// 如果有重载，则需要指明
	char (Screen::*pmf1)(Screen::pos, Screen::pos) const;
	pmf1 = &Screen::get;

	char c1 = (pScreen->*pmf)();
	char c2 = (myScreen.*pmf1)(0, 0);

	using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
	Action get = &Screen::get;
	Screen& action(Screen&, Action = &Screen::get);
	action(myScreen);
	action(myScreen, get);
	action(myScreen, &Screen::get);

	/*成员指针函数表*/
	myScreen.move(Screen::HOME);
	myScreen.move(Screen::DOWN);

	/*将成员函数用作可调用对象，使用function生成一个可调用对象*/
	vector<string> svec = { "deep", "dark", "fantacy" };
	function<bool(const string&)> fcn = &string::empty;
	find_if(svec.begin(), svec.end(), fcn);

	/*使用mem_fn生成一个可调用对象*/
	find_if(svec.begin(), svec.end(), mem_fn(&string::empty));
	auto f = mem_fn(&string::empty);// f接受一个string或者一个string*
	f(*svec.begin()); // 传入一个string对象，f使用.*调用empty
	f(&svec[0]); // 传入一个string指针，f使用->*调用empty

	/*使用bind生成一个可调用对象*/
	find_if(svec.begin(), svec.end(), bind(&string::empty, _1));
	auto f1 = bind(&string::empty, _1);
	f1(*svec.begin());
	f1(&svec[0]);
}