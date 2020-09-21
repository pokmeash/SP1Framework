#include "player.h"

void player::updatePos()
{
	switch (dir)
	{
	case UP:
		pos.sety(pos.gety() - 1);
		break;
	case DOWN:
		pos.sety(pos.gety() + 1);
		break;
	case LEFT:
		pos.setx(pos.getx() - 2);
		break;
	case RIGHT:
		pos.setx(pos.getx() + 2);
		break;
	case NOT:
		break;
	}
}
