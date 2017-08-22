#include "BlobPtr.h"


template<typename T>
BlobPtr<T> & BlobPtr<T>::operator++()
{
	
}

template<typename T>
BlobPtr<T> & BlobPtr<T>::operator--()
{
	
}

template<typename T>
BlobPtr<T> & BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T> & BlobPtr<T>::operator--(int)
{
	
}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t, const string &) const
{

}
