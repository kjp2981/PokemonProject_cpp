#pragma once
#include"Pokemon.h"
#include"Bag.h"
#include"Manager.h"
//#include"Map.h"

typedef struct pos {
	int x;
	int y;
} POS, *PPOS;

class Map;
class Player {
public:
	pos pos;
	bool isBattle;
	Pokemon* pokemonList[6];
private:
	Bag* bag;
	int walkCnt;
private:
	void MoveUp(char map[MAX_X][MAX_Y]);
	void MoveDown(char map[MAX_X][MAX_Y]);
	void MoveLeft(char map[MAX_X][MAX_Y]);
	void MoveRight(char map[MAX_X][MAX_Y]);
public:
	Player();
	~Player();
	Pokemon* FirstPokemon();
	void MovePlayer(Map mapClass);
	void SetPlayerPos();
	void SetFirstPokemon();
};