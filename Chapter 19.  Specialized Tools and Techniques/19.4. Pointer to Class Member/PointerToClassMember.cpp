#include "common.h"
#include "Screen.h"

using namespace std;

int main()
{
	/*��ʼ��һ����Աָ���Ϊ��Աָ�븳ֵʱ����ָ�벢û��ָ���κ�����*/
	const string Screen::* pdata;
	pdata = &Screen::contents;
	// c++11����򵥵ķ���
	// auto pdata = &Screen::contents;
	Screen myScreen;
	Screen* pScreen = &myScreen;
	auto s = myScreen.*pdata;
	s = pScreen->*pdata;

	const string Screen::* pdata1 = Screen::data();
	auto s1 = myScreen.*pdata1;

	/*��Ա����ָ��*/
	auto pmf = &Screen::get_cursor;
	// ��������أ�����Ҫָ��
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

	/*��Աָ�뺯����*/
	myScreen.move(Screen::HOME);
	myScreen.move(Screen::DOWN);

	/*����Ա���������ɵ��ö���ʹ��function����һ���ɵ��ö���*/
	vector<string> svec = { "deep", "dark", "fantacy" };
	function<bool(const string&)> fcn = &string::empty;
	find_if(svec.begin(), svec.end(), fcn);

	/*ʹ��mem_fn����һ���ɵ��ö���*/
	find_if(svec.begin(), svec.end(), mem_fn(&string::empty));
	auto f = mem_fn(&string::empty);// f����һ��string����һ��string*
	f(*svec.begin()); // ����һ��string����fʹ��.*����empty
	f(&svec[0]); // ����һ��stringָ�룬fʹ��->*����empty

	/*ʹ��bind����һ���ɵ��ö���*/
	find_if(svec.begin(), svec.end(), bind(&string::empty, _1));
	auto f1 = bind(&string::empty, _1);
	f1(*svec.begin());
	f1(&svec[0]);
}