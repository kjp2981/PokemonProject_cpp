#pragma once
#include"Pokemon.h"

const int HP_BAR = 10;

class Player;
class Battle {
public:
	Pokemon* wildPokemon;
public:
	void Update(Player player);
	void CreatePokemon();
	void PrintBattleScreen();
	void PrintPokemon(Player player);
	void PrintPokemonHp(Player player);
	void PrintPokemonName(Player player);
	void PrintText(Player player);
	~Battle();
};