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
private:
	Pokemon* pokemonList[6];
	Bag* bag;
	int walkCnt;
private:
	void MoveUp(char map[MAX_X][MAX_Y]);
	void MoveDown(char map[MAX_X][MAX_Y]);
	void MoveLeft(char map[MAX_X][MAX_Y]);
	void MoveRight(char map[MAX_X][MAX_Y]);
public:
	Player() {
		SetPlayerPos();
		walkCnt = 0;
	}
	void MovePlayer(Map mapClass);
	void SetPlayerPos() {
		pos.x = 0;
		pos.y = 15;
	}
	void SetFirstPokemon() { // 어걸 점더 때깔 나게 나중에 고치기
		switch (rand() % 3 + 1)
		{
		case P_Chimchar:
			pokemonList[0] = new Chimchar();
			break;
		case P_Turtwig:
			pokemonList[0] = new Chimchar();
			break;
		case P_Piplup:
			pokemonList[0] = new Chimchar();
			break;
		default:
			break;
		}
	}
};