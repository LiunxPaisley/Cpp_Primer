#include "Derived.h"

bool Derived::equal(const Base &rhs) const
{
	// ������������ȵģ������׳��쳣
	auto r = dynamic_cast<const Derived&>(rhs);
	// ִ�бȽ�����Derived����Ĳ��������ؽ��
	return false;
}
