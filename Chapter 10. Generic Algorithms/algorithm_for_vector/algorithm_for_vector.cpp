#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

// ������������<<,ʹ��ֱ�����vector
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
	// accumulate�㷨������ͷ�ļ�numeric�У���vec_int�е�Ԫ����ͣ��͵ĳ�ֵΪ0
	cout << "accumulate�㷨 int : " << accumulate(vec_int.cbegin(), vec_int.cend(), 0) << endl;
	cout << "accumulate�㷨 string : " << accumulate(vec_string.cbegin(), vec_string.cend(), string("")) << endl;
	vector<string> vec_string_ = { "deep","dark","fantacy" };
	// equal�㷨���ж��������
	cout << "equal�㷨 :" << equal(vec_string.cbegin(), vec_string.cend(), vec_string_.cbegin()) << endl;
	// fill�㷨����һ�Ե���������ķ�Χ
	fill(vec_int.begin(), vec_int.end(), 8);
	cout << "fill�㷨 :" << vec_int << endl;
	// fill_n�㷨
	fill_n(vec_int.begin(), 2, 7);
	cout << "fill_n�㷨 :" << vec_int << endl;
	//���������back_inserter
	fill_n(back_inserter(vec_string), 3, string("hey"));
	cout << "���������back_inserter :" << vec_string << endl;
	// copy�����㷨
	vector<string> vec_null;
	auto ret = copy(vec_string.begin(), vec_string.end(), back_inserter(vec_null));
	cout << "copy�����㷨 :" << vec_null << endl;
	// replace�㷨����hey�滻��shit��
	replace(vec_string.begin(), vec_string.end(), string("hey"), string("shit"));
	cout << "replace�㷨 :" << vec_string << endl;
	// replace_copy�㷨,�滻����������vec_string_�У�ԭ���в���
	replace_copy(vec_string.begin(), vec_string.end(), back_inserter(vec_string_), string("hey"), string("shit"));
	cout << "replace_copy�㷨 :" << vec_string_ << endl;
	// ��������Ԫ�ص��㷨
	vector<string> words = { "the","qiuck","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(words);
	cout << "��������Ԫ�ص��㷨 :" << words << endl;
	return 0;
}