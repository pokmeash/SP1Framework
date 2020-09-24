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
	direction dirx;
	direction diry;
protected:
	direction dir;
	position pos;
	position nextpos;
public:
	entity();
	entity(int x, int y);
	position getPos();
	position getnextPos(int howmany);
	int getDirX();
	int getDirY();
	virtual void updatePos();
	void setDirection(int where);
	void setDirX(int where);
	void setDirY(int where);
	void setPos(int x, int y);
	void oppDirection();
	void changeAxis();

};

