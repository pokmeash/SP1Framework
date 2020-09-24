#pragma once
#include "Framework\console.h"
#include "minigame.h"

class map
{
public:
	char map[75][560];
	void maparray(Console& g_Console);    // array for submarine
	void rendermap(Console& g_Console, int x, int y, int light);    // render map
	void ghostposition(int x, int y);      //ghost array map thing
	void deleteghostposition(int x, int y);          //delete ghost array map thing
	void roomA1();
	void roomA2();
	void roomA3();
	void roomB1();
	void roomB2();
	void roomB3();
	void roomD1();
	void roomD2();
	void roomD3();
	void roomE1();
	void roomE2();
	void roomE3();
	void roomG1();
	void roomG2();
	void roomG3();
	void roomH1();
	void roomH2();
	void roomH3();
	void fish(int xLoc, int yLoc, int dir);
	void toilet(int xLoc, int yLoc, int dir);
	void roomI1();
};

