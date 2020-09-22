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
                        g_Console.writeToBuffer(40 + b, 10 + a, ' ', 0x8F);
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
    //face right
    toilet(33, 13, 3); //on top
    toilet(33, 17, 3); //below
}

void map::roomH2()
{
    //face up
    toilet(35, 17, 0);
    toilet(55, 17, 0);

    //face down
    toilet(35, 13, 2);
    toilet(45, 13, 2);
    toilet(55, 13, 2);

}

void map::roomH3()
{
    //face right
    toilet(33, 13, 3); //on top
    toilet(33, 17, 3); //below

    //face left
    toilet(66, 13, 1); //on top
    toilet(66, 17, 1); //below
}

void map::toilet(int xLoc, int yLoc, int dir)
{
    switch (dir)
    {
    case 0: // face up
        //toilet seat
        map[yLoc][xLoc] = char(158);
        //top
        map[yLoc - 1][xLoc + 1] = '+';
        map[yLoc - 1][xLoc - 1] = '+';
        //bottom
        map[yLoc + 1][xLoc + 1] = '+';
        map[yLoc + 1][xLoc - 1] = '+';
        map[yLoc + 1][xLoc] = '+';
        //left
        map[yLoc][xLoc - 1] = '+';
        //right
        map[yLoc][xLoc + 1] = '+';
        break;

    case 1: // face left
        //toilet seat
        map[yLoc][xLoc] = char(158);
        //top
        map[yLoc - 1][xLoc + 1] = '+';
        map[yLoc - 1][xLoc - 1] = '+';
        map[yLoc - 1][xLoc] = '+';
        //bottom
        map[yLoc + 1][xLoc + 1] = '+';
        map[yLoc + 1][xLoc - 1] = '+';
        map[yLoc + 1][xLoc] = '+';
        //right
        map[yLoc][xLoc + 1] = '+';
        break;

    case 2: // face down
        //toilet seat
        map[yLoc][xLoc] = char(158);
        //top
        map[yLoc - 1][xLoc + 1] = '+';
        map[yLoc - 1][xLoc - 1] = '+';
        map[yLoc - 1][xLoc] = '+';
        //bottom
        map[yLoc + 1][xLoc + 1] = '+';
        map[yLoc + 1][xLoc - 1] = '+';
        //left
        map[yLoc][xLoc - 1] = '+';
        //right
        map[yLoc][xLoc + 1] = '+';
        break;

    case 3: // face right
        //toilet seat
        map[yLoc][xLoc] = char(158);
        //top
        map[yLoc - 1][xLoc + 1] = '+';
        map[yLoc - 1][xLoc - 1] = '+';
        map[yLoc - 1][xLoc] = '+';
        //bottom
        map[yLoc + 1][xLoc + 1] = '+';
        map[yLoc + 1][xLoc - 1] = '+';
        map[yLoc + 1][xLoc] = '+';
        //left
        map[yLoc][xLoc - 1] = '+';
        break;
    }
}
}

void map::roomI1()
{
    //y level 9 to 12 to 24
    //x level 71 119
    //Ladders
    map[24][72] = 'L';
    map[23][77] = 'L';
    map[16][78] = 'L';
    map[15][80] = 'L';
    map[11][92] = 'L';
    map[9][105] = 'L';
    map[18][94] = 'L';
    map[18][97] = 'L';
    map[17][91] = 'L';
    map[11][80] = 'L';
    map[13][97] = 'L';
    map[13][117] = 'L';
    map[14][113] = 'L';
    map[16][104] = 'L';
    map[17][101] = 'L';
    //walls fun time
    //horizontal walls
    for (int i = 105; i < 116; i++)
    {
        map[10][i] = 'B';
    }
    for (int i = 113; i < 117; i++)
    {
        map[13][i] = 'B';
    }
    for (int i = 109; i < 113; i++)
    {
        map[14][i] = 'B';
    }
    for (int i = 103; i < 110; i++)
    {
        map[15][i] = 'B';
    }
    for (int i = 102; i < 104; i++)
    {
        map[16][i] = 'B';
    }
    for (int i = 94; i < 100; i++)
    {
        map[17][i] = 'B';
    }
    for (int i = 98; i < 101; i++)
    {
        map[13][i] = 'B';
    }
    for (int i = 100; i < 108; i++)
    {
        map[12][i] = 'B';
    }
    for (int i = 95; i < 99; i++)
    {
        map[15][i] = 'B';
    }
    for (int i = 89; i < 94; i++)
    {
        map[19][i] = 'B';
    }
    for (int i = 81; i < 90; i++)
    {
        map[20][i] = 'B';
    }
    for (int i = 77; i < 82; i++)
    {
        map[21][i] = 'B';
    }
    for (int i = 74; i < 76; i++)
    {
        map[23][i] = 'B';
    }
    for (int i = 71; i < 75; i++)
    {
        map[20][i] = 'B';
    }
    for (int i = 74; i < 79; i++)
    {
        map[17][i] = 'B';
    }
    for (int i = 80; i < 82; i++)
    {
        map[12][i] = 'B';
    }
    for (int i = 82; i < 85; i++)
    {
        map[10][i] = 'B';
    }
    for (int i = 90; i < 94; i++)
    {
        map[10][i] = 'B';
    }
    for (int i = 87; i < 95; i++)
    {
        map[12][i] = 'B';
    }
    for (int i = 84; i < 86; i++)
    {
        map[12][i] = 'B';
    }
    for (int i = 83; i < 86; i++)
    {
        map[18][i] = 'B';
    }
    for (int i = 87; i < 91; i++)
    {
        map[14][i] = 'B';
    }
    //vertical walls
    for (int j = 10; j < 12; j++)
    {
        map[j][118] = 'B';
    }
    for (int j = 15; j < 18; j++)
    {
        map[j][100] = 'B';
    }
    for (int j = 18; j < 20; j++)
    {
        map[j][93] = 'B';
    }
    for (int j = 9; j < 13; j++)
    {
        map[j][97] = 'B';
    }
    for (int j = 11; j < 13; j++)
    {
        map[j][110] = 'B';
    }
    for (int j = 10; j < 12; j++)
    {
        map[j][103] = 'B';
    }
    for (int j = 13; j < 15; j++)
    {
        map[j][104] = 'B';
    }
    for (int j = 10; j < 15; j++)
    {
        map[j][95] = 'B';
    }
    for (int j = 19; j < 24; j++)
    {
        map[j][76] = 'B';
    }
    for (int j = 22; j < 25; j++)
    {
        map[j][73] = 'B';
    }
    for (int j = 12; j < 20; j++)
    {
        map[j][79] = 'B';
    }
    for (int j = 14; j < 19; j++)
    {
        map[j][81] = 'B';
    }
    for (int j = 9; j < 12; j++)
    {
        map[j][86] = 'B';
    }
    for (int j = 13; j < 16; j++)
    {
        map[j][83] = 'B';
    }
    for (int j = 13; j < 17; j++)
    {
        map[j][91] = 'B';
    }
    for (int j = 16; j < 20; j++)
    {
        map[j][87] = 'B';
    }
    for (int j = 14; j < 17; j++)
    {
        map[j][85] = 'B';
    }
    //one block walls??????????????????????
    map[11][117] = 'B';
    map[12][116] = 'B';
    map[14][93] = 'B';
    map[16][93] = 'B';
    map[12][109] = 'B';
    map[14][80] = 'B';
    map[11][82] = 'B';
    map[15][88] = 'B';
}