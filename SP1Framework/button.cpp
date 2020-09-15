#include "button.h"

button::button() : length(0), width(0), text(" ")
{

}

button::button(int l, int w, std::string what, int x, int y) : length(l), width(w), text(what)
{
	pos.setx(x);
	pos.sety(y);
	corner[0].setx(x - ((l - 1) / 2));
	corner[0].sety(y - ((w - 1) / 2));
	corner[1].setx(x + ((l - 1) / 2));
	corner[1].sety(y - ((w - 1) / 2));
	corner[2].setx(x - ((l - 1) / 2));
	corner[2].sety(y + ((w - 1) / 2));
	corner[3].setx(x + ((l - 1) / 2));
	corner[3].sety(y + ((w - 1) / 2));
}

int button::getLength()
{
	return length;
}

int button::getWidth()
{
	return width;
}

std::string button::getText()
{
	return text;
}

position button::getPos()
{
	return pos;
}

position button::getCorner(int index)
{
	return corner[index];
}