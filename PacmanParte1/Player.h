#pragma once

#include "ConsoleUtils.h"
#include "Map.h"

class Player
{
public:
	enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
	char player_char = 'O';
	int player_x;
	int player_y;
	int player_points = 0;
	USER_INPUTS input = USER_INPUTS::NONE;
	bool run = true;
	bool win = false;

public:

	Player();

	void Input();

	void Logic(int mapWidth, int mapHeight, Map _map);

};

