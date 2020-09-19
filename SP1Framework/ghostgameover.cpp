#include "ghostgameover.h"

void ghostgameover::initGridGhost(Console& g_Console)
{
	COORD c;
	for (j = 0; j < 31; j++)
	{
		for (i = 0; i < 80; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x8F);
		}
	}
}

void ghostgameover::GhostHair(Console& g_Console)
{
	COORD c;
	//hair
	for (int k = 31; k < 48; k++)
	{
		c.X = k;
		c.Y = 5;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}
	for (int k = 29; k < 50; k++)
	{
		c.X = k;
		c.Y = 6;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}

	for (int k = 26; k < 53; k++)
	{
		c.X = k;
		c.Y = 7;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}

	for (int k = 23; k < 56; k++)
	{
		for (int h = 9; h > 7; h--)
		{
			c.X = k;
			c.Y = h;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
		}
	}

	for (int k = 21; k < 58; k++)
	{
		for (int h = 25; h > 9; h--)
		{
			c.X = k;
			c.Y = h;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
		}
	}

	for (int k = 23; k < 56; k++)
	{
		for (int h = 27; h > 25; h--)
		{
			c.X = k;
			c.Y = h;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
		}
	}

	for (int k = 25; k < 54; k++)
	{
		for (int h = 29; h > 27; h--)
		{
			c.X = k;
			c.Y = h;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
		}
	}
}
void ghostgameover::GhostSprite1(Console& g_Console)
{
	COORD c;
	//body
	for (int k = 20; k < 55; k++)
	{
		for (int h = 29; h > 19; h--)
		{
			c.X = k;
			c.Y = h;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
		}
	}
	for (int h = 29; h > 21; h--)
	{
		c.X = 19;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int h = 29; h > 24; h--)
	{
		c.X = 18;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}
	GhostHair(g_Console);
}
void ghostgameover::GhostSprite2(Console& g_Console)
{
	COORD c;
	//right shoulder
	c.X = 55;
	c.Y = 29;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
}
void ghostgameover::GhostSprite3(Console& g_Console)
{
	//right shoulder
	COORD c;
	for (int h = 29; h > 27; h--)
	{
		c.X = 55;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int h = 29; h > 28; h--)
	{
		c.X = 56;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}
}
void ghostgameover::GhostSprite4(Console& g_Console)
{
	COORD c;
	//left shoulder
	c.X = 19;
	c.Y = 22;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 20;
	c.Y = 20;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	//right shoulder
	for (int h = 29; h > 25; h--)
	{
		c.X = 56;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int h = 29; h > 27; h--)
	{
		c.X = 57;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	c.X = 58;
	c.Y = 29;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
}
void ghostgameover::GhostSprite5(Console& g_Console)
{
	COORD c;
	//left shoulder
	c.X = 18;
	c.Y = 25;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 19;
	c.Y = 23;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 20;
	c.Y = 21;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	//right shoulder
	for (int h = 29; h > 25; h--)
	{
		c.X = 57;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int h = 29; h > 27; h--)
	{
		c.X = 58;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	c.X = 59;
	c.Y = 29;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
}
void ghostgameover::GhostSprite6(Console& g_Console)
{
	COORD c;
	//left shoulder
	c.X = 18;
	c.Y = 26;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 19;
	c.Y = 24;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 20;
	c.Y = 22;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	//right shoulder
	for (int h = 29; h > 23; h--)
	{
		c.X = 58;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int h = 29; h > 25; h--)
	{
		c.X = 59;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	c.X = 60;
	c.Y = 29;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
}
void ghostgameover::GhostSprite7(Console& g_Console)
{
	COORD c;
	//left shoulder
	c.X = 18;
	c.Y = 27;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 19;
	c.Y = 25;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	c.X = 20;
	c.Y = 23;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);

	//right shoulder
	for (int h = 29; h > 23; h--)
	{
		c.X = 58;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int h = 29; h > 25; h--)
	{
		c.X = 59;
		c.Y = h;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	c.X = 60;
	c.Y = 28;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
}
void ghostgameover::GhostSprite8(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 16;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
}
void ghostgameover::GhostSprite9(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 15;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	for (int k = 36; k < 38; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
}
void ghostgameover::GhostSprite10(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	for (int k = 36; k < 38; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 35; k < 41; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair
	c.X = 22;
	c.Y = 28;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 58;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite11(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 13;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	for (int k = 36; k < 38; k++)
	{
		c.X = k;
		c.Y = 14;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 35; k < 41; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 33; k < 45; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 36; k < 42; k++)
	{
		c.X = k;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 37; k < 41; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair
	c.X = 23;
	c.Y = 29;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 59;
	c.Y = 14;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 20;
	c.Y = 16;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite12(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	for (int k = 36; k < 38; k++)
	{
		c.X = k;
		c.Y = 13;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 35; k < 41; k++)
	{
		c.X = k;
		c.Y = 14;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 33; k < 45; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 32; k < 48; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair disbanding

	for (int k = 34; k < 45; k++)
	{
		c.X = k;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 35; k < 44; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 36; k < 42; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair
	c.X = 60;
	c.Y = 15;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 19;
	c.Y = 17;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite13(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 11;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	for (int k = 36; k < 38; k++)
	{
		c.X = k;
		c.Y = 12;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 35; k < 41; k++)
	{
		c.X = k;
		c.Y = 13;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 33; k < 45; k++)
	{
		c.X = k;
		c.Y = 14;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 32; k < 48; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 30; k < 50; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair disbanding

	for (int k = 32; k < 48; k++)
	{
		c.X = k;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 34; k < 47; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 35; k < 45; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 34; k < 43; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair
	c.X = 60;
	c.Y = 16;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 20;
	c.Y = 18;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite14(Console& g_Console)
{
	COORD c;
	c.X = 36;
	c.Y = 10;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	for (int k = 36; k < 38; k++)
	{
		c.X = k;
		c.Y = 11;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 35; k < 41; k++)
	{
		c.X = k;
		c.Y = 12;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 33; k < 45; k++)
	{
		c.X = k;
		c.Y = 13;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 32; k < 48; k++)
	{
		c.X = k;
		c.Y = 14;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 30; k < 50; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 28; k < 52; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair disbanding

	for (int k = 30; k < 50; k++)
	{
		c.X = k;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 31; k < 49; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 31; k < 48; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}


	for (int k = 33; k < 46; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 34; k < 45; k++)
	{
		c.X = k;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//hair
	c.X = 59;
	c.Y = 17;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite15(Console& g_Console)
{
	COORD c;
	for (int k = 28; k < 52; k++)
	{
		for (j = 16; j < 18; j++)
		{
			c.X = k;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
		}
	}

	//hair disbanding
	for (int k = 30; k < 50; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 31; k < 49; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 31; k < 48; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}


	for (int k = 33; k < 46; k++)
	{
		c.X = k;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//Shirt
	for (int k = 34; k < 45; k++)
	{
		c.X = k;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int k = 38; k < 42; k++)
	{
		c.X = k;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 36; k < 44; k++)
	{
		c.X = k;
		c.Y = 23;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//hair
	c.X = 58;
	c.Y = 18;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite16(Console& g_Console)
{
	COORD c;
	for (int k = 28; k < 52; k++)
	{
		for (j = 16; j < 19; j++)
		{
			c.X = k;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
		}
	}

	//hair disbanding
	for (int k = 30; k < 50; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 31; k < 49; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 31; k < 48; k++)
	{
		c.X = k;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//Shirt
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int k = 38; k < 42; k++)
	{
		c.X = k;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 34; k < 46; k++)
	{
		c.X = k;
		c.Y = 23;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}
	for (int k = 35; k < 44; k++)
	{
		c.X = k;
		c.Y = 24;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//hair
	c.X = 56;
	c.Y = 27;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite17(Console& g_Console)
{
	COORD c;
	for (int k = 28; k < 52; k++)
	{
		for (j = 16; j < 20; j++)
		{
			c.X = k;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
		}
	}

	//hair disbanding
	for (int k = 30; k < 50; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}
	for (int k = 31; k < 49; k++)
	{
		c.X = k;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	//Shirt
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int k = 38; k < 42; k++)
	{
		c.X = k;
		c.Y = 22;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x7F);
	}

	for (int k = 34; k < 46; k++)
	{
		c.X = k;
		c.Y = 23;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 24;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int k = 34; k < 45; k++)
	{
		c.X = k;
		c.Y = 25;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//hair
	c.X = 58;
	c.Y = 20;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 57;
	c.Y = 28;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite18(Console& g_Console)
{
	COORD c;
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 25;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	for (int k = 34; k < 46; k++)
	{
		c.X = k;
		c.Y = 26;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//hair
	c.X = 59;
	c.Y = 21;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);

	c.X = 56;
	c.Y = 29;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite19(Console& g_Console)
{
	COORD c;
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 27;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//hair
	c.X = 59;
	c.Y = 22;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite20(Console& g_Console)
{
	COORD c;
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 28;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//hair
	c.X = 58;
	c.Y = 23;
	g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
}
void ghostgameover::GhostSprite21(Console& g_Console)
{
	COORD c;
	for (int k = 33; k < 47; k++)
	{
		c.X = k;
		c.Y = 29;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0xFF);
	}

	//eyes
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);
	}

	//mouth
	for (int k = 38; k < 42; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x8F);
	}
}
void ghostgameover::GhostSprite22(Console& g_Console)
{
	COORD c;
	//eyes
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 17;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}
}
void ghostgameover::GhostSprite23(Console& g_Console)
{
	COORD c;
	//eyes
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 16;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}
}
void ghostgameover::GhostSprite24(Console& g_Console)
{
	COORD c;
	//eyes
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 15;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x0F);
	}
}
void ghostgameover::GhostSprite25(Console& g_Console)
{
	COORD c;
	//tears
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 18;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}
}
void ghostgameover::GhostSprite26(Console& g_Console)
{
	COORD c;
	//tears
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 19;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}
}
void ghostgameover::GhostSprite27(Console& g_Console)
{
	COORD c;
	//tears
	for (int k = 30; k < 36; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}

	for (int k = 44; k < 50; k++)
	{
		c.X = k;
		c.Y = 20;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}
}
void ghostgameover::GhostSprite28(Console& g_Console)
{
	COORD c;
	//tears
	for (int k = 31; k < 36; k++)
	{
		c.X = k;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}

	for (int k = 44; k < 49; k++)
	{
		c.X = k;
		c.Y = 21;
		g_Console.writeToBuffer(c, Grid[c.X][c.Y] = ' ', 0x4F);
	}
}
void ghostgameover::GhostSprite29(Console& g_Console)
{
	COORD c;
	for (j = 0; j < 31; j++)
	{
		for (i = 0; i < 80; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x94F);
		}
	}
}
void ghostgameover::GhostSprite30(Console& g_Console)
{
	COORD c;
	//face
	for (j = 0; j < 31; j++)
	{
		for (i = 0; i < 80; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x7F);
		}
	}
	//eyes
	for (j = 6; j < 19; j++)
	{
		for (i = 7; i < 29; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0F);
		}
	}
	for (j = 6; j < 19; j++)
	{
		for (i = 51; i < 73; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x0F);
		}
	}

	//pupils
	c.X = 17;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0xFF);
	c.X = 18;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0xFF);

	c.X = 61;
	c.Y = 12;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0xFF);
	c.X = 62;
	g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0xFF);

	//tears
	for (j = 19; j < 30; j++)
	{
		for (i = 7; i < 29; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x4F);
		}
	}
	for (j = 19; j < 30; j++)
	{
		for (i = 51; i < 73; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x4F);
		}
	}

	//mouth
	for (j = 22; j < 29; j++)
	{
		for (i = 31; i < 49; i++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, Grid[c.Y][c.X] = ' ', 0x4F);
		}
	}
}

void ghostgameover::miniGhost1(Console& g_Console, int x)
{
	COORD c;
	//body
	for (int i = (x - 3); i < (x + 13); i++)
	{
		for (int j = 12; j < 20; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0xFF);
		}
	}

	for (int j = 13; j < 20; j++)
	{
		c.X = x - 4;
		c.Y = j;
		g_Console.writeToBuffer(c, ' ', 0xFF);
	}
	for (int j = 13; j < 20; j++)
	{
		c.X = x + 13;
		c.Y = j;
		g_Console.writeToBuffer(c, ' ', 0xFF);
	}
	for (int j = 14; j < 20; j++)
	{
		c.X = x - 5;
		c.Y = j;
		g_Console.writeToBuffer(c, ' ', 0xFF);
	}
	for (int j = 14; j < 20; j++)
	{
		c.X = x + 14;
		c.Y = j;
		g_Console.writeToBuffer(c, ' ', 0xFF);
	}
	//hair
	for (int i = x; i < (x + 10); i++)
	{
		c.X = i;
		c.Y = 4;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
	for (int i = (x - 1); i < (x + 11); i++)
	{
		c.X = i;
		c.Y = 5;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
	for (int i = (x - 2); i < (x + 12); i++)
	{
		for (int j = 6; j < 15; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}
	for (int i = (x - 1); i < (x + 11); i++)
	{
		c.X = i;
		c.Y = 15;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
	for (int i = x; i < (x + 10); i++)
	{
		c.X = i;
		c.Y = 16;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
	for (int i = (x + 1); i < (x + 9); i++)
	{
		c.X = i;
		c.Y = 17;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
}

void ghostgameover::miniGhost2(Console& g_Console)
{
	COORD c;

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x44);
		}
	}

	//left eye
	for (int i = 23; i < 32; i++)
	{
		for (int j = 5; j < 11; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}

	for (int i = 14; i < 23; i++)
	{
		for (int j = 7; j < 13; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}

	//right eye
	for (int i = 48; i < 57; i++)
	{
		for (int j = 8; j < 14; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}

	for (int i = 57; i < 66; i++)
	{
		for (int j = 10; j < 16; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}
	
	//mouth
	for (int i = 18; i < 48; i++)
	{
		c.X = i;
		c.Y = 16;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}

	for (int i = 14; i < 57; i++)
	{
		c.X = i;
		c.Y = 17;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}

	for (int i = 10; i < 66; i++)
	{
		for (int j = 18; j < 25; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0x00);
		}
	}
	for (int i = 16; i < 61; i++)
	{
		c.X = i;
		c.Y = 25;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}
	for (int i = 19; i < 54; i++)
	{
		c.X = i;
		c.Y = 26;
		g_Console.writeToBuffer(c, ' ', 0x00);
	}

	//pupils
	for (int i = 22; i < 26; i++)
	{
		for (int j = 8; j < 10; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0xCC);
		}
	}

	for (int i = 54; i < 58; i++)
	{
		for (int j = 11; j < 13; j++)
		{
			c.X = i;
			c.Y = j;
			g_Console.writeToBuffer(c, ' ', 0xCC);
		}
	}
}
