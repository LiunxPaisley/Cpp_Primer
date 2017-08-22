#include "Derived.h"

bool Derived::equal(const Base &rhs) const
{
	// 两个类型是相等的，不会抛出异常
	auto r = dynamic_cast<const Derived&>(rhs);
	// 执行比较两个Derived对象的操作并返回结果
	return false;
}
