#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

using namespace std;

typedef tuple<vector<Sales_data>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator> matches;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(istream& in, ostream& os, const vector<vector<Sales_data>>& files) {
	string s;
	while (in >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
			continue;
		}
		for (const auto& store : trans) {
			os << "store " << get<0>(store) << " sales:" 
				<< accumulate(get<1>(store), get<2>(store), Sales_data(s))
				<< endl;
		}
	}
}

int main() {
	/*定义和初始化*/
	tuple<string, vector<double>, int, list<int>> 
		someVal("constant", { 3.14, 2.718 }, 42, { 0,1,2,3,4,5 });
	auto item = make_tuple("0-999-78345-X", 3, 20.00);
	/*访问成员*/
	auto book = get<0>(item);
	auto cnt = get<1>(item);
	auto price = get<2>(item);
	get<2>(item) *= 0.8;

	typedef decltype(item) trans;
	size_t sz = tuple_size<trans>::value;
	tuple_element<1, trans>::type count = get<1>(item);
	/*关系和相等运算符*/
	tuple<string, string> duo("1", "2");
	tuple<size_t, size_t> twoD(1, 2);
	//bool b = (duo == twoD);
	//cout << b << endl;
	tuple<size_t, size_t, size_t> threeD(1, 2, 3);
	/*bool b1 = (twoD < threeD);
	cout << b1 << endl;*/
	tuple<size_t, size_t> origin(0, 0);
	bool b2 = (origin < twoD);
	cout << b2 << endl;
}