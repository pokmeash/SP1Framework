#include "position.h"

position::position() : x(0), y(0)
{

}

int position::getx()
{
	return x;
}

int position::gety()
{
	return y;
}

void position::setx(int xx)
{
	x = xx;
}

void position::sety(int yy)
{
	y = yy;
}