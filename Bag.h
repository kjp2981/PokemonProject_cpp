#pragma once
#include"Item.h"

int const MAX_VALUE = 99;

class Bag {
public:
	int medicineCnt = 0;
	int monsterballCnt = 0;
public:
	Bag();
	~Bag();
	void UseItem(int type);
	void AddItem(int type);
};

