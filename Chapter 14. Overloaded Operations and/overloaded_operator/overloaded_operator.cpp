#include <vector>
#include <utility>
#include "Sales_data.h"
#include "StrVec.h"

using namespace std;

class PrintString {
public:
	PrintString(ostream& o = cout, char c = ' ')
		: os(o), sep(c){}
	void operator()(const string& s) const {
		os << s << sep;
	}
private:
	ostream& os;
	char sep;
};

int main() {
	string s = "fuck";
	PrintString printer;
	printer(s);
	PrintString errors(cerr, '\n');
	errors(s);
}