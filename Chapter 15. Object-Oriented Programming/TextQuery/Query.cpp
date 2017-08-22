#include "Query.h"

ostream& operator<<(ostream& os, const Query& query) {
	return os << query.rep();
}

Query operator~(const Query &) {
	return Query();
}

Query operator|(const Query&, const Query&) {

}

