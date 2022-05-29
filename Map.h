#pragma once
#include"Player.h"
#include"Manager.h"

class Map
{
public:
	char map[MAX_X][MAX_Y];
	void SetMap(char map[MAX_X][MAX_Y]);
	void PrintMap(char map[MAX_X][MAX_Y], PPOS playerPos);
	bool CheckGrass(char map[MAX_X][MAX_Y], PPOS playerPos);
};

