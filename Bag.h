#pragma once
#include"Item.h"

class Medicine;
class Monsterball;
class Bag {
private:
	Medicine* medicine;
	Monsterball* monsterball;
public:
	Bag();
	~Bag();
	void UseItem(int type);
	void AddItem(int type);
	int GetItemCount(int type);
	bool isUseItem(int type);
};