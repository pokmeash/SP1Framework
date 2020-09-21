#pragma once
#include "entity.h"
class player :
	public entity
{
public:
	void updatePos();
	position getnextPos(int howmany);
};

