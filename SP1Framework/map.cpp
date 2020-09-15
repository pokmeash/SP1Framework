#include "map.h"

void map::maparray(Console& g_Console, int x , int y)
{

    //array to detect things
    for (int x = 0; x < 560; ++x)
    {
        for (int y = 0; y < 75; ++y)
        {
            g_Console.writeToBuffer(x,y, map[y][x] = ' ', 0x8F);
        }
    }
    //walls in 4 sides
    for (int i = 0; i < 560; i++)
    {
        if (y < 10)
        {
            g_Console.writeToBuffer(i, y - 10, map[0][i] = '+', 0x0C);
        }
        else
        {
            g_Console.writeToBuffer(i, y - 10, map[y - 10][i] = '+', 0x0C);
        }
        
    }
    for (int j = 0; j < 75; j++)
    {
        if (x < 40)
        {
            g_Console.writeToBuffer(x - 40, j, map[j][0] = '+', 0x0C);
        }
        else
        {
            g_Console.writeToBuffer(x - 40, j, map[j][x - 40] = '+', 0x0C);
        }
    }
    
    

}