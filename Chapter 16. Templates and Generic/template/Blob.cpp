#include "Blob.h"

template<typename T>
Blob<T>::Blob()
	: data(make_shared<vector<T>>()){
}

template<typename T>
Blob<T>::Blob(initializer_list<T> il)
	: data(make_shared<vector<T>>(il)){
}

template<typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
T & Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->data();
}

template<typename T>
T & Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::check(size_type i, const string & msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}