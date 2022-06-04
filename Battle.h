#pragma once
#include"Pokemon.h"

class Player;
class Battle {
public:
	Pokemon* wildPokemon;
	void Update(Player player);
	void CreatePokemon();
	void PrintBattleScreen();
	void PrintPokemon(Player player);
};