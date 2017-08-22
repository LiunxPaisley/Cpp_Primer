#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void test_insert() {
	map<string, size_t> word_count;
	string word;
	cin.clear();// 由于上次的输入EOF使cin流已经处于无效状态，cin.clear()，使流处于有效状态
	while (cin >> word) {/*hey hey hey the boy next door deep dark fantacy*/
		// 插入一个元素，关键字等于word，值为1；
		// 若word已在word_count中，insert什么也不做
		pair<map<string, size_t>::iterator, bool> ret = word_count.insert({ word,1 });
		if (!ret.second) {
			++ret.first->second;
		}
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}

int main() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {/*hey hey hey the boy next door*/
		++word_count[word];
	}
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i < 10; i++) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.cbegin(), ivec.cend());
	cout << "cin.fail()=" << cin.fail() << endl;
	/*关联容器迭代器*/
	auto map_it = word_count.begin();/* *map_it是指向一个pair<const string,size_t>对象的引用*/
	cout << "map_it: " << map_it->first << " " << map_it->second << endl;
	++map_it->second;//map_it->first = "new key"; // 关键字是const的

	/*set迭代器是const的*/
	set<int>::iterator set_it = iset.begin();
	if (set_it != iset.end()) {
		cout << "set_it: " << *set_it << endl;//*set_it = 42; // set关键字是只读的
	}

	/*遍历关联容器*/
	while (map_it != word_count.cend()) {
		cout << "map_it遍历： " << map_it->first << " occurs " << map_it->second << " times" << endl;
		++map_it;
	}

	/*添加元素*/
	vector<int> vec2 = { 2,4,6,8,2,4,6,8 };
	set<int> set2;
	set2.insert(vec2.cbegin(), vec2.cend());// 注意这里必须使用cbegin和cend
	set2.insert({ 1,3,5,7,1,3,5,7 });
	cout << "set2: ";
	for (const auto &var : set2) {
		cout << var << " ";
	}
	cout << endl;
	string word2 = "new word";
	word_count.insert({ word2, 1 });
	word_count.insert(make_pair(word2, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));

	/*检测insert的返回值*/
	test_insert();

	/*删除元素*/
	multimap<string, string> authors;
	authors.insert({ "Barth, John","Sot-Weed Factor" });
	authors.insert({ "Barth, John","Lost in the Funhouse" });
	auto cnt = authors.erase("Barth, John");
	if (cnt) {
		cout << "ok: " << cnt << " Barth, John removed" << endl;
	}
	else {
		cout << "oops: Barth, John not found" << endl;
	}

	/*访问multimap元素*/
	authors.insert({ "Barth, John","Sot-Weed Factor" });
	authors.insert({ "Barth, John","Lost in the Funhouse" });
	cout << "1. 访问multimap: " ;
	for (auto beg = authors.lower_bound("Barth, John"), end = authors.upper_bound("Barth, John");
		beg != end; ++beg) {
		cout << beg->second << " ";
	}
	cout << endl;
	cout << "2. 访问multimap: ";
	for (auto pos = authors.equal_range("Barth, John"); pos.first != pos.second; pos.first++) {
		cout << pos.first->second << " ";
	}
	cout << endl;
}