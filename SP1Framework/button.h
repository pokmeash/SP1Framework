#pragma once
#include <string>
#include "position.h"

class button
{
private:
	int length;
	int width;
	std::string text;
	position pos;
	
public:
	button();
	button(int l, int w, std::string what, int x, int y);
	int getLength();
	int getWidth();
	std::string getText();
	position getPos();
	void setPos();

};

