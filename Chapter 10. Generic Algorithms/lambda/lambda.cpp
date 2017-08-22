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
	// ��words���ֵ�����ɾ���ظ�����
	elimDups(words);
	// ���������򣬳�����ͬ�ĵ���ά���ֵ���
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b)
			{return a.size() < b.size(); });
	// ��ȡһ����������ָ���һ������size()>=sz��Ԫ��
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a)
			{return a.size() >= sz; });
	// ��������size>=sz��Ԫ�ص���Ŀ
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	// ��ӡ��ʹ��lambda
	for_each(wc, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main() {
	vector<string> words = { "the","qiuck","red","fox","jumps","over","the","slow","red","turtle" };
	// ʹ��lambda,����biggies
	vector<string>::size_type sz = 4;
	biggies(words, sz);
	// ֵ��������ò���
	size_t v1 = 42;
	auto f1 = [v1] {return v1; };
	auto f2 = [&v1] {return v1; };
	v1 = 0;
	cout << "f1 = " << f1() << ",f2 = " << f2() << endl;
	// ��ʽ����
	auto wc = find_if(words.begin(), words.end(),
		[=](const string &a)// ֵ����
			{return a.size() > sz; });
	wc = find_if(words.begin(), words.end(),
		[&](const string &a)// ���ò���
			{return a.size() > sz; });
	// �ɱ�lambda���ı�ֵ���������ֵ
	v1 = 3;
	auto f3 = [v1]()mutable {return ++v1; };
	v1 = 0;
	cout << "f3 = " << f3() << endl;
	// ���ò���������޸�����������ָ����Ƿ�Ϊconst����
	v1 = 4;
	auto f4 = [&v1] {return ++v1; };
	v1 = 2;
	cout << "f4 = " << f4() << endl;
	// ָ��lambda�ķ�������,β�÷�������
	vector<int> vec_int = { 12,23,43,-1,-33,-4 };
	transform(vec_int.begin(), vec_int.end(), vec_int.begin(),
		[](int i) ->int 
		{if (i < 0)return -i; else return i; });
	cout << vec_int << endl;
	return 0;
}