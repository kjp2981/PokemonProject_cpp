#pragma once
#include"Pokemon.h"

class Battle {
public:
	Pokemon* wildPokemon;
	void Update();
	void CreatePokemon();
	void PrintBattleScreen();
};