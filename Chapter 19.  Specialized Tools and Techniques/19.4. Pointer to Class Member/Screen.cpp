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
	// TODO: �ڴ˴����� return ���
	return (this->*Menu[cm])();
}

