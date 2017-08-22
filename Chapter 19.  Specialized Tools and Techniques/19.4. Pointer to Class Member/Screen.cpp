#include "Screen.h"

Screen::Action Screen::Menu[] =
{
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};

Screen & Screen::move(Directions cm)
{
	// TODO: 在此处插入 return 语句
	return (this->*Menu[cm])();
}

