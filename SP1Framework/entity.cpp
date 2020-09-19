#include "entity.h"

entity::entity() : dir(NOT)
{

}

entity::entity(int x, int y) : dir(NOT)
{
	pos.setx(x);
	pos.sety(y);
}

position entity::getPos()
{
	return pos;
}

void entity::setDirection(int where)
{
	switch (where)
	{
	case 0:
		dir = NOT;
		break;
	case 1:
		dir = UP;
		break;
	case 2:
		dir = DOWN;
		break;
	case 3:
		dir = LEFT;
		break;
	case 4:
		dir = RIGHT;
		break;
	}
}

void entity::updatePos()
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
		pos.setx(pos.getx() - 1);
		break;
	case RIGHT:
		pos.setx(pos.getx() + 1);
		break;
	case NOT:
		break;
	}
}

position entity::getnextPos(int howmany)
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
			nextpos.setx(nextpos.getx() - 1);
			break;
		case RIGHT:
			nextpos.setx(nextpos.getx() + 1);
			break;
		case NOT:
			break;
		}
	}

	return nextpos;
}

void entity::oppDirection()
{
	switch (dir)
	{
	case UP:
		dir = DOWN;
		break;
	case DOWN:
		dir = UP;
		break;
	case LEFT:
		dir = RIGHT;
		break;
	case RIGHT:
		dir = LEFT;
		break;
	}
}


