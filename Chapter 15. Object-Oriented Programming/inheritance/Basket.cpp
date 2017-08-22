#include "Basket.h"

void Basket::add_item(const Quote & sale) {
	items.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote && sale) {
	items.insert(shared_ptr<Quote>(std::move(sale.clone())));
}

double Basket::total_receipt(ostream &os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin();
		iter != items.cend();
		iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}
