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
	void fishLeft(Console& g_Console, int i, int j);
};

