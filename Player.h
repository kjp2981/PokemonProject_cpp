#pragma once
#include"Pokemon.h"

class Player {
protected:
	Pokemon hasPokemon[6];
	int pokemonList[6];
	
public:
	Player(){
		for (int i = 0; i < 6; i++)
			pokemonList[i] = 0;
	}
	void SetPokemon(int index, Pokemon pokemon) {
		pokemonList[index] = pokemon.GetId();
	}
};

