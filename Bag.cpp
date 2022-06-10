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
		++this->medicineCnt;
		if (this->medicineCnt > MAX_VALUE)
			this->medicineCnt = MAX_VALUE;
	}
	else if (type == I_Monsterball) {
		++this->monsterballCnt;
		if (this->monsterballCnt > MAX_VALUE)
			this->monsterballCnt = MAX_VALUE;
	}
}
