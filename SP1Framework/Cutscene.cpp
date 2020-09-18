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

void frame(Console& g_Console)
{
	g_Console.writeToBuffer(1,1, ' ', 0xFF);
}
