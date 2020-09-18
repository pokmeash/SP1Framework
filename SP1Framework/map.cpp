#include "map.h"

void map::maparray(Console& g_Console)
{
    int p;
    //array to detect things
    for (int x = 0; x < 150; ++x)
    {
        for (int y = 0; y < 30; ++y)
        {
            map[y][x] = ' ';
        }
    }
    //walls in 4 sides
    for (int i = 0; i < 150; i++)
    {
        map[0][i] = '+';
        map[29][i] = '+';
    }
    for (int j = 0; j < 30; j++)
    {
        map[j][0] = '+';
        map[j][149] = '+';
    }
    //Power room wall right
    for (int j = 0; j < 30; j++)
    {
        map[j][30] = '+';
    }
    //Door to Room A from Power Room
    for (int j = 4; j < 7; j++)
    {
        map[j][30] = ' ';
    }
    //Door to Room G from Power Room
    for (int j = 24; j < 27; j++)
    {
        map[j][30] = ' ';
    }
    //Room A
    for (int j = 0; j < 6; j++)
    {
        map[j][60] = '+';
    }
    for (int j = 6; j < 11; j++)
    {
        map[j][80] = '+';
    }
    for (int i = 60; i < 80; i++)
    {
        map[6][i] = '+';
    }
    for (int i = 30; i < 80; i++)
    {
        map[10][i] = '+';
    }
    //Door to Room B from Room A
    for (int i = 69; i < 74; i++)
    {
        map[6][i] = ' ';
    }
    //Room B
    for (int i = 80; i < 120; i++)
    {
        map[8][i] = '+';
    }
    //Door to Room I from Room B
    for (int i = 98; i < 103; i++)
    {
        map[8][i] = ' ';
    }
    //Room C / Control Room
    for (int j = 0; j < 30; j++)
    {
        map[j][120] = '+';
    }
    
    //Door to Room D from Room C
    for (int j = 18; j < 22; j++)
    {
        map[j][120] = ' ';
    }


    //Room G
    for (int i = 30; i < 70; i++)
    {
        map[20][i] = '+';
    }
    for (int j = 20; j < 30; j++)
    {
        map[j][70] = '+';
    }
    //Door to Room H from Room G
    for (int i = 40; i < 45; i++)
    {
        map[20][i] = ' ';
    }
    //Room I 
    p = 20;
    for (int i = 70; i < 80; i++)
    {
        if (p > 10)
        {
            map[p][i] = '+';
            p--;
        }
    }
    p = 25;
    for (int i = 70; i < 120; (i = i + 4))
    {
        if (p > 7)
        {
            map[p][i] = '+';
            p--;
        }
    }
    p = 25;
    for (int i = 71; i < 120; (i = i + 4))
    {
        if (p > 7)
        {
            map[p][i] = '+';
            p--;
        }
    }
    p = 25;
    for (int i = 72; i < 120; (i = i + 4))
    {
        if (p > 7)
        {
            map[p][i] = '+';
            p--;
        }
    }
    p = 25;
    for (int i = 73; i < 120; (i = i + 4))
    {
        if (p > 7)
        {
            map[p][i] = '+';
            p--;
        }
    }
    //Door to Room I from Room H
    p = 15;
    for (int i = 75; i < 78; i++)
    {
        if (p > 12)
        {
            map[p][i] = ' ';
            p--;
        }
    }
    //Room D and E
    p = 19;
    for (int i = 95; i < 120; (i = i + 2))
    {
        if (p < 30)
        {
            map[p][i] = '+';
            p++;
        }
    }
    p = 19;
    for (int i = 96; i < 120; (i = i + 2))
    {
        if (p < 30)
        {
            map[p][i] = '+';
            p++;
        }
    }
    //Door to Room I from Room E
    for (int i = 82; i < 86; i++)
    {
        map[22][i] = ' ';
    }
    //Door to Room E from Room D
    for (int i = 107; i < 109; i++)
    {
        map[25][i] = ' ';
    }
    // oil stations
    map[12][33] = 'O';
    map[2][118] = 'O';
    map[27][74] = 'O';
    map[14][16] = 'O';
    map[14][135] = 'O';

}

void map::rendermap(Console& g_Console, int x, int y)
{
    for (int a = -10; a < 10; a++) 
    {
        for (int b = -40; b < 40; b++)
        {
            if (y + a < 30 && y + a > -1)
            {
                if (x + b < 150 && x + b > -1)   
                {
                    if (map[y + a][x + b] == '+')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '+', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'O')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'O', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'G')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'G', 0x7D);
                    }
                    else if (map[y + a][x + b] == ' ')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, ' ', 0x7F);
                    }
                    
                }
            }
        }
    }

}


void map::renderFullLantern(Console& g_Console, int x, int y)
{
    for (int a = -4; a < 5; a++)
    {
        for (int b = -10; b < 11; b++)
        {
            if (y + a < 75 && y + a > -1)
            {
                if (x + b < 560 && x + b > -1)
                {
                    if (map[y + a][x + b] == '+')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '+', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'O')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'O', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'G')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'G', 0x7D);
                    }
                    else if (map[y + a][x + b] == ' ')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, ' ', 0x7F);
                    }

                }
            }
        }
    }
}

void map::renderHalfLantern(Console& g_Console, int x, int y)
{
    for (int a = -3; a < 4; a++)
    {
        for (int b = -8; b < 9; b++)
        {
            if (y + a < 75 && y + a > -1)
            {
                if (x + b < 560 && x + b > -1)
                {
                    if (map[y + a][x + b] == '+')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '+', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'O')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'O', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'G')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'G', 0x7D);
                    }
                    else if (map[y + a][x + b] == ' ')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, ' ', 0x7F);
                    }

                }
            }
        }
    }
}

void map::renderDimLantern(Console& g_Console, int x, int y)
{
    for (int a = -1; a < 2; a++)
    {
        for (int b = -3; b < 4; b++)
        {
            if (y + a < 75 && y + a > -1)
            {
                if (x + b < 560 && x + b > -1)
                {
                    if (map[y + a][x + b] == '+')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '+', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'O')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'O', 0x8F);
                    }
                    else if (map[y + a][x + b] == 'G')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, 'G', 0x7D);
                    }
                    else if (map[y + a][x + b] == ' ')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, ' ', 0x7F);
                    }

                }
            }
        }
    }
}

void map::ghostposition(int x, int y)
{
    map[y][x] = 'G';
}

void map::deleteghostposition(int x, int y)
{
    map[y][x] = ' ';
}