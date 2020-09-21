#pragma once
#include <string>
#include "position.h"

class button
{
private:
	int length;
	int width;
	std::string text;
	position pos; // midpoint
	position corner[4];
	
public:
	button();
	button(int l, int w, std::string what, int x, int y);
	int getLength();
	int getWidth();
	std::string getText();
	position getPos();
	position getCorner(int index);
};

