#include "Bag.h"
#include"Item.h"

Bag::Bag()
{
	medicine = new Medicine(5);
	monsterball = new Monsterball(10);
	gold = new Gold(5000);
}

Bag::~Bag()
{
	if (medicine != nullptr)
		delete medicine;
	if (monsterball != nullptr)
		delete monsterball;
	if (gold != nullptr)
		delete gold;
}

void Bag::UseItem(int type, int amount)
{
	if (type == I_Medicine) {
		medicine->UseItem(amount);
	}
	else if (type == I_Monsterball) {
		monsterball->UseItem(amount);
	}
	else if (type == I_Gold) {
		gold->UseItem(amount);
	}
}

void Bag::AddItem(int type, int amount)
{
	if (type == I_Medicine) {
		medicine->AddItem(amount);
	}
	else if (type == I_Monsterball) {
		monsterball->AddItem(amount);
	}
	else if (type == I_Gold) {
		gold->AddItem(amount);
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
	else if (type == I_Gold) {
		return gold->count;
	}

	return -1;
}

bool Bag::IsUseItem(int type, int amount)
{
	if (type == I_Medicine) {
		return medicine->IsUseItem(amount);
	}
	else if (type == I_Monsterball) {
		return monsterball->IsUseItem(amount);
	}
	else if (type == I_Gold) {
		return gold->IsUseItem(amount);
	}

	return false;
}
