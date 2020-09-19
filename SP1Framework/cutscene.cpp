#include "Cutscene.h"

cutscene::cutscene() : noofLines(0)
{
	//no codes here
}

cutscene::cutscene(int lines) : noofLines(lines)
{
	story = new std::string[lines];
}

cutscene::~cutscene()
{
	delete[] story;
}

void cutscene::setStory(int index, std::string text)
{
	story[index] = text;
}

std::string cutscene::getLine(int index)
{
	return story[index];
}

int cutscene::getnoofLines()
{
	return noofLines;
}

void introcutscene1(Console& g_Console)
{
	//80 by 19
	//0 to 3
	//campfire
	g_Console.writeToBuffer(25, 3,  "           )            ", 0x0F);
	g_Console.writeToBuffer(25, 4,  "         (   )          ", 0x0F);
	g_Console.writeToBuffer(25, 5,  "       (   )  )         ", 0x0F);
	g_Console.writeToBuffer(25, 6,  "      (   ( )  )       ", 0x0F);
	g_Console.writeToBuffer(25, 7,  "  _____(___  _)______  ", 0x0F);
	g_Console.writeToBuffer(25, 8,  " |_______  \\/ _______| ", 0x0F);
	g_Console.writeToBuffer(25, 9,  "         /    \\        ", 0x0F);
	g_Console.writeToBuffer(25, 10, "  ______/  /\\  \\______ ", 0x0F);
	g_Console.writeToBuffer(25, 11, " |________/  \\________|", 0x0F);
	//left person
	g_Console.writeToBuffer(15, 3, "   __", 0x0F);
	g_Console.writeToBuffer(15, 4, "  /  \\", 0x0F);
	g_Console.writeToBuffer(15, 5, "  \\__/", 0x0F);
	g_Console.writeToBuffer(15, 6, "    | /", 0x0F);
	g_Console.writeToBuffer(15, 7, "___ |/ ", 0x0F);
	g_Console.writeToBuffer(15, 8, "\\  \\|", 0x0F);
	g_Console.writeToBuffer(15, 9, " \\  |__", 0x0F);
	g_Console.writeToBuffer(15, 10, "  \\  \\ \\", 0x0F);
	g_Console.writeToBuffer(15, 11, "   \\  \\", 0x0F);
	g_Console.writeToBuffer(15, 12, "    \\__\\", 0x0F);
	//right person
	g_Console.writeToBuffer(48, 3, "    __", 0x0F);
	g_Console.writeToBuffer(48, 4, "   /  \\", 0x0F);
	g_Console.writeToBuffer(48, 5, "   \\__/", 0x0F);
	g_Console.writeToBuffer(48, 6, "   \\ |", 0x0F);
	g_Console.writeToBuffer(48, 7, "    \\| ___", 0x0F);
	g_Console.writeToBuffer(48, 8, "     |/  /", 0x0F);
	g_Console.writeToBuffer(48, 9, "   __|  /", 0x0F);
	g_Console.writeToBuffer(48, 10, "  / /  /", 0x0F);
	g_Console.writeToBuffer(48, 11, "   /  /", 0x0F);
	g_Console.writeToBuffer(48, 12, "  /__/", 0x0F);
}

void introcutscene2(Console& g_Console)
{
	//80 by 19
	//4 to 7
	//wholething?
	g_Console.writeToBuffer(0, 3, "                                   ___", 0x0F);
	g_Console.writeToBuffer(0, 4, "                                  / _ | ", 0x0F);
	g_Console.writeToBuffer(0, 5, "   ______                _________| |______", 0x0F);
	g_Console.writeToBuffer(0, 6, "  /|_||  \\              /  /\\  \\    /   /| \\", 0x0F);
	g_Console.writeToBuffer(0, 7, " /    |   \\         |\\_|  |--|  \\/\\/   /_|  \\", 0x0F);
	g_Console.writeToBuffer(0, 8, "      |             |     |  |           |  /", 0x0F);
	g_Console.writeToBuffer(0, 9, " _____|_____________|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^", 0x0F);
	g_Console.writeToBuffer(0, 10, "      |             \\____________", 0x0F);
	g_Console.writeToBuffer(0, 11, "      |      _       \\   \\   \\   \\", 0x0F);
	g_Console.writeToBuffer(0, 12, "            / \\       \\ __\\ __\\___\\", 0x0F);
	g_Console.writeToBuffer(0, 13, "            \\_/        \\    |     |", 0x0F);
	g_Console.writeToBuffer(0, 14, "            \\|/         \\   |     |", 0x0F);
	g_Console.writeToBuffer(0, 15, "             |           |", 0x0F);
	g_Console.writeToBuffer(0, 16, "            / \\          |", 0x0F);
	g_Console.writeToBuffer(0, 17, "                        /", 0x0F);
	g_Console.writeToBuffer(0, 18, "                       /", 0x0F);
	g_Console.writeToBuffer(0, 19, "                      /", 0x0F);
}
