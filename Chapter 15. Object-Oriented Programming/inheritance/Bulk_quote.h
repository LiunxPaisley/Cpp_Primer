#pragma once
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string&, double, size_t, double);
	virtual double net_price(size_t) const override;
	virtual Bulk_quote* clone() const & {
		return new Bulk_quote(*this);
	}
	virtual Bulk_quote* clone() && {
		return new Bulk_quote(std::move(*this));
	}
};