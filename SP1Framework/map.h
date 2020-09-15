#pragma once
#include "Framework\console.h"

class map
{
public:
	char map[75][560];
	void maparray(Console& g_Console);    // array for submarine
	void rendermap(Console& g_Console, int x, int y);    // render map
};

