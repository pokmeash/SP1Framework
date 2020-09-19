#pragma once
#include "Framework\console.h"

class minigame
{
public:
	char miniGrid[80][20];
	//pressure minigame
	void initialiseMap(Console& g_Console);
	void vertLine(Console& g_Console, int i, int j, int k);
	void horiLine(Console& g_Console, int i, int j, int k);
	void pressureBorder(Console& g_Console);
	void pressureMap(Console& g_Console);
	void pressureDoors(Console& g_Console, int i, int j);
	void pressureWin(Console& g_Console, int i, int j);
	void fishLeft(Console& g_Console, int i, int j, CHAR colour);
	void seaVoid(Console& g_Console, int j);

	//countdown
	void countdown1(Console& g_Console);
	void countdown2(Console& g_Console);
	void countdown3(Console& g_Console);
	void countdown4(Console& g_Console);
	void countdown5(Console& g_Console);

	//left side
	void attack(Console& g_Console, int x);

	//right side
};

