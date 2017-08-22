#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Sales_data {
	string isbn() const { return bookNo; };
	Sales_data & combine(const Sales_data &rhs);
	double avg_price() const;
	Sales_data(string s);
	string bookNo;
	unsigned int units_sold;
	double revenue = 0.0;
};

Sales_data & Sales_data::combine(const Sales_data &rhs) {
	// TODO: 在此处插入 return 语句
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const {
	return 0.0;
}

Sales_data::Sales_data(string s) {
	this->bookNo = s;
}

size_t hasher(const Sales_data &sd) {
	return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() == rhs.isbn();
}

int main() {
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word) {/*hey hey hey the boy next door*/
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}

	/*将类作为无序容器的关键字*/
	using SD_multiset = unordered_set<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	SD_multiset bookstore(42, hasher, eqOp);// 参数是桶大小，哈希函数指针和相等性判断运算符指针
	vector<Sales_data*> sdvec = { new Sales_data("hey"),new Sales_data("boy"),new Sales_data("next"),new Sales_data("door") };
	for (auto &var : sdvec) {
		bookstore.insert(*var);
	}
	cout << "unordered_set: ";
	for (auto &var : bookstore) {
		cout << var.isbn() << " ";
	}
	cout << endl;
}


