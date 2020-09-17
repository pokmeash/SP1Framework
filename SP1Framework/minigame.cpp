#include "minigame.h"

void minigame::initialiseMap(Console& g_Console)
{
	COORD c;
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x7F);
		}
	}
}
void minigame::vertLine(Console& g_Console, int i, int j, int k)
{
	COORD c;
	for (int line = i; line < j; line++)
	{
		c.X = k;
		c.Y = line;
		g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x8F);
	}
}
void minigame::horiLine(Console& g_Console, int i, int j, int k)
{
	COORD c;
	for (int line = i; line < j; line++)
	{
		c.X = line;
		c.Y = k;
		g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x8F);
	}
}
void minigame::pressureBorder(Console& g_Console)
{
	COORD c;
	initialiseMap(g_Console);
	for (int i = 20; i < 60; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x1A);
		}
	}
	//Border
	horiLine(g_Console, 20, 60, 0);
	horiLine(g_Console, 20, 60, 19);
	vertLine(g_Console, 0, 20, 20);
	vertLine(g_Console, 0, 20, 59);
}
void minigame::pressureMap(Console& g_Console)
{
	COORD c;
	pressureBorder(g_Console);
	//maze lines
	for (int i = 21; i < 59; i++)
	{
		for (int j = 2; j < 18; (j = j + 2))
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '-', 0x1B);
		}
	}
}
void minigame::pressureDoors(Console& g_Console, int i, int j)
{
	//range for pressure doors is 21 to 54
	COORD c;
	for (int door = i; door < (i + 3); door++)
	{
		c.X = door;
		c.Y = j;
		g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x1B);
	}
}

void minigame::pressureWin(Console& g_Console, int i, int j)
{
	//range for pressure doors is 21 to 54
	COORD c;
	for (int door = i; door < (i + 3); door++)
	{
		c.X = door;
		c.Y = j;
		g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '@', 0x1B);
	}
}
