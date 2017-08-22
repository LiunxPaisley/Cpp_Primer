#ifndef _FILE_H_
#define _FILE_H_
typedef unsigned int Bit;

class File
{
	Bit mode : 2;
	Bit modified : 1;
	Bit prot_owner : 3;
	Bit prot_proup : 3;
	Bit prot_world : 3;
public:
	enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
	File& open(modes);
	void close();
	void write();
	bool isRead() const;
	void setWrite();
	File();
	//~File();
};

#endif