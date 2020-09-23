#include "player.h"
player::player() : speed(0)
{

}

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
		pos.setx(pos.getx() - 1);
		break;
	case RIGHT:
		pos.setx(pos.getx() + 1);
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

void player::setSpeed(float spd)
{
	speed = spd;
}

float player::getSpeed()
{
	return speed;
}

void player::setSpeed()
{
	switch (dir)
	{
	case 1:
	case 2:
		speed = 0.08;
		break;
	case 3:
	case 4:
		speed = 0.04;
		break;
	}
}