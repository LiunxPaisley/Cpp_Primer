#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool valid(const smatch& m) {
	if (m[1].matched) {
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

int main() {
	/*regex使用*/
	cout << "regex使用 : ";
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r1(pattern);
	smatch results;
	string test_str = "receipt freind theif receive";
	if (regex_search(test_str, results, r1)) {
		cout << results.str();
	}

	/*忽略大小写*/
	cout << "\n忽略大小写 : ";
	regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	smatch results_;
	string filename = "regular_expression.cpp";
	if (regex_search(filename, results, r2))
		cout << results.str();

	/*指出正则表达式的错误*/
	cout << "\n指出正则表达式的错误 : ";
	try {
		regex r3("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}

	/*char*匹配*/
	cout << "char*匹配 : ";
	cmatch cresults;
	if (regex_search("myfile.cc", cresults, r2))
		cout << results.str();

	/*使用sregex_iterator*/
	cout << "\n使用sregex_iterator : ";
	string file = "receipt freind theif receive";
	regex r4(pattern, regex::icase);
	for (sregex_iterator it(file.begin(), file.end(), r4), end_it;
		it != end_it; ++it) {
		cout << it->str() << " ";
	}
	cout << "\n使用匹配数据 : " << endl;
	for (sregex_iterator it(file.begin(), file.end(), r4), end_it;
		it != end_it; ++it) {
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		cout << it->prefix().str().substr(pos)
			<< "\n\t\t>>> " << it->str() << " <<<\n"
			<< it->suffix().str().substr(0, 40)
			<< endl;
	}
	/*使用子表达式*/
	cout << "使用子表达式: ";
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	while (getline(cin, s)) {
		cout << s << endl;
		for (sregex_iterator it(s.begin(), s.end(), r), end_it;
			it != end_it; ++it) {
			if (valid(*it)) {
				cout << "valid: " << it->str() << endl;
			}
			else {
				cout << "not valid: " << it->str() << endl;
			}
		}
	}
	/*使用regex_replace*/
	cout << "使用regex_replace: ";
	string fmt = "$2.$5.$7";
	string number = "(908) 555-1800";
	cout << regex_replace(number, r, fmt) << endl;

	/*用来控制匹配和格式的标志*/
	string fmt2 = "$2.$5.$7 ";
	using namespace std::regex_constants;
	cout << regex_replace(s, r, fmt2, format_no_copy) << endl;
}