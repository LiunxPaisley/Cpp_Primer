#include "Blob.h"

template<typename T>
Blob<T>::Blob(initializer_list<T> il) try :
	data(std::make_shared<std::vector<T>>(il))
{
	/*¿Õº¯ÊýÌå*/
}
catch (const std::bad_alloc &e)
{
	handle_out_of_memory(e);
}