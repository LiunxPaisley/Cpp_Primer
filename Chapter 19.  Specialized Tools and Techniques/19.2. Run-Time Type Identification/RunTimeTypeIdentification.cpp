#include "Base.h"
#include "Derived.h"
#include "common.h"


int main()
{
	/*指针的动态转换*/
	Base* bp = new Base;
	/*
	 * 如果希望使用dynamic_cast技术或者不得不使用dynamic_cast技术，
	 * 那应该确保在多态类上使用它（也就是继承体系里有虚函数）
	 */
	if (Derived *dp = dynamic_cast<Derived*>(bp))
	{
		cout << "使用dp指向的Derived对象" << endl;
		cout << "dynamic_cast success" << endl;
		cout << dp->b << endl;
		cout << dp->d << endl;
	}
	else
	{
		cout << "使用bp指向的Base对象" << endl;
		cout << "dynamic_cast fail" << endl;
		cout << bp->b << endl;
		//cout << bp->d << endl;
	}
	/*引用的动态转换，因为不存在空引用，所以需要抛出异常*/
	try
	{
		const Derived& d = dynamic_cast<const Derived&>(*bp);
	}
	catch (bad_cast)
	{
		cout << "处理失败的情况" << endl;
		cout << "dynamic_cast fail" << endl;
		cout << bp->b << endl;
		delete bp;
	}
	/*typeid运算符*/
	Derived* dp1 = new Derived;
	Base* bp1 = dp1;
	if (typeid(*bp1) == typeid(*dp1))
	{
		cout << "bp和dp指向同一个对象" << endl;
	}
	else
	{
		cout << "bp和dp不指向同一个对象" << endl;
	}
	if (typeid(*bp1) == typeid(Derived))
	{
		cout << "bp实际指向Derived对象" << endl;
	}
	else
	{
		cout << "bp不指向Derived对象" << endl;
	}

	cout << "bp1 before dp1 is "
		<< (typeid(bp1).before(typeid(dp1)) ? "true" : "false") << endl;
	int arr[10];
	Derived d;
	Base *p = &d;
	cout << typeid(42).name() << ", "
		<< typeid(arr).name() << ", "
		<< typeid(std::string).name() << ", "
		<< typeid(p).name() << ", "
		<< typeid(*p).name() << endl;
}