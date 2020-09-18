#pragma once
#include "Framework\console.h"

class map
{
public:
	char map[75][560];
	void maparray(Console& g_Console);    // array for submarine
	void rendermap(Console& g_Console, int x, int y);    // render map
	void ghostposition(int x, int y);      //ghost array map thing
	void deleteghostposition(int x, int y);          //delete ghost array map thing

	void renderFullLantern(Console& g_Console, int x, int y);    // render lantern light (full)
	void renderHalfLantern(Console& g_Console, int x, int y);    // render lantern light (half)
	void renderDimLantern(Console& g_Console, int x, int y);    // render lantern light (dim)
	

};

