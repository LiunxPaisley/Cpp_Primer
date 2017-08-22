#pragma once
#include <string>

#include "Quote.h"

using namespace std;

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc)
		: Quote(book, price), quantity(qty), discount(disc) {
	}
	virtual double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};