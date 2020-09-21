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

position player::getnextPos(int howmany)
{
	nextpos.setx(pos.getx());
	nextpos.sety(pos.gety());

	for (int i = 0; i < howmany; i++)
	{
		switch (dir)
		{
		case UP:
			nextpos.sety(nextpos.gety() - 1);
			break;
		case DOWN:
			nextpos.sety(nextpos.gety() + 1);
			break;
		case LEFT:
			nextpos.setx(nextpos.getx() - 2);
			break;
		case RIGHT:
			nextpos.setx(nextpos.getx() + 2);
			break;
		case NOT:
			break;
		}
	}

	return nextpos;
}