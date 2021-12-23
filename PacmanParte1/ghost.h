#pragma once
#include "ConsoleUtils.h"
#include "Map.h"	
#include <stdlib.h> 
#include <time.h>
class ghost
{
private:
	COORD position;
	COORD direction;
	char ghostchar = 'X';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::MAGENTA;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;


public:
	ghost();
	void GoRandom();
	void Draw();
	void Move(Map* _map);
		
};

