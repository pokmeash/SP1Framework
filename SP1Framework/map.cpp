#include "map.h"

void map::maparray(Console& g_Console)
{

    //array to detect things
    for (int x = 0; x < 560; ++x)
    {
        for (int y = 0; y < 75; ++y)
        {
            g_Console.writeToBuffer(x,y, map[y][x] = ' ', 0x0C);
        }
    }
    //walls in 4 sides
    for (int i = 0; i < 560; i++)
    {
        g_Console.writeToBuffer(i,0, map[0][i] = '+', 0x0C);
        g_Console.writeToBuffer(i,74, map[74][i] = '+', 0x0C);
    }
    for (int j = 0; j < 75; j++)
    {
        g_Console.writeToBuffer(0, j, map[j][0] = '+', 0x0C);
        g_Console.writeToBuffer(559, j, map[j][559] = '+', 0x0C);   
    }


}