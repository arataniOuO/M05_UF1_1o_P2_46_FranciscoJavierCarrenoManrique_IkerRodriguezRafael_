#pragma once

#include "ConsoleUtils.h"
#include "Map.h"
#include "TimeManager.h"

#include <stdlib.h> 
#include <time.h>

class ghost
{
private:
	COORD spawn;
	COORD position;
	COORD direction;
	char ghostchar = 'X';
	float powerup_countdown = 0;
	const float powerup_countdown_time = 15;
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::MAGENTA;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;

	ConsoleUtils::CONSOLE_COLOR foreground_attack = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR foreground_powerUp = ConsoleUtils::CONSOLE_COLOR::CYAN;
	void GoRandom();

public:
	
	enum GHOST_STATE { GHOST_NONE, GHOST_KILLED, GHOST_DEAD };
	ghost();
	ghost(COORD _spawn);
	void Draw();
	//void Move(Map* _map);
	void PowerUpPicked();
	GHOST_STATE Update(Map* _map, COORD _player);
		
};

