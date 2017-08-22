#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

// 重载输出运算符<<,使其直接输出vector
template<typename Dtype>
ostream& operator<<(ostream& out, vector<Dtype> vec) {
	for (auto var : vec) {
		out << var << " ";
	}
	//out << endl;
	return out;
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

int main() {
	vector<string> vec_string = { "deep","dark","fantacy" };
	vector<int> vec_int = { 12,23,43 };
	// accumulate算法定义在头文件numeric中，对vec_int中的元素求和，和的初值为0
	cout << "accumulate算法 int : " << accumulate(vec_int.cbegin(), vec_int.cend(), 0) << endl;
	cout << "accumulate算法 string : " << accumulate(vec_string.cbegin(), vec_string.cend(), string("")) << endl;
	vector<string> vec_string_ = { "deep","dark","fantacy" };
	// equal算法，判断序列相等
	cout << "equal算法 :" << equal(vec_string.cbegin(), vec_string.cend(), vec_string_.cbegin()) << endl;
	// fill算法接受一对迭代器代表的范围
	fill(vec_int.begin(), vec_int.end(), 8);
	cout << "fill算法 :" << vec_int << endl;
	// fill_n算法
	fill_n(vec_int.begin(), 2, 7);
	cout << "fill_n算法 :" << vec_int << endl;
	//插入迭代器back_inserter
	fill_n(back_inserter(vec_string), 3, string("hey"));
	cout << "插入迭代器back_inserter :" << vec_string << endl;
	// copy拷贝算法
	vector<string> vec_null;
	auto ret = copy(vec_string.begin(), vec_string.end(), back_inserter(vec_null));
	cout << "copy拷贝算法 :" << vec_null << endl;
	// replace算法（把hey替换成shit）
	replace(vec_string.begin(), vec_string.end(), string("hey"), string("shit"));
	cout << "replace算法 :" << vec_string << endl;
	// replace_copy算法,替换副本保存在vec_string_中，原序列不变
	replace_copy(vec_string.begin(), vec_string.end(), back_inserter(vec_string_), string("hey"), string("shit"));
	cout << "replace_copy算法 :" << vec_string_ << endl;
	// 重排容器元素的算法
	vector<string> words = { "the","qiuck","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(words);
	cout << "重排容器元素的算法 :" << words << endl;
	return 0;
}