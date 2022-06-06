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
} COURSORPOS;

class Player;

class Battle {
private:
	COURSORPOS _pos;
public:
	Pokemon* wildPokemon;
public:
	void Update(Player player);
	void CreatePokemon(Player player);
	void PrintBattleScreen();
	void PrintPokemon(Player player);
	void PrintPokemonHp(Player player);
	void PrintPokemonName(Player player);
	void PrintText(Player player);
	void MoveCursor(Player player);
	void PrintCursor();
	void DeleteCursor();
	Battle();
	~Battle();
};