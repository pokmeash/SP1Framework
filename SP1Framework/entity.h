#pragma once
#include "position.h"

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NOT
};

class entity
{
private:
	position pos;
	position nextpos;
	direction dir;
	direction dirx;
	direction diry;

public:
	entity();
	entity(int x, int y);
	position getPos();
	position getnextPos(int howmany);
	int getDirX();
	int getDirY();
	void updatePos();
	void setDirection(int where);
	void setDirX(int where);
	void setDirY(int where);
	void setPos(int x, int y);
	void oppDirection();
	void changeAxis();

};

