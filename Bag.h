#pragma once
#include"Item.h"

int const MAX_VALIE = 99;

class Bag {
private:
	int medicineCnt = 0;
	int monsterballCnt = 0;
public:
	void UseItem(int type) {
		if (type == I_Medicine) {
			medicineCnt--;
		}
		else if (type == I_Monsterball) {
			monsterballCnt--;
		}
	}
};

