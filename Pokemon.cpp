#include "Pokemon.h"
#include <conio.h>

int Pokemon::GetId() {
	return id;
}

int Pokemon::GetHP()
{
	return hp;
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
	hp -= amount;
	// 화면 갱신
}

void Pokemon::Heal(int amount)
{
	hp += amount;
	// 화면 갱신
}
