#include <iostream>
#include <vector>
#include <memory>

#include "Sales_data.h"
#include "HasPtr.h"
#include "NoCopy.h"
#include "HasPtr_.h"

using namespace std;

int main() {
	// Îö¹¹º¯Êý
	{
		Sales_data *p = new Sales_data();
		auto p2 = make_shared<Sales_data>();
		Sales_data item(*p);
		vector<Sales_data> vec;
		vec.push_back(*p2);
		cout << "Sales_data.bookNo: " << p->getBookNo() << endl;
		delete p;
	}
}


