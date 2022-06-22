#include "Pokemon.h"
#include <conio.h>
#include"Console.h"
#include "Manager.h"

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

void Pokemon::Damage(int amount, int type, bool isEqual)
{
	// ((((레벨 * 2 / 5) + 2) * Attack * 위력 / 50) / Defence) * 타입 상성
	float typeCom = TypeCompatibility(type);
	int damage = ceil((float)(((1 * 2 / 5) + 2) * attack * amount / 50 / defence)
		* typeCom * (isEqual ? 1.5f : 1));
	damage = damage > 0 ? damage : 1;
	damage = damage < 10 ? damage * 2 : damage;
	hp -= damage;

	if (typeCom == 0) {
		Gotoxy(6, 22);
		cout << "효과가";
		Gotoxy(6, 23);
		cout << "나지 않는다.";
	}
	else if (typeCom == 0.5f) {
		Gotoxy(6, 22);
		cout << "효과는";
		Gotoxy(6, 23);
		cout << "별로였다.";
	}
	else if (typeCom == 1) {
		Gotoxy(6, 22);
		cout << "효과는";
		Gotoxy(6, 23);
		cout << "평범했다.";
	}
	else if (typeCom == 2) {
		Gotoxy(6, 22);
		cout << "효과는";
		Gotoxy(6, 23);
		cout << "굉장했다!";
	}
	else {
		Gotoxy(6, 21);
		cout << "효과는";
		Gotoxy(6, 22);
		cout << "평범했다.";
	}
}

void Pokemon::Heal(int amount)
{
	hp += amount;
	if (hp > MAX_HP) {
		hp = MAX_HP;
	}
}

float Pokemon::TypeCompatibility(int type1)
{
	switch (type1)
	{
	case Fire:
		switch (this->type)
		{
		case Fire:
			return 0.5f;
			break;
		case Grass:
			return 2;
			break;
		case Water:
			return 0.5f;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 0.5f;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 1;
			break;
		case Bug:
			return 2;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 0.5f;
			break;
		default:
			break;
		}
		break;
	case Grass:
		switch (this->type)
		{
		case Fire:
			return 0.5f;
			break;
		case Grass:
			return 2;
			break;
		case Water:
			return 2;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 0.5f;
			break;
		case Flying:
			return 0.5f;
			break;
		case Ghost:
			return 1;
			break;
		case Bug:
			return 0.5f;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 2;
			break;
		default:
			break;
		}
		break;
	case Water:
		switch (this->type)
		{
		case Fire:
			return 2;
			break;
		case Grass:
			return 0.5f;
			break;
		case Water:
			return 0.5f;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 0.5f;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 1;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 2;
			break;
		default:
			break;
		}
		break;
	case Electric:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 0.5f;
			break;
		case Water:
			return 2;
			break;
		case Electric:
			return 0.5f;
			break;
		case Dragon:
			return 0.5f;
			break;
		case Flying:
			return 2;
			break;
		case Ghost:
			return 1;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 1;
			break;
		default:
			break;
		}
		break;
	case Dragon:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 1;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 2;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 1;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 1;
			break;
		default:
			break;
		}
		break;
	case Flying:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 2;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 0.5f;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 1;
			break;
		case Bug:
			return 2;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 2;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 0.5f;
			break;
		default:
			break;
		}
		break;
	case Ghost:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 1;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 2;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 0;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 0.5f;
			break;
		case Rock:
			return 1;
			break;
		default:
			break;
		}
		break;
	case Bug:
		switch (this->type)
		{
		case Fire:
			return 0.5f;
			break;
		case Grass:
			return 2;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 0.5f;
			break;
		case Ghost:
			return 0.5f;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 0.5f;
			break;
		case Dark:
			return 2;
			break;
		case Rock:
			return 1;
			break;
		default:
			break;
		}
		break;
	case Normal:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 1;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 0;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 0.5f;
			break;
		default:
			break;
		}
		break;
	case Fighting:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 1;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 0.5f;
			break;
		case Ghost:
			return 0;
			break;
		case Bug:
			return 0.5f;
			break;
		case Normal:
			return 2;
			break;
		case Fighting:
			return 1;
			break;
		case Dark:
			return 2;
			break;
		case Rock:
			return 2;
			break;
		default:
			break;
		}
		break;
	case Dark:
		switch (this->type)
		{
		case Fire:
			return 1;
			break;
		case Grass:
			return 1;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 1;
			break;
		case Ghost:
			return 2;
			break;
		case Bug:
			return 1;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 0.5f;
			break;
		case Dark:
			return 0.5f;
			break;
		case Rock:
			return 1;
			break;
		default:
			break;
		}
		break;
	case Rock:
		switch (this->type)
		{
		case Fire:
			return 2;
			break;
		case Grass:
			return 1;
			break;
		case Water:
			return 1;
			break;
		case Electric:
			return 1;
			break;
		case Dragon:
			return 1;
			break;
		case Flying:
			return 2;
			break;
		case Ghost:
			return 2;
			break;
		case Bug:
			return 2;
			break;
		case Normal:
			return 1;
			break;
		case Fighting:
			return 0.5f;
			break;
		case Dark:
			return 1;
			break;
		case Rock:
			return 1;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 1;
}
