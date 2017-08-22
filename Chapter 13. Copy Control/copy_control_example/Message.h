#pragma once
#include <string>
#include <set>

using namespace std;

class Message 
{
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const string& str="="):
		contents(str) {}
	Message(const Message&);
	Message(Message &&m);
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message *m);
};