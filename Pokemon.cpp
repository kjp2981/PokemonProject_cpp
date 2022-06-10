#include "Pokemon.h"
#include <conio.h>

int Pokemon::GetId() {
	return id;
}

int Pokemon::GetHP()
{
	return this->hp;
}

int Pokemon::GetAttack()
{
	return attack;
}

int Pokemon::GetDefence()
{
	return defence;
}

int Pokemon::GetMaxHP()
{
	return MAX_HP;
}

int Pokemon::GetSpeed()
{
	return speed;
}

int Pokemon::GetType()
{
	return type;
}

string Pokemon::GetName()
{
	return name;
}

void Pokemon::Damage(int amount)
{
	// ((((레벨 * 2 / 5) + 2) * Attack * 위력 / 50) / Defence) * 타입 상성
	int damage = (((2 / 5) + 2) * attack * amount / 50 / defence);
	damage = damage > 0 ? damage : 1;
	hp -= damage;
}

void Pokemon::Heal(int amount)
{
	hp += amount;
}
