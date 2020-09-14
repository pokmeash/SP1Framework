#include "button.h"

button::button() : length(0), width(0), text(" ")
{

}

button::button(int l, int w, std::string what, int x, int y) : length(l), width(w), text(what)
{
	pos.setx(x);
	pos.sety(y);
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

void button::setPos()
{
	pos.setx(pos.getx() - (length / 2));
	pos.sety(pos.gety() - (width / 2));
}

position button::getPos()
{
	return pos;
}
