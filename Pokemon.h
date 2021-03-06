#pragma once
#include<iostream>
#include"Skill.h"
#include<string.h>
#include<string>
#include"TypeEnum.h"

#define HP rand() % 11;
#define ATTACK rand() % 6;
#define DEFENCE rand() % 6;
#define SPEED rand() % 6

const int MAX_LEVEL = 100;

enum PokemonList
{
	P_Chimchar = 1, // 불꽃숭이
	P_Turtwig, // 모부기
	P_Piplup, // 팽도리
	P_Pikachu, // 피카츄
	P_Gible, // 딥상어동
	P_Starly, // 찌르꼬
	P_Giratina, // 기라티나
	P_Metapod // 단데기
};

class Pokemon {
protected:
	int id;
	int type;
	int hp;
	int MAX_HP;
	int attack;
	int defence;
	int speed;
	std::string name;

	int level;
	int cExp; // 현재 경험치 량
	int mExp; // 최대 경험치 량(레벨업하기 위해 필요한 량)
	int CExp; // 누적 경험치
public:
	wchar_t backImage[7][14];
	wchar_t frontImage[7][14];
	Skill* skiiList[4];
public:
	int GetId();
	int GetHP();
	int GetMaxHP();
	int GetAttack();
	int GetDefence();
	int GetSpeed();
	int GetType();
	std::string GetName();
	void Heal(int amount);
	void Damage(int amount, int type, bool isEqual);
	float TypeCompatibility(int type1);
	Pokemon(int id, int type) : id(id), type(type), hp(0), MAX_HP(0), attack(0), defence(0), speed(0) {
		//image[0][0] = NULL;
		level = 1;
		cExp = 0;
		mExp = 100;

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 14; j++) {
				backImage[i][j] = NULL;
			}
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 14; j++) {
				frontImage[i][j] = NULL;
			}
		}

		for (int i = 0; i < 4; i++) {
			skiiList[i] = NULL;
		}
	}
	Pokemon(int id, int type, int hp, int maxHp, int attack, int defence, int speed) : id(id), type(type), hp(hp), MAX_HP(maxHp), attack(attack), defence(defence), speed(speed) {
		//image[0][0] = NULL;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 14; j++) {
				backImage[i][j] = NULL;
			}
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 14; j++) {
				frontImage[i][j] = NULL;
			}
		}

		for (int i = 0; i < 4; i++) {
			skiiList[i] = NULL;
		}
	}
	Pokemon(Pokemon* pokemon) {
		id = pokemon->GetId();
		type = pokemon->GetType();
		name = pokemon->GetName();
		hp = pokemon->GetHP();
		attack = pokemon->GetAttack();
		defence = pokemon->GetDefence();
		speed = pokemon->GetSpeed();
		MAX_HP = pokemon->GetMaxHP();

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 14; j++) {
				backImage[i][j] = pokemon->backImage[i][j];
			}
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 14; j++) {
				frontImage[i][j] = pokemon->frontImage[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			skiiList[i] = pokemon->skiiList[i];
		}
	}
	~Pokemon() {

	}
};

/// <summary>
/// 파이리 클래스
/// </summary>
class Chimchar : public Pokemon {
public:
	Chimchar() : Pokemon(P_Chimchar, Fire) {
		name = "불꽃숭이";
		hp = 44 + HP;
		attack = 58 + ATTACK;
		defence = 44 + DEFENCE;
		speed = 61 + SPEED;
		MAX_HP = hp;
		
		wcscpy_s(backImage[0], L"⠀⠀⢠⢶⠀⠀⠀⠀⠀⠀   ");
		wcscpy_s(backImage[1], L"⠀⠀⢸⡀⠹⣀⡀⠀⠀⠀   ");
		wcscpy_s(backImage[2], L"⠀⢠⠃⠠⣲⡄⣈⡆⠀    ");
		wcscpy_s(backImage[3], L"⠀⠘⡀⠘⣧⠾⠏⡇⡠⢄   ");
		wcscpy_s(backImage[4], L"⡐⢶⣾⡦⢬⣥⣤⡺⠀⣩   ");
		wcscpy_s(backImage[5], L"⢻⠈⠛⠁⢸⠑⠓⠊⠁⠀   ");
		wcscpy_s(backImage[6], L"⠈⠒⠒⠒⠒⠀⠀⠀⠀⠀   ");

		wcscpy_s(frontImage[0], L"⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀  ");
		wcscpy_s(frontImage[1], L"⠀⠀⠀⠀⢠⡚⠻⡀⠀⠀ ⠀ ");
		wcscpy_s(frontImage[2], L"⠀⠀⡤⠎⢁⣀⣈⣻⢤⠀⠀  ");
		wcscpy_s(frontImage[3], L"⠀⠐⣇⢳⠈⢠⣲⢱⣾⠀⠀  ");
		wcscpy_s(frontImage[4], L"⠀⡤⢬⣯⢤⡬⢟⣿⠓⢲⡀  ");
		wcscpy_s(frontImage[5], L"⠈⠓⠺⢾⡟⢃⡈⢪⡵⠋⠀  ");
		wcscpy_s(frontImage[6], L"⠀⠀⠀⠸⠭⡼⣿⣬⡷⠀⠀  ");

		skiiList[0] = new Scratch();
		skiiList[1] = new Ember();
		skiiList[2] = new PowerUpPunch();
		skiiList[3] = new FlameWheel();
	}
	Chimchar(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

/// <summary>
/// 모부기 클래스
/// </summary>
class Turtwig : public Pokemon {
public:
	Turtwig() : Pokemon(P_Turtwig, Grass) {
		name = "모부기";
		hp = 55 + HP;
		attack = 68 + ATTACK;
		defence = 64 + DEFENCE;
		speed = 31 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"⠀⠀⠀⠀⠀⢤⠀⠀⠀⠀   ");
		wcscpy_s(backImage[1], L"⠀⠀⠀⠀⡞⢰⠂⠀⠀⠀   ");
		wcscpy_s(backImage[2], L"⠀⠰⠭⠩⣿⠧⢤⣀⠀⠀   ");
		wcscpy_s(backImage[3], L"⠀⠀⠀⢠⠉⠁⠁⣠⣵⡆   ");
		wcscpy_s(backImage[4], L"⠀⢀⣴⣾⣶⣴⡉⠹⢭⠇   ");
		wcscpy_s(backImage[5], L"⢀⣧⢀⡄⣸⣿⣧⠤⠀⠀   ");
		wcscpy_s(backImage[6], L"⠛⠋⠓⠘⠉⠛⠒⠃⠀⠀   ");

		wcscpy_s(frontImage[0], L"⠀⠀⣶⠦⣄⣀⡤⢶⠀⠀ ⠀ ");
		wcscpy_s(frontImage[1], L"⠀⠀⠘⢦⣸⣧⠴⠋⠀⠀⠀  ");
		wcscpy_s(frontImage[2], L"⠀⣠⠞⠋⠙⠙⣦⠀⠀⠀   ");
		wcscpy_s(frontImage[3], L"⢸⡗⠂⠀⢈⢦⠾⣷⢄⠀   ");
		wcscpy_s(frontImage[4], L"⠘⣟⠦⠖⠋⢉⣠⣯⣷⣷⠀  ");
		wcscpy_s(frontImage[5], L"⠀⠈⢹⡏⢻⡝⠀⣸⡄⢸⡃  ");
		wcscpy_s(frontImage[6], L"⠀⠀⠀⠉⠋⠙⠒⠛⠉⠉⠀  ");

		skiiList[0] = new Tackle();
		skiiList[1] = new RazorLeaf();
		skiiList[2] = new Bite();
		skiiList[3] = new Megadrain();
	}
	Turtwig(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

/// <summary>
/// 팽도리 클래스
/// </summary>
class Piplup : public Pokemon {
public:
	Piplup() : Pokemon(P_Piplup, Water) {
		name = "팽도리";
		hp = 53 + HP;
		attack = 51 + ATTACK;
		defence = 53 + DEFENCE;
		speed = 40 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"⠀⠀⣀⣀⣀⠀⠀      ");
		wcscpy_s(backImage[1], L"⢠⣾⣷⣶⡷⠽⣆      ");
		wcscpy_s(backImage[2], L"⢻⣿⣿⣿⡇⢸⣿      ");
		wcscpy_s(backImage[3], L"⠀⣻⣿⣿⣿⢶⡉      ");
		wcscpy_s(backImage[4], L"⠸⡿⣿⠿⠣⣤⣱      ");
		wcscpy_s(backImage[5], L"⠀⠑⠒⠒⠒⠃⠀      ");
		wcscpy_s(backImage[6], L"⠀     ⠀      ");

		wcscpy_s(frontImage[0], L"⠀⠀⣀⡴⠶⡶⢦⣀⠀    ");
		wcscpy_s(frontImage[1], L"⣠⣾⣥⣠⣴⠶⠦⣝⣧    ");
		wcscpy_s(frontImage[2], L"⢿⣣⡸⢦⡏⢠⡄⢸⣿    ");
		wcscpy_s(frontImage[3], L"⠘⢿⣜⣾⣃⣨⣠⣾⡿    ");
		wcscpy_s(frontImage[4], L"⠀⣼⠫⠛⠙⠛⠉⢿⣿    ");
		wcscpy_s(frontImage[5], L"⠀⢸⣙⣳⣶⡤⢰⣾⠋    ");
		wcscpy_s(frontImage[6], L"⠀⠀⠀⠀⠈⠙⠛⠋⠀    ");

		skiiList[0] = new Pound();
		skiiList[1] = new WaterGun();
		skiiList[2] = new Peck();
		skiiList[3] = new BubbleBeam();
	}
	Piplup(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

/// <summary>
/// 피카추 클래스
/// </summary>
class Pikachu : public Pokemon {
public:
	Pikachu() : Pokemon(P_Pikachu, Electric) {
		name = "피카츄";
		hp = 35 + HP;
		attack = 55 + ATTACK;
		defence = 30 + DEFENCE;
		speed = 90 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"⠀⠀⠀⠀⠀⠀⠀⣤⡄⠀⠀ ⠀");
		wcscpy_s(backImage[1], L"⠀⣀⡄⢶⡖⠤⡀⣻⠋⢆⠀  ");
		wcscpy_s(backImage[2], L"⢠⠁⠈⠢⣑⡲⠃⠀⠑⢘⡄ ⠀");
		wcscpy_s(backImage[3], L"⠀⠉⢢⡤⢈⠧⣤⣀⠀⢠⠿  ");
		wcscpy_s(backImage[4], L"⠀⠀⠀⢳⣽⠛⠒⠦⠁⡤⠊⠁ ");
		wcscpy_s(backImage[5], L"⠀⠀⠀⠰⠭⠦⠤⠤⠤⠇⠀  ");
		wcscpy_s(backImage[6], L"⠀     ⠀      ");

		wcscpy_s(frontImage[0], L"⢀⡾⣦⠀⠀⣀⣠⣤⡄⠀⠀  ");
		wcscpy_s(frontImage[1], L"⢀⣧⡈⢉⣍⢡⣼⣟⠽⠲⡄  ");
		wcscpy_s(frontImage[2], L"⠸⣏⠛⡦⠸⢞⡿⠁⠀⢀⡽  ");
		wcscpy_s(frontImage[3], L"⠀⡟⢄⢀⠀⡀⣿⠒⣯⠁⠀  ");
		wcscpy_s(frontImage[4], L"⢸⠉⠚⠈⠚⠀⢹⡿⠁⠀⠀  ");
		wcscpy_s(frontImage[5], L"⠘⠯⠖⠋⠒⠶⠞⠁⠀⠀ ⠀ ");
		wcscpy_s(frontImage[6], L"⠀     ⠀      ");

		skiiList[0] = new QuickAttack();
		skiiList[1] = new Spark();
		skiiList[2] = new Thunderbolt();
		skiiList[3] = new Thunder();
	}
	Pikachu(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

/// <summary>
/// 딥상어동 클래스
/// </summary>
class Gible : public Pokemon {
public:
	Gible() : Pokemon(P_Gible, Dragon) {
		name = "딥상어동";
		hp = 58 + HP;
		attack = 70 + ATTACK;
		defence = 45 + DEFENCE;
		speed = 42 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"⠀⢀⣠⣤⣀⣀⠀⠀⡀⠀   ");
		wcscpy_s(backImage[1], L"⠀⠘⣧⡀⠀⢠⡝⠙⢽⡇   ");
		wcscpy_s(backImage[2], L"⠀⠀⣾⣯⡀⡏⢈⣦⣾⣿   ");
		wcscpy_s(backImage[3], L"⠀⠀⢹⠏⢀⠉⠉⢠⣿⡇   ");
		wcscpy_s(backImage[4], L"⠀⢀⡯⠈⠰⡱⡀⢦⣀⣿   ");
		wcscpy_s(backImage[5], L"⠺⠵⠦⠤⠤⠽⠧⠤⠿⠃   ");
		wcscpy_s(backImage[6], L"⠀     ⠀      ");

		wcscpy_s(frontImage[0], L"⠀⠀⠀⡠⠊⣹⠀⠀⠀    ");
		wcscpy_s(frontImage[1], L"⢀⡤⡞⠀⢀⠿⢤⣀⠀    ");
		wcscpy_s(frontImage[2], L"⠘⠿⣦⡯⢷⠒⠊⣽⡆    ");
		wcscpy_s(frontImage[3], L"⠀⠀⡟⣅⢋⣱⠀⡵⠁    ");
		wcscpy_s(frontImage[4], L"⠀⠀⠙⠚⠉⠙⠐⠁⠀    ");
		wcscpy_s(frontImage[5], L"⠀     ⠀      ");
		wcscpy_s(frontImage[6], L"⠀     ⠀      ");

		skiiList[0] = new Tackle();
		skiiList[1] = new DragonBreath();
		skiiList[2] = new Bite();
		skiiList[3] = new DragonClaw();
	}
	Gible(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

/// <summary>
/// 찌르꼬 클래스
/// </summary>
class Starly : public Pokemon {
public:
	Starly() : Pokemon(P_Starly, Flying) {
		name = "찌르꼬";
		hp = 30 + HP;
		attack = 55 + ATTACK;
		defence = 30 + DEFENCE;
		speed = 60 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"⠀⠀⠀⠀⢠⣶⠀⠀⠀⠀⠀  ");
		wcscpy_s(backImage[1], L"⠀⠀⠀⠀⣸⣛⣲⣐⢄⠀⠀  ");
		wcscpy_s(backImage[2], L"⠀⠀⠀⣰⣯⠷⣯⡏⠸⣷⠄  ");
		wcscpy_s(backImage[3], L"⢴⡈⢻⣟⠻⣻⣾⠽⠶⢧⠀  ");
		wcscpy_s(backImage[4], L"⠘⢿⣘⣿⢼⣿⣻⣤⣀⡜⠀  ");
		wcscpy_s(backImage[5], L"⠀⠈⠙⠓⠒⠛⠓⠛⠉⠀⠀  ");
		wcscpy_s(backImage[6], L"             ");

		wcscpy_s(frontImage[0], L"⠀⠀⢠⣤⠄⠀⠀⠀⠀⠀   ");
		wcscpy_s(frontImage[1], L"⠀⢠⣿⣿⠓⠲⡀⠀⠀⠀   ");
		wcscpy_s(frontImage[2], L"⠀⣿⡏⢹⣧⡠⣽⠋⣽⡆   ");
		wcscpy_s(frontImage[3], L"⢸⣿⠿⠶⠶⣯⠛⣿⣿⠁   ");
		wcscpy_s(frontImage[4], L"⠈⢿⣶⣤⣔⣹⣶⡿⠃⠀   ");
		wcscpy_s(frontImage[5], L"⠀⠀⠛⠛⠛⠾⠋⠀⠀⠀   ");
		wcscpy_s(frontImage[6], L"             ");

		skiiList[0] = new Tackle();
		skiiList[1] = new QuickAttack();
		skiiList[2] = new WingAttack();
		skiiList[3] = new AerialAce();
	}
	Starly(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

/// <summary>
/// 키라티나 클래스
/// </summary>
class Giratina : public Pokemon {
public:
	Giratina() : Pokemon(P_Giratina, Ghost) {
		name = "기라티나";
		hp = 150 + HP;
		attack = 120 + ATTACK;
		defence = 100 + DEFENCE;
		speed = 90 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"⠀⠀⠀⠀⣠⠀⠀⢀⡄⠀⠀⠀ ");
		wcscpy_s(backImage[1], L"⠀⢀⣤⣼⠃⣀⠰⡿⠷⠶⡀⠀ ");
		wcscpy_s(backImage[2], L"⣠⣼⣿⡗⠪⢄⣶⡯⣄⡠⢈⣲ ");
		wcscpy_s(backImage[3], L"⢹⣿⣿⣿⢶⣸⣿⣷⢭⡛⢞⠀ ");
		wcscpy_s(backImage[4], L"⢸⣿⣿⣏⣧⣽⡿⠣⠭⣙⢏⠀ ");
		wcscpy_s(backImage[5], L"⣽⣿⣿⣿⠗⣽⣧⡈⣲⣌⡣⠀ ");
		wcscpy_s(backImage[6], L"             ");

		wcscpy_s(frontImage[0], L"⣀⣤⠖⡜⣛⠂⢴⣤⣦⣄⠀  ");
		wcscpy_s(frontImage[1], L"⢾⣿⡷⢾⡷⠘⣿⣿⣿⠆⡁  ");
		wcscpy_s(frontImage[2], L"⠉⢿⣋⣸⡯⠙⢹⠿⠾⢷⢄  ");
		wcscpy_s(frontImage[3], L"⠀⠈⡞⣼⣿⠐⢚⡵⡶⡉⡞  ");
		wcscpy_s(frontImage[4], L"⠀⢈⠑⣿⣿⣰⢉⣍⢈⠘⠀  ");
		wcscpy_s(frontImage[5], L"⠀⠤⠮⠛⠚⠻⢑⣾⠶⠛⠀  ");
		wcscpy_s(frontImage[6], L"             ");

		skiiList[0] = new AuraSphere();
		skiiList[1] = new AncientPower();
		skiiList[2] = new DragonClaw();
		skiiList[3] = new ShadowForce();
	}
	Giratina(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};

class Metapod : public Pokemon {
public:
	Metapod() : Pokemon(P_Metapod, Bug) {
		name = "단데기";
		hp = 600 + HP;
		attack = 1 + ATTACK;
		defence = 505 + DEFENCE;
		speed = 1 + SPEED;
		MAX_HP = hp;

		wcscpy_s(backImage[0], L"  ⠀⠀⠀⢀⣀⠀⠀    ");
		wcscpy_s(backImage[1], L"  ⠀⠀⠀⣼⠈⡆⠀    ");
		wcscpy_s(backImage[2], L"  ⠀⠀⡰⠃⢄⣹⡄    ");
		wcscpy_s(backImage[3], L"  ⠀⣞⠡⠈⠌⡻⢇    ");
		wcscpy_s(backImage[4], L"  ⠀⡟⢣⣈⠌⣷⠞    ");
		wcscpy_s(backImage[5], L"  ⣸⠤⢄⡸⢠⡟⠀    ");
		wcscpy_s(backImage[6], L"  ⠁⠀⠈⠉⠉⠀⠀    ");

		wcscpy_s(frontImage[0], L"⠀⠀⠀⢀⣠⡀⠀⠀⠀⠀   ");
		wcscpy_s(frontImage[1], L"⠀⠀⣴⠏⠈⣧⠀⠀⠀⠀   ");
		wcscpy_s(frontImage[2], L"⢀⡾⣃⣖⡶⣟⣧⠀⠀⠀   ");
		wcscpy_s(frontImage[3], L"⢸⣅⣠⠛⣮⠍⡙⣻⡆⠀   ");
		wcscpy_s(frontImage[4], L"⠀⠹⡜⢳⡏⡌⡹⣧⣁⣀   ");
		wcscpy_s(frontImage[5], L"⠀⠀⠙⠧⣿⣠⣽⣭⣿⡟   ");
		wcscpy_s(frontImage[6], L"             ");
	}
	Metapod(Pokemon* pokemon) : Pokemon(pokemon) {

	}
};