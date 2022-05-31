#pragma once
#include"Player.h"
#include"Manager.h"
#include"Pokemon.h"

class Map
{
public:
	char map[MAX_X][MAX_Y];
	void SetMap();
	void PrintMap(char map[MAX_X][MAX_Y], PPOS playerPos);
	bool CheckGrass(char map[MAX_X][MAX_Y], PPOS playerPos);
};

