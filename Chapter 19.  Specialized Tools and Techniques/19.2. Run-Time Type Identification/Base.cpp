#include "Base.h"

bool operator==(const Base &lhs, const Base &rhs)
{
	cout << typeid(lhs).name() << endl;
	cout << typeid(rhs).name() << endl;
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base &rhs) const
{
	// ִ�бȽ�Base����Ĳ���
	return false;
}
