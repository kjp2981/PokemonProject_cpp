#pragma once
#include"Item.h"

int const MAX_VALUE = 99;

class Bag {
public:
	int medicineCnt;
	int monsterballCnt;
public:
	Bag();
	~Bag();
	void UseItem(int type);
	void AddItem(int type);
};