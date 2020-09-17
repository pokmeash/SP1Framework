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
