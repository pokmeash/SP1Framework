#pragma once
#include "entity.h"
class player :
	public entity
{
private:
	float speed; //time before moving
public:
	player();
	void updatePos();
	void setSpeed(float spd);
	void setSpeed();
	float getSpeed();
	position getnextPos(int howmany);
};

