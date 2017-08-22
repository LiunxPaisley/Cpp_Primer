#pragma once
#include <string>
#include <set>

using namespace std;

class Folder {
	friend class Message;
	friend void swap(Message &lhs, Message &rhs);
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void addMsg(Message *);
	void remMsg(Message *);
private:
	set<Message*> messages;
	void add_Messages(const Folder &);
	void remove_Folder();
};