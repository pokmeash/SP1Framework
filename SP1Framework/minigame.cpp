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
	//Border
	horiLine(g_Console, 20, 60, 0);
	horiLine(g_Console, 20, 60, 19);
	vertLine(g_Console, 0, 20, 20);
	vertLine(g_Console, 0, 20, 59);
}
void minigame::pressureMap(Console& g_Console)
{
	COORD c;
	//bg of game
	for (int i = 20; i < 60; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x1A);
		}
	}
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

void minigame::fishLeft(Console& g_Console, int i, int j, CHAR colour)
{
	COORD c;
	c.X = i;
	c.Y = j;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '>', colour);
	c.X = i + 1;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '<', colour);
	c.X = i + 2;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '>', colour);
	c.X = i - 1;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', colour);
	c.X = i - 2;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', colour);
}

void minigame::seaVoid(Console& g_Console, int j)
{
	COORD c;
	for (int i = 21; i < 59; i++)
	{
		c.X = i;
		c.Y = j;
		g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = 'x', 0x0F);
	}
}

void minigame::countdown1(Console& g_Console)
{
	COORD c;
	c.X = 39;
	c.Y = 9;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '3', 0x1C);
}

void minigame::countdown2(Console& g_Console)
{
	COORD c;
	c.X = 39;
	c.Y = 9;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '2', 0x1C);
}

void minigame::countdown3(Console& g_Console)
{
	COORD c;
	c.X = 39;
	c.Y = 9;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '1', 0x1C);
}

void minigame::countdown4(Console& g_Console)
{
	COORD c;
	c.X = 38;
	c.Y = 9;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = 'Go!', 0x1C);
}

void minigame::countdown5(Console& g_Console)
{
	COORD c;
	c.X = 38;
	c.Y = 9;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '   ', 0x1C);
}

void minigame::attack(Console& g_Console, int x)
{
	COORD c;
	for (int i = x; i < (x + 20); i++)
	{
		for (int j = 0; j < 20; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '/', 0xCC);
		}
	}
}

void minigame::smile(Console& g_Console, int x, int y, int k)
{
	COORD c;
	c.X = x + k;
	c.Y = y;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0x88);
}

void minigame::eyes(Console& g_Console, int x, int y, int k)
{
	COORD c;
	c.X = x + k;
	c.Y = y;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0x88);
	c.Y = y + 4;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0x88);
}

void minigame::tears(Console& g_Console, int x, int y, int k)
{
	COORD c;
	c.X = x + k;
	c.Y = y;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0xFF);
	c.X = x + 1 + k;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0xFF);
	c.X = x + 7 + k;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0xFF);
	c.X = x + 8 + k;
	g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = '_', 0xFF);
}

void minigame::clearWarning(Console& g_Console, int x, int y, int k)
{
	COORD c;
	for (int i = x; i < (x + 15); i++)
	{
		for (int j = y; j < (y + 5); j++)
		{
			c.X = i + k;
			c.Y = j;
			g_Console.writeToBuffer(c, miniGrid[c.X][c.Y] = ' ', 0x77);
		}
	}
}