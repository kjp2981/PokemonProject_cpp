#pragma once
#include"Bag.h"
#include"Manager.h"
//#include <vector>

typedef struct pos {
	int x;
	int y;
} POS, *PPOS;

class Map;
class Pokemon;
class Player {
public:
	POS pos;
	bool isBattle;
	bool isGiratina; // 기라티나 배틀인지 아닌지
	Pokemon* pokemonList[6];
	Bag* bag;
private:
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
	void SwapPokemon(int fIdx, int sIdx);
	void AllPokemonHeal();
	bool IsPokemonEmpty();
	bool IsPokemonFull();
	int EmptyPokemonIndex();
	void PrintPokemon();
};