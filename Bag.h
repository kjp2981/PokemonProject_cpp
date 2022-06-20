#pragma once
#include"Item.h"

class Medicine;
class Monsterball;
class Bag {
private:
	Medicine* medicine;
	Monsterball* monsterball;
	Gold* gold;
public:
	Bag();
	~Bag();
	void UseItem(int type, int amount);
	void AddItem(int type, int amount);
	int GetItemCount(int type);
	bool IsUseItem(int type, int amount);
};