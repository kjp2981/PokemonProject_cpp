#pragma once

int const MAX_VALUE = 99;

enum ItemType
{
	I_Medicine,
	I_Monsterball
};

class Item {
public:
	int count;
public:
	Item(int count) : count(count) {

	}
	virtual void UseItem() = 0;
	virtual void AddItem() = 0;
	bool IsUseItem();
};

class Medicine : public Item {
public:
	Medicine(int count) : Item(count) {

	}
	void UseItem() {
		if(IsUseItem())
			--count;
	}
	void AddItem() {
		++count;
		if (count > MAX_VALUE)
			count = MAX_VALUE;
	}
};

class Monsterball : public Item {
public:
	Monsterball(int count) : Item(count) {

	}
	void UseItem() {
		if (IsUseItem())
			--count;
	}
	void AddItem() {
		++count;
		if (count > MAX_VALUE)
			count = MAX_VALUE;
	}
};