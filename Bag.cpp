#include "Bag.h"

Bag::Bag()
{
	medicineCnt = 5;
	monsterballCnt = 10;
}

Bag::~Bag()
{

}

void Bag::UseItem(int type)
{
	if (type == I_Medicine) {
		medicineCnt--;
	}
	else if (type == I_Monsterball) {
		monsterballCnt--;
	}
}

void Bag::AddItem(int type)
{
	if (type == I_Medicine) {
		medicineCnt++;
		if (medicineCnt > MAX_VALUE)
			medicineCnt = MAX_VALUE;
	}
	else if (type == I_Monsterball) {
		monsterballCnt++;
		if (monsterballCnt > MAX_VALUE)
			monsterballCnt = MAX_VALUE;
	}
}
