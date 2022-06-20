#pragma once

int const MAX_VALUE = 99;

enum ItemType
{
	I_Medicine,
	I_Monsterball,
	I_Gold
};

class Item {
public:
	int count;
public:
	Item(int count) : count(count) {

	}
	virtual void UseItem(int amount) = 0;
	virtual void AddItem(int amount) = 0;
	bool IsUseItem(int amount);
};

class Medicine : public Item {
public:
	Medicine(int count) : Item(count) {

	}
	void UseItem(int amount) {
		if (IsUseItem(amount))
			count -= amount;
	}
	void AddItem(int amount) {
		count += amount;
		if (count > MAX_VALUE)
			count = MAX_VALUE;
	}
};

class Monsterball : public Item {
public:
	Monsterball(int count) : Item(count) {

	}
	void UseItem(int amount) {
		if (IsUseItem(amount))
			count -= amount;
	}
	void AddItem(int amount) {
		count += amount;
		if (count > MAX_VALUE)
			count = MAX_VALUE;
	}
};

class Gold : public Item {
public:
	Gold(int count) : Item(count) {

	}
	void UseItem(int amount) {
		if (IsUseItem(amount))
			count -= amount;
	}
	void AddItem(int amount) {
		count += amount;
		if (count > MAX_VALUE)
			count = MAX_VALUE;
	}
};