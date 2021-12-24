#include "ghost.h"

void ghost::GoRandom()
{
	direction = { 0,0 };
	int r = rand() % 4;
	switch (r)
	{
	case 0:
		direction.X = 1;
		break;
	case 1:
		direction.X = -1;
		break;
	case 2:
		direction.Y = 1;
		break;
	case 3:
		direction.Y = -1;
		break;
	}
}


ghost::ghost()
{
	spawn = { 20,10 };
	position = spawn;
	direction = { 0,0 };
}

ghost::ghost(COORD _spawn)
{
	spawn = _spawn;
	position = _spawn;
	direction = { 0,0 };
}

void ghost::Draw()
{
	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << ghostchar;
}

void ghost::PowerUpPicked()
{
	powerup_countdown = TimeManager::getInstance().time + powerup_countdown_time;
}

ghost::GHOST_STATE ghost::Update(Map* _map, COORD _player)
{
	GoRandom();
	COORD newPosition = position;
	newPosition.X += direction.X;
	newPosition.Y += direction.Y;

	if (newPosition.X < 0)
	{
		newPosition.X = _map->Width - 1;
	}
	newPosition.X %= _map->Width;
	if (newPosition.Y < 0)
	{
		newPosition.Y = _map->Height - 1;
	}
	newPosition.Y %= _map->Height;

	switch (_map->GetTile(newPosition.X, newPosition.Y))
	{
	case Map::MAP_TILES::MAP_WALL:
		newPosition = position;
		break;
	}
	position = newPosition;

	GHOST_STATE state = GHOST_STATE::GHOST_NONE;
	if (position.X == _player.X && position.Y == _player.Y) {
		if (powerup_countdown <= TimeManager::getInstance().time) {
			state = GHOST_STATE::GHOST_DEAD;
		}
		else {
			position = spawn;
			state = GHOST_STATE::GHOST_KILLED;
		}
	}
	if (powerup_countdown <= TimeManager::getInstance().time) {
		foreground = foreground_attack;
	}
	else {
		foreground = foreground_powerUp;
	}
	return state;
}


//void ghost::Move(Map* _map)
//{
//	GoRandom();
//	COORD newPosition = position;
//	newPosition.X += direction.X;
//	newPosition.Y += direction.Y;
//
//	if (newPosition.X < 0)
//	{
//		newPosition.X = _map->Width - 1;
//	}
//	newPosition.X %= _map->Width;
//	if (newPosition.Y < 0)
//	{
//		newPosition.Y = _map->Height - 1;
//	}
//	newPosition.Y %= _map->Height;
//
//	switch (_map->GetTile(newPosition.X, newPosition.Y))
//	{
//	case Map::MAP_TILES::MAP_WALL:
//		newPosition = position;
//		break;
//	}
//	position = newPosition;
//}
