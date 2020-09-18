#pragma once
#include "Framework\console.h"

class map
{
public:
	char map[75][560];
	void maparray(Console& g_Console);    // array for submarine
	void rendermap(Console& g_Console, int x, int y, int light);    // render map
	void ghostposition(int x, int y);      //ghost array map thing
	void deleteghostposition(int x, int y);          //delete ghost array map thing
};