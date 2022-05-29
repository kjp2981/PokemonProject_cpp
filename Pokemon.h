#pragma once
#include<iostream>
#include"Skill.h"

#define HP rand() % 11;
#define ATTACK rand() % 6;
#define DEFENCE rand() % 6;
#define SPEED rand() % 6

enum PokemonList // �׳� �̰� string���� ������ ��? �׷��� ����
{
	P_Chimchar = 1, // �Ҳɼ���
	P_Turtwig, // ��α�
	P_Piplup, // �ص���
	P_Pikachu, // ��ī��
	P_Gible, // ����
	P_Starly, // ���
	P_Giratina // ���Ƽ��
};

enum PokemonType {
	Fire, // ��
	Grass, // Ǯ
	Water, // ��
	Lighting, // ����
	Dragon, // �巡��
	Flight, // ����
	Ghost // ��Ʈ
};

class Pokemon { // �ϴ� ���� ����
protected:
	int id;
	int type;
	int hp;
	int attack;
	int defence;
	int speed;
	//Skill skiiList[4];
public:
	int GetId() { return id; }
	Pokemon() {

	}
	Pokemon(int id, int type) : id(id), type(type), hp(0), attack(0), defence(0), speed(0) {

	}
	~Pokemon() {

	}
};

class Chimchar : public Pokemon {
	Chimchar() : Pokemon(P_Chimchar, Fire) {
		hp = 44 + HP;
		attack = 58 + ATTACK;
		defence = 44 + DEFENCE;
		speed = 61 + SPEED;
	}
};

class Turtwig : public Pokemon {
	Turtwig() : Pokemon(P_Turtwig, Grass) {
		hp = 55 + HP;
		attack = 68 + ATTACK;
		defence = 64 + DEFENCE;
		speed = 31 + SPEED;
	}
};

class Piplup : public Pokemon {
	Piplup() : Pokemon(P_Piplup, Water) {
		hp = 53 + HP;
		attack = 51 + ATTACK;
		defence = 53 + DEFENCE;
		speed = 40 + SPEED;
	}
};

class Pikachu : public Pokemon {
	Pikachu() : Pokemon(P_Pikachu, Lighting) {
		hp = 35 + HP;
		attack = 55 + ATTACK;
		defence = 30 + DEFENCE;
		speed = 90 + SPEED;
	}
};

class Gible : public Pokemon {
	Gible() : Pokemon(P_Gible, Dragon) {
		hp = 58 + HP;
		attack = 70 + ATTACK;
		defence = 45 + DEFENCE;
		speed = 42 + SPEED;
	}
};

class Starly : public Pokemon {
	Starly() : Pokemon(P_Starly, Flight) {
		hp = 30 + HP;
		attack = 55 + ATTACK;
		defence = 30 + DEFENCE;
		speed = 60 + SPEED;
	}
};

class Giratina : public Pokemon {
	Giratina() : Pokemon(P_Giratina, Ghost) {
		hp = 150 + HP;
		attack = 120 + ATTACK;
		defence = 100 + DEFENCE;
		speed = 90 + SPEED;
	}
};