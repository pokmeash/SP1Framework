#pragma once
#include "Framework\console.h"
#include <string>

class cutscene
{
private:
	std::string* story;
	int noofLines;
public:
	cutscene();
	cutscene(int lines);
	~cutscene();
	void setStory(int index, std::string text);
	std::string getLine(int index);
	int getnoofLines();
	
	
};

void frame(Console& g_Console);