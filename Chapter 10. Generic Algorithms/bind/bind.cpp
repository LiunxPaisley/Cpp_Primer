#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
//using std::placeholders::_1;
using namespace std::placeholders;

template<typename Dtype>
ostream& operator<<(ostream& out, vector<Dtype> vec) {
	for (auto var : vec) {
		out << var << " ";
	}
	//out << endl;
	return out;
}

bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

ostream &print(ostream &os, const string &s, char c) {
	return os << s << c;
}

int main() {
	// bind�������󶨲���
	auto check6 = bind(check_size, _1, 6);
	vector<string> words = { "the","qiuck","red","fox","jumps","over","the","slow","red","turtle" };
	string::size_type sz = 4;
	auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
	cout << "bind: " << *wc << endl;
	// �����ʳ����ɶ���������
	sort(words.begin(), words.end(), isShorter);
	cout << "sort: " << words << endl;
	sort(words.begin(), words.end(), bind(isShorter, _2, _1));
	cout << "sort: " << words << endl;
	// �����ò�������ӡ��ʹ��bind
	// ���ϣ�����ݸ�bindһ���������������������ʹ�ñ�׼�⺯��ref����
	for_each(words.begin(), words.end(), bind(print, ref(cout), _1, ' '));
}