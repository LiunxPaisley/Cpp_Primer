#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename Dtype>
ostream& operator<<(ostream& out, vector<Dtype> vec) {
	for (auto var : vec) {
		out << var << " ";
	}
	//out << endl;
	return out;
}

string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	// 将words按字典排序，删除重复单词
	elimDups(words);
	// 按长度排序，长度相同的单词维持字典序
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b)
			{return a.size() < b.size(); });
	// 获取一个迭代器，指向第一个满足size()>=sz的元素
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a)
			{return a.size() >= sz; });
	// 计算满足size>=sz的元素的数目
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	// 打印，使用lambda
	for_each(wc, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main() {
	vector<string> words = { "the","qiuck","red","fox","jumps","over","the","slow","red","turtle" };
	// 使用lambda,调用biggies
	vector<string>::size_type sz = 4;
	biggies(words, sz);
	// 值捕获和引用捕获
	size_t v1 = 42;
	auto f1 = [v1] {return v1; };
	auto f2 = [&v1] {return v1; };
	v1 = 0;
	cout << "f1 = " << f1() << ",f2 = " << f2() << endl;
	// 隐式捕获
	auto wc = find_if(words.begin(), words.end(),
		[=](const string &a)// 值捕获
			{return a.size() > sz; });
	wc = find_if(words.begin(), words.end(),
		[&](const string &a)// 引用捕获
			{return a.size() > sz; });
	// 可变lambda，改变值捕获变量的值
	v1 = 3;
	auto f3 = [v1]()mutable {return ++v1; };
	v1 = 0;
	cout << "f3 = " << f3() << endl;
	// 引用捕获变量的修改依赖于引用指向的是否为const类型
	v1 = 4;
	auto f4 = [&v1] {return ++v1; };
	v1 = 2;
	cout << "f4 = " << f4() << endl;
	// 指定lambda的返回类型,尾置返回类型
	vector<int> vec_int = { 12,23,43,-1,-33,-4 };
	transform(vec_int.begin(), vec_int.end(), vec_int.begin(),
		[](int i) ->int 
		{if (i < 0)return -i; else return i; });
	cout << vec_int << endl;
	return 0;
}