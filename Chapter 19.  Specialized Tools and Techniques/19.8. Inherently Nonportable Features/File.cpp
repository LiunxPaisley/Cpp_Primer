#include "File.h"

File & File::open(modes m)
{
	// TODO: 在此处插入 return 语句
	mode |= READ;
	if (m & WRITE)
	{

	}
	return *this;
}

void File::close()
{
	if (modified)
	{
		// ...
	}
		
}

void File::write()
{
	modified = 1;
	// ...
}

inline bool File::isRead() const
{
	return mode & READ;
}

void File::setWrite()
{
	mode |= WRITE;
}

File::File()
{
}


//File::~File()
//{
//}
