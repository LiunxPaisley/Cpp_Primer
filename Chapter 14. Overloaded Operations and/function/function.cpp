#include <iostream>
#include <string>
#include <functional>
#include <map>

using namespace std;

int add(int i, int j) {
	return i + j;
}

auto mod = [](int i, int j) { return i%j; };

struct divide {
	int operator()(int demoninator, int divisor) {
		return demoninator / divisor;
	}
};

int main() {
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = divide();
	function<int(int, int)> f3 = [](int i, int j) { return i*j; };

	map<string, function<int(int, int)> > binops = {
		{"+", add},
		{"-", std::minus<int>()},
		{"/", divide()},
		{"*", [](int i, int j) { return i*j; } },
		{"%", mod}
	};
	cout << "binops[\" + \"](10, 5) = " << binops["+"](10, 5) << endl;
	cout << "binops[\" - \"](10, 5) = " << binops["-"](10, 5) << endl;
	cout << "binops[\" / \"](10, 5) = " << binops["/"](10, 5) << endl;
	cout << "binops[\" * \"](10, 5) = " << binops["*"](10, 5) << endl;
	cout << "binops[\" % \"](10, 5) = " << binops["%"](10, 5) << endl;
}