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

void introcutscene(Console& g_Console)
{
	//80 by 19

	g_Console.writeToBuffer(0, 7, "  _________  ________", 0x0F);
	g_Console.writeToBuffer(0, 8, " |_______  \/ _______| ", 0x0F);
	g_Console.writeToBuffer(0, 7, "         /    \ ", 0x0F);
	g_Console.writeToBuffer(0, 7, "  ______/  /\  \______", 0x0F);
	g_Console.writeToBuffer(0, 7, " |________/  \________|", 0x0F);
}
