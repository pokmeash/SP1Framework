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
    /*
    map[12][33] = 'O';
    map[2][118] = 'O';
    map[27][74] = 'O';
    map[14][16] = 'O';
    map[14][135] = 'O';
    */
}

void map::rendermap(Console& g_Console, int x, int y, int light)
{
    int x1, x2, y1, y2, e;
    x1 = x2 = y1 = y2 = e = 0;
    e = light;
    switch (e)
    {
    case 0: // full view
        y1 = -10;
        y2 = 10;
        x1 = -40;
        x2 = 40;
        break;
    case 1: // full lantern
        y1 = -4;
        y2 = 5;
        x1 = -10;
        x2 = 11;
        break;
    case 2: // half lantern
        y1 = -3;
        y2 = 4;
        x1 = -8;
        x2 = 9;
        break;
    case 3: // dim lantern
        y1 = -1;
        y2 = 2;
        x1 = -3;
        x2 = 4;
        break;
    }
    for (int a = y1; a < y2; a++)
    {
        for (int b = x1; b < x2; b++)
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
                    else if (map[y + a][x + b] == '|')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '|', 0x78);
                    }
                    else if (map[y + a][x + b] == '-')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '-', 0x11);
                    }
                    else if (map[y + a][x + b] == char(12))
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, char(12), 0x7D);
                    }
                    else if (map[y + a][x + b] == char(248))
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, char(248), 0x1B);
                    }
                    else if (map[y + a][x + b] == char(247))
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, char(247), 0x19);
                    }
                    else if (map[y + a][x + b] == char(158))
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, char(158), 0x79);
                    }
                    else if (map[y + a][x + b] == '<')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '<', 0x19);
                    }

                    else if (map[y + a][x + b] == '>')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '>', 0x19);
                    }
                    else if (map[y + a][x + b] == '#')
                    {
                        g_Console.writeToBuffer(40 + b, 10 + a, '#', 0x55);
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

void map::roomA1() 
{
    //left vert wall
    for (int i = 9; i > 5; i--)
    {
        map[i][51] = '+';
    }
    //vert wall
    for (int i = 7; i < 9; i++)
    {
        map[i][64] = '+';
    }
    //hori wall
    for (int i = 77; i > 68; i--)
    {
        map[8][i] = '+';
    }
    for (int i = 40; i < 48; i++)
    {
        map[3][i] = '#';
    }
}
void map::roomA2()
{
    //hori top wall
    for (int i = 31; i < 45; i++)
    {
        map[3][i] = '+';
    }
    //hori middle wall
    for (int i = 63; i > 50; i--)
    {
        map[8][i] = '+';
    }
    
}

void map::roomA3()
{
    //hori top wall
    for (int i = 9; i > 4; i--)
    {
        map[i][42] = '+';
    }
    //hori middle wall
    for (int i = 65; i > 60; i--)
    {
        map[8][i] = '+';
    }
    //vert wall
    for (int i = 7; i < 9; i++)
    {
        map[i][65] = '+';
    }
}

void map::roomB1()
{
    //vert mid wall
    for (int i = 7; i > 3; i--)
    {
        map[i][90] = '+';
    }
    //vert right wall
    for (int i = 1; i < 6; i++)
    {
        map[i][111] = '+';
    }
    //tables
    for (int i = 1; i < 6; i++)
    {
        map[i][67] = '#';
    }
    //oil station
    map[6][83] = 'O';

    //left stickman
    map[1][61] = '|';
    map[2][61] = '|';
    map[3][61] = char(12);

    //mid stickman
    map[1][63] = '|';
    map[2][63] = '|';
    map[3][63] = char(12);

    //right stickman
    map[1][65] = '|';
    map[2][65] = '|';
    map[3][65] = char(12);

}

void map::roomB2()
{
    //hori mid wall
    for (int i = 81; i < 108; i++)
    {
        map[6][i] = '+';
    }
    //vert mid wall
    for (int i = 2; i < 5; i++)
    {
        map[i][88] = '+';
    }
    //vert right wall
    for (int i = 3; i < 8; i++)
    {
        map[i][113] = '+';
    }
    //tables
    for (int i = 1; i < 6; i++)
    {
        map[i][67] = '#';
    }
    //oil station
    map[6][117] = 'O';

    //left stickman
    map[1][61] = '|';
    map[2][61] = '|';
    map[3][61] = char(12);

    //mid stickman
    map[1][63] = '|';
    map[2][63] = '|';
    map[3][63] = char(12);

    //right stickman
    map[1][65] = '|';
    map[2][65] = '|';
    map[3][65] = char(12);

}

void map::roomB3()
{
    //vert left wall
    for (int i = 1; i < 4; i++)
    {
        map[i][67] = '+';
    }
    //vert mid wall
    for (int i = 3; i < 6; i++)
    {
        map[i][80] = '+';
    }
    //vert right wall
    for (int i = 5; i < 8; i++)
    {
        map[i][88] = '+';
    }
    //tables
    for (int i = 1; i < 8; i++)
    {
        map[i][109] = '#';
    }
    //oil station
    map[6][84] = 'O';

    //left stickman
    map[1][111] = '|';
    map[2][111] = '|';
    map[3][111] = char(12);

    //mid stickman
    map[1][113] = '|';
    map[2][113] = '|';
    map[3][113] = char(12);

    //right stickman
    map[1][115] = '|';
    map[2][115] = '|';
    map[3][115] = char(12);

}

void map::roomD1()
{
    //vert top wall
    for (int i = 16; i < 21; i++)
    {
        map[i][113] = '+';
    }
    //hori middle wall
    for (int i = 105; i < 115; i++)
    {
        map[23][i] = '+';
    }
    //hori bottom wall
    for (int i = 111; i < 120; i++)
    {
        map[26][i] = '+';
    }
}

void map::roomD2()
{
    //vert top wall
    for (int i = 16; i < 21; i++)
    {
        map[i][113] = '+';
    }
    //hori middle wall
    for (int i = 110; i < 120; i++)
    {
        map[23][i] = '+';
    }
}

void map::roomD3()
{
    //vert mid wall
    for (int i = 21; i < 26; i++)
    {
        map[i][113] = '+';
    }
    //hori top wall
    for (int i = 110; i < 120; i++)
    {
        map[19][i] = '+';
    }
}

void map::roomE1()
{
    //vert mid wall
    for (int i = 22; i < 26; i++)
    {
        map[i][87] = '+';
    }
    //hori left mid wall
    for (int i = 80; i < 87; i++)
    {
        map[25][i] = '+';
    }
    //hori left wall
    for (int i = 26; i < 28; i++)
    {
        map[i][80] = '+';
    }
    //hori bottom wall
    for (int i = 76; i < 91; i++)
    {
        map[27][i] = '+';
    }
    //vert right mid wall
    for (int i = 23; i < 29; i++)
    {
        map[i][95] = '+';
    }
    //hori right mid wall
    for (int i = 98; i < 102; i++)
    {
        map[24][i] = '+';
    }
    //vert right bottom wall
    for (int i = 27; i < 29; i++)
    {
        map[i][101] = '+';
    }
    //oil station
    map[27][106] = 'O';
}

void map::roomE2()
{
    //vert mid wall
    for (int i = 22; i < 24; i++)
    {
        map[i][87] = '+';
    }
    //hori left mid wall
    for (int i = 80; i < 87; i++)
    {
        map[25][i] = '+';
    }
    //hori left wall
    for (int i = 26; i < 28; i++)
    {
        map[i][80] = '+';
    }
    //hori bottom wall
    for (int i = 76; i < 91; i++)
    {
        map[27][i] = '+';
    }
    //vert short left mid wall
    map[28][82] = '+';
    //vert right mid wall
    for (int i = 23; i < 25; i++)
    {
        map[i][95] = '+';
    }
    //vert right mid wall2
    for (int i = 27; i < 29; i++)
    {
        map[i][95] = '+';
    }
    //vert mid wall
    for (int i = 23; i < 26; i++)
    {
        map[i][99] = '+';
    }
    //hori right bottom wall
    for (int i = 98; i < 105; i++)
    {
        map[26][i] = '+';
    }
    //vert right bottom wall
    map[27][101] = '+';
    //oil station
    map[24][101] = 'O';
}

void map::roomE3()
{
    //hori left mid wall
    for (int i = 80; i < 87; i++)
    {
        map[25][i] = '+';
    }
    //hori left wall
    for (int i = 27; i < 28; i++)
    {
        map[i][80] = '+';
    }
    //hori bottom wall
    for (int i = 80; i < 91; i++)
    {
        map[27][i] = '+';
    }
    //vert right mid wall
    for (int i = 22; i < 25; i++)
    {
        map[i][95] = '+';
    }
    //vert right mid wall2
    for (int i = 27; i < 29; i++)
    {
        map[i][95] = '+';
    }
    //vert center wall
    for (int i = 21; i < 27; i++)
    {
        map[i][90] = '+';
    }
    //vert mid wall
    for (int i = 20; i < 26; i++)
    {
        map[i][99] = '+';
    }

    //hori right bottom wall
    for (int i = 98; i < 105; i++)
    {
        map[26][i] = '+';
    }
    //vert right bottom wall
    map[27][101] = '+';
    //oil station
    map[20][95] = 'O';
    map[24][80] = '+';
}

void map::roomG1()
{
    //water
    for (int i = 31; i < 70; i++)
    {
        for (int j = 21; j < 29; j++)
        {
            map[j][i] = '-';
        }
    }
    //bubbles
    map[23][36] = char(248);
    map[26][43] = char(248);
    map[22][56] = char(248);
    map[25][65] = char(248);
    map[23][47] = char(248);
    map[26][55] = char(248);
    map[28][36] = char(248);
    //waves
    for (int j = 55; j < 58; j++)
    {
        map[26][j] = char(247);
    }
    map[28][36] = char(247);
    //fish
    map[23][47] = '<';
    map[23][48] = '>';
    map[23][49] = '<';
}

void map::roomG2()
{
}

void map::roomG3()
{
}

void map::roomH1()
{
    map[12][33] = char(158);
    map[14][33] = char(158);
    map[16][33] = char(158);

}

void map::roomH2()
{
}

void map::roomH3()
{
}