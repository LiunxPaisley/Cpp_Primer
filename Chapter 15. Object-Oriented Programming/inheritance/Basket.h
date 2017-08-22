#pragma once
#include <memory>
#include <iostream>
#include <set>

#include "Quote.h"

using namespace std;

class Basket {
public:
	void add_item(const shared_ptr<Quote>& sale) {
		items.insert(sale);
	}
	void add_item(const Quote& sale);
	void add_item(Quote&& sale);
	
	double total_receipt(ostream&) const;
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	// 就地初始化不用小括号
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};