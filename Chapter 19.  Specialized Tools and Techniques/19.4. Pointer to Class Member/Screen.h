#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "common.h"

class Screen
{
public:
	typedef std::string::size_type pos;
	
	char get_cursor() const { return contents[cursor]; }
	char get()const;
	char get(pos ht, pos wd) const;
	std::string contents;
	static const std::string Screen::* data()
	{
		return &Screen::contents;
	}

	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& up();
	Screen& down();
	using Action = Screen& (Screen::*)();
	enum Directions {HOME, FORWARD, BACK, UP, DOWN};
	Screen& move(Directions);
private:
	pos cursor;
	pos height, width;
	static Action Menu[];
};

#endif
