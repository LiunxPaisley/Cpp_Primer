#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename Dtype>
ostream& operator<<(ostream& out, vector<Dtype> vec) {
	for (auto var : vec) {
		out << var << " ";
	}
	//out << endl;
	return out;
}

template<typename Dtype>
ostream& operator<<(ostream& out, list<Dtype> lst) {
	for (auto var : lst) {
		out << var << " ";
	}
	//out << endl;
	return out;
}

int main() {
	// 插入迭代器
	list<int> lst = { 1,2,3,4 };
	list<int> lst2, lst3;
	copy(lst.begin(), lst.end(), front_inserter(lst2));
	cout << "front_inserter: " << lst2 << endl;
	copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
	cout << "inserter: " << lst3 << endl;
	// istream_iterator迭代器
	/*istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	while (in_iter != eof) {
		vec.push_back(*in_iter++);
	}*/
	// 重写以上代码
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	cout << "istream_iterato accumulate: " << accumulate(in_iter, eof, 0) << endl;
	vector<int> vec_in(in_iter, eof);
	// 使用算法操作流迭代器

	// ostream_iterator迭代器
	ostream_iterator<int> out_iter(cout, " ");
	cout << "ostream_iterator: ";
	for (auto e : vec_in) {
		out_iter = e;// 写入绑定的输出流
	}
	cout << endl;
	// 反向迭代器
	vector<int> vec = { 0,4,5,6,1,2,3,7,8,9 };
	for (auto r_iter = vec.rbegin(); r_iter != vec.rend(); r_iter++) {
		cout << *r_iter << " ";
	}
	cout << endl;
	sort(vec.begin(), vec.end());
	cout << "sort: " << vec << endl;
	sort(vec.rbegin(), vec.rend());
	cout << "sort: " << vec << endl;
	// 反向迭代器与其他迭代器的关系
	string line = "FIRST,MIDDLE,LAST";
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	// 得到一个正向迭代器
	cout << "last: " << string(rcomma.base(), line.cend()) << endl;
	return 0;
}