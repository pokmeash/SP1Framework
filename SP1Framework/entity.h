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

public:
	entity();
	entity(int x, int y);
	position getPos();
	position getnextPos(int howmany);
	void updatePos();
	void setDirection(int where);

};

