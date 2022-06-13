#include "Bag.h"
#include"Item.h"

Bag::Bag()
{
	medicine = new Medicine(5);
	monsterball = new Monsterball(10);
}

Bag::~Bag()
{
	if (medicine != nullptr)
		delete medicine;
	if (monsterball != nullptr)
		delete monsterball;
}

void Bag::UseItem(int type)
{
	if (type == I_Medicine) {
		medicine->UseItem();
	}
	else if (type == I_Monsterball) {
		monsterball->UseItem();
	}
}

void Bag::AddItem(int type)
{
	if (type == I_Medicine) {
		medicine->AddItem();
	}
	else if (type == I_Monsterball) {
		monsterball->AddItem();
	}
}

int Bag::GetItemCount(int type)
{
	if (type == I_Medicine) {
		return medicine->count;
	}
	else if (type == I_Monsterball) {
		return monsterball->count;
	}

	return -1;
}

bool Bag::isUseItem(int type)
{
	if (type == I_Medicine) {
		return medicine->IsUseItem();
	}
	else if (type == I_Monsterball) {
		return monsterball->IsUseItem();
	}

	return false;
}
