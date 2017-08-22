#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

int main() {
	int n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);

	
	auto q = p;
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");

	cout << *p << endl;
	// cout << *q << endl; // 错误，q指向未构造的内存

	while (q != p) {
		alloc.destroy(--q); // 销毁元素，不是释放内存
	}
	alloc.deallocate(p, n); // 释放内存
	
	allocator<int> alloc_int;
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto s = alloc_int.allocate(vi.size() * 2);
	auto t = uninitialized_copy(vi.begin(), vi.end(), s);
	uninitialized_fill_n(t, vi.size(), 42);
	cout << "allocate: ";
	for (int i = 0; i < vi.size() * 2; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}