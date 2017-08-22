#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*pair*/
pair<string, int> process(vector<string> &v) {
	if (!v.empty()) {
		//return make_pair(v.back(),v.back().size());
		return { v.back(),v.back().size() };
	}
	else {
		return pair<string, int>();
	}
}

int main() {
	/*map*/
	map<string, size_t> word_count;
	set<string> exclude = { "the" };
	string word;
	while (cin >> word) {/*hey hey hey the boy next door*/
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}