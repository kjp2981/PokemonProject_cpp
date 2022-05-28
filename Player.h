#pragma once
#include"Pokemon.h"
#include"Bag.h"

typedef struct pos {
	int x;
	int y;
} POS, *PPOS;

class Player {
private:
	pos pos;
	Pokemon pokemonList[6];
	Bag* bag;
private:
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
public:
	void MovePlayer();
};