#include "hudstuff.h"

void hudstuff::LanternBase(Console& g_Console)
{
	COORD lantern;
    //lantern
    //top
    lantern.X = 8;
    lantern.Y = 20;
    g_Console.writeToBuffer(lantern, "_", 0x08);
    lantern.X = 5;
    lantern.Y = 21;
    g_Console.writeToBuffer(lantern, "__(_)__", 0x08);
    lantern.X = 4;
    lantern.Y = 22;
    g_Console.writeToBuffer(lantern, "/_______\\", 0x08);
    //left side
    for (int j = 23; j < 27; j++)
    {
        lantern.X = 4;
        lantern.Y = j;
        g_Console.writeToBuffer(lantern, "|", 0x08);
    }
    //right side
    for (int j = 23; j < 27; j++)
    {
        lantern.X = 12;
        lantern.Y = j;
        g_Console.writeToBuffer(lantern, "|", 0x08);
    }
    //bottom
    lantern.X = 4;
    lantern.Y = 27;
    g_Console.writeToBuffer(lantern, "|_______|", 0x08);
    lantern.Y = 28;
    g_Console.writeToBuffer(lantern, "\\_______/", 0x08);
}

void hudstuff::LanternDim(Console& g_Console)
{
    COORD candle;
    LanternBase(g_Console);
    candle.X = 8;
    candle.Y = 24;
    g_Console.writeToBuffer(candle, "_", 0x0F);
    //left candle
    for (int j = 25; j < 28; j++)
    {
        candle.X = 7;
        candle.Y = j;
        g_Console.writeToBuffer(candle, "|", 0x0F);
    }
    //right candle
    for (int j = 25; j < 28; j++)
    {
        candle.X = 9;
        candle.Y = j;
        g_Console.writeToBuffer(candle, "|", 0x0F);
    }
}

void hudstuff::LanternFull(Console& g_Console)
{
    COORD flame;
    LanternDim(g_Console);
    flame.X = 7;
    flame.Y = 24;
    g_Console.writeToBuffer(flame, "(_)", 0x1B);
    flame.X = 8;
    flame.Y = 23;
    g_Console.writeToBuffer(flame, "(", 0x1B);
}

void hudstuff::LanternHalf(Console& g_Console)
{
    COORD flame;
    LanternDim(g_Console);
    flame.X = 7;
    flame.Y = 25;
    g_Console.writeToBuffer(flame, "(_)", 0x1B);
    flame.X = 8;
    flame.Y = 24;
    g_Console.writeToBuffer(flame, ")", 0x1B);
}

void hudstuff::Minimap(Console& g_Console)
{
    int p;
    //map size 80 x 20
    //colour to save my life
    // walls - 0x8F
    // floor - 0x0F
    // 
    for (int j = 0; j < 80; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            g_Console.writeToBuffer(j, i, ' ', 0x7F);
        }
    }
    for (int i = 0; i < 20; i++)
    {
        g_Console.writeToBuffer(0, i, ' ', 0x8F);
        g_Console.writeToBuffer(79, i, ' ', 0x8F);
        g_Console.writeToBuffer(15, i, ' ', 0x8F);
        g_Console.writeToBuffer(65, i, ' ', 0x8F);
    }
    for (int j = 0; j < 80; j++)
    {
        g_Console.writeToBuffer(j, 0, ' ', 0x8F);
        g_Console.writeToBuffer(j, 19, ' ', 0x8F);
    }
    //Room A
    for (int j = 15; j < 35; j++)
    {
        g_Console.writeToBuffer(j, 7, ' ', 0x8F);
    }
    for (int i = 0; i < 5; i++)
    {
        g_Console.writeToBuffer(25, i, ' ', 0x8F);
    }
    for (int j = 25; j < 35; j++)
    {
        g_Console.writeToBuffer(j, 4, ' ', 0x8F);
    }
    for (int i = 5; i < 7; i++)
    {
        g_Console.writeToBuffer(34, i, ' ', 0x8F);
    }
    //Room B
    for (int j = 35; j < 65; j++)
    {
        g_Console.writeToBuffer(j, 6, ' ', 0x8F);
    }
    //Room I
    p = 17;
    for (int j = 27; j < 65; (j = j + 4))
    {
        if (p > 6)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p--;
        }
    }
    p = 17;
    for (int j = 28; j < 65; (j = j + 4))
    {
        if (p > 6)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p--;
        }
    }
    p = 17;
    for (int j = 29; j < 65; (j = j + 4))
    {
        if (p > 6)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p--;
        }
    }
    p = 17;
    for (int j = 30; j < 65; (j = j + 4))
    {
        if (p > 6)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p--;
        }
    }
    //Wall for Wall E and Wall D
    p = 13;
    for (int j = 46; j < 65; (j = j + 3))
    {
        if (p < 20)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p++;
        }
    }
    p = 13;
    for (int j = 47; j < 65; (j = j + 3))
    {
        if (p < 20)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p++;
        }
    }
    p = 13;
    for (int j = 48; j < 65; (j = j + 3))
    {
        if (p < 20)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p++;
        }
    }
    //Room H
    p = 14;
    for (int j = 27; j < 34; j++)
    {
        if (p > 7)
        {
            g_Console.writeToBuffer(j, p, ' ', 0x8F);
            p--;
        }
    }
    //Room G
    for (int j = 15; j < 27; j++)
    {
        g_Console.writeToBuffer(j, 14, ' ', 0x8F);
    }
    for (int i = 14; i < 20; i++)
    {
        g_Console.writeToBuffer(27, i, ' ', 0x8F);
    }
    //DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOORS
    g_Console.writeToBuffer(30, 4, ' ', 0x7F);
    g_Console.writeToBuffer(15, 4, ' ', 0x7F);
    g_Console.writeToBuffer(15, 17, ' ', 0x7F);
    g_Console.writeToBuffer(22, 14, ' ', 0x7F);
    g_Console.writeToBuffer(31, 10, ' ', 0x7F);
    g_Console.writeToBuffer(51, 6, ' ', 0x7F);
    for (int j = 35; j < 39; j++)
    {
        g_Console.writeToBuffer(j, 15, ' ', 0x7F);
    }
    for (int j = 55; j < 59; j++)
    {
        g_Console.writeToBuffer(j, 16, ' ', 0x7F);
    }
    g_Console.writeToBuffer(65, 13, ' ', 0x7F);
}
