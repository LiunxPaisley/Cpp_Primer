#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

vector<unsigned> good_randVec() {
	static default_random_engine e3;
	static uniform_int_distribution<unsigned> u3(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 30; ++i) {
		ret.push_back(u3(e3));
	}
	return ret;
}

bool play(bool first) {
	default_random_engine e;
	bernoulli_distribution b;
	return b(e);
}

void print(unsigned i) {
	cout << i << " ";
}
int main() {
	/*���������*/
	default_random_engine e1;
	for (size_t i = 0; i < 10; i++) {
		cout << e1() << " ";
	}
	cout << endl;

	/*����ֲ�����*/
	uniform_int_distribution<unsigned> u2(0, 9);
	default_random_engine e2;
	for (size_t i = 0; i < 10; i++) {
		/*��u��Ϊ�����Դ*/
		cout << u2(e2) << " ";
	}
	cout << endl;
	/*���������С���ֵ*/
	cout << "min: " << e2.min() << " max: " << e2.max() << endl;

	/*��ȷ��дʹ��������Ĵ��룬����ÿ�η�����ͬ��ֵ*/
	vector<unsigned> v1 = good_randVec();
	for_each(v1.cbegin(), v1.cend(), print);
	cout << endl;
	vector<unsigned> v2 = good_randVec();
	for_each(v2.cbegin(), v2.cend(), print);
	cout << endl;

	/*�������������������*/
	default_random_engine e3;
	default_random_engine e4(2147483646);
	default_random_engine e5;
	e5.seed(32767);
	default_random_engine e6(32767);
	for (size_t i = 0; i != 100; ++i) {
		if (e3() == e4()) {
			cout << "unseeded match at iteration: " << i << endl;
		}
		if (e5() != e6()) {
			cout << "seeded differs at iteration: " << i << endl;
		}
	}

	/*�������ʵ��*/
	default_random_engine e7;
	uniform_real_distribution<double> u7(0, 1);
	for (size_t i = 0; i < 10; ++i) {
		cout << u7(e7) << " ";
	}
	cout << endl;
	/*Ĭ��double*/
	uniform_real_distribution<> u8(0, 1);

	/*���ɷǾ��ȷֲ��������*/
	default_random_engine e8;
	normal_distribution<> n(4, 1.5);
	vector<unsigned> vals(9);
	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e8));
		if (v < vals.size()) {
			++vals[v];
		}
	}
	for (size_t j = 0; j != vals.size(); ++j) {
		cout << j << ": " << string(vals[j], '*') << endl;
	}

	/*��Ŭ���ֲ�*/
	string resp;
	default_random_engine e9;
	bernoulli_distribution b9;
	do {
		bool first = b9(e9);
		cout << (first ? "We go first" : "You get to go first") << endl;
		cout << ((play(first)) ? "sorry, you lost" : "congrats, you won") << endl;
	} while (cin >> resp&&resp[0] == 'y');
}