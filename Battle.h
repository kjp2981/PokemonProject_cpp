#pragma once
#include"Pokemon.h"

const int HP_BAR = 10;

enum CursorPos
{
	ONE = 1,
	TWO,
	THREE,
	FOUR
};

typedef struct Cousorpos {
	int pos;
} CORSORPOS;

class Player;
class Map;

class Battle {
private:
	CORSORPOS _pos;
	int input;
public:
	Pokemon* wildPokemon;
	Player* player;
	Map* map;
public:
	void Update();
	void CreatePokemon();
	void AllPrint();
	void PrintBattleScreen();
	void PrintPokemon();
	void PrintPokemonHp();
	void PrintPokemonName();
	void PrintText();
	void MoveCursor();
	void PrintCursor();
	void DeleteCursor();
	void Input();
	//void SetPlayer(Player* player);
	//void MouseClick();
	Battle(Player* player, Map* map);
	~Battle();
};