#include "Base.h"
#include "Derived.h"
#include "common.h"


int main()
{
	/*ָ��Ķ�̬ת��*/
	Base* bp = new Base;
	/*
	 * ���ϣ��ʹ��dynamic_cast�������߲��ò�ʹ��dynamic_cast������
	 * ��Ӧ��ȷ���ڶ�̬����ʹ������Ҳ���Ǽ̳���ϵ�����麯����
	 */
	if (Derived *dp = dynamic_cast<Derived*>(bp))
	{
		cout << "ʹ��dpָ���Derived����" << endl;
		cout << "dynamic_cast success" << endl;
		cout << dp->b << endl;
		cout << dp->d << endl;
	}
	else
	{
		cout << "ʹ��bpָ���Base����" << endl;
		cout << "dynamic_cast fail" << endl;
		cout << bp->b << endl;
		//cout << bp->d << endl;
	}
	/*���õĶ�̬ת������Ϊ�����ڿ����ã�������Ҫ�׳��쳣*/
	try
	{
		const Derived& d = dynamic_cast<const Derived&>(*bp);
	}
	catch (bad_cast)
	{
		cout << "����ʧ�ܵ����" << endl;
		cout << "dynamic_cast fail" << endl;
		cout << bp->b << endl;
		delete bp;
	}
	/*typeid�����*/
	Derived* dp1 = new Derived;
	Base* bp1 = dp1;
	if (typeid(*bp1) == typeid(*dp1))
	{
		cout << "bp��dpָ��ͬһ������" << endl;
	}
	else
	{
		cout << "bp��dp��ָ��ͬһ������" << endl;
	}
	if (typeid(*bp1) == typeid(Derived))
	{
		cout << "bpʵ��ָ��Derived����" << endl;
	}
	else
	{
		cout << "bp��ָ��Derived����" << endl;
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