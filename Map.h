#pragma once
#include"Player.h"

static const int MAX_X = 30;
static const int MAX_Y = 31;

Player* player;
class Map
{
public:
	char map[MAX_X][MAX_Y];
	void SetMap(char map[MAX_X][MAX_Y]);
	void PrintMap(char map[MAX_X][MAX_Y], PPOS playerPos);
};

