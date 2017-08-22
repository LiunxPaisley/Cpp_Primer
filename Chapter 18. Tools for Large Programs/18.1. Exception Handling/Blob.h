#ifndef _BLOB_H_
#define _BLOB_H_

#include <initializer_list>
#include <exception>

using std::initializer_list;

template<typename T>
class Blob
{
public:
	Blob(initializer_list<T> il);
};

#endif

