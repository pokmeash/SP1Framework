#include "map.h"

void map::maparray(Console& g_Console)
{

    //array to detect things
    for (int x = 0; x < 560; ++x)
    {
        for (int y = 0; y < 75; ++y)
        {
            map[y][x] = ' ';
        }
    }
    //walls in 4 sides
    for (int i = 0; i < 560; i++)
    {
        map[0][i] = '+';
        map[74][i] = '+';
    }
    for (int j = 0; j < 75; j++)
    {
        map[j][0] = '+';
        map[j][559] = '+';
    }
    map[12][40] = '+';
}

void map::rendermap(Console& g_Console, int x, int y)
{
    for (int a = -10; a < 10; a++)
    {
        for (int b = -40; b < 40; b++)
        {
            if (y + a < 75 && y + a > -1)
            {
                if (x + b < 560 && x + b > -1)
                {
                    if (map[y + a][x + b] == '+')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, "+", 0);
                    }
                }
            }
        }
    }  
}