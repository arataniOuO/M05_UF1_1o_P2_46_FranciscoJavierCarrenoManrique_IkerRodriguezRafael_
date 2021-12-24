#pragma once

#include "ConsoleUtils.h"
#include "Map.h"
#include "ghost.h"

#include <vector>

enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
class Player
{

private:
	COORD spawn;
	COORD direction;
	char player_char = 'O';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::YELLOW;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;

public:

	int points = 0;
	COORD position;
	Player(COORD _spawn);
	void Update(Map* _map, USER_INPUTS input, std::vector<ghost>* enemies);
	void Draw();

};

