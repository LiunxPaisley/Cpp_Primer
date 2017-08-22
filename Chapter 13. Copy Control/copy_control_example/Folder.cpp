#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder &f) :
	messages(f.messages) {
}

Folder & Folder::operator=(const Folder &rhs) {
	// TODO: 在此处插入 return 语句
	remove_Folder();
	messages = rhs.messages;
	add_Messages(rhs);
	return *this;
}

Folder::~Folder() {
	remove_Folder();
}

void Folder::addMsg(Message *m) {
	messages.insert(m);
}

void Folder::remMsg(Message *m) {
	messages.erase(m);
}

void Folder::add_Messages(const Folder &f) {
	for (auto m : f.messages) {
		m->save(*this);
	}
}

void Folder::remove_Folder() {
	for (auto m : messages) {
		m->remove(*this);
	}
}
