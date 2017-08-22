#include <iostream>

#include "QueryResult.h"

using namespace std;

int main() {
	ifstream input("D:/Code/C++/dynamic_memory/text_query/input.txt");
	TextQuery tq(input);
	while (true) {
		cout << "enter a word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout,tq.query(s));
	}
}

