#pragma once
#include<iostream>
#include"Skill.h"
#include<string.h>
#include<string>

using namespace std;

#define HP rand() % 11;
#define ATTACK rand() % 6;
#define DEFENCE rand() % 6;
#define SPEED rand() % 6

enum PokemonList
{
	P_Chimchar = 1, // 불꽃숭이
	P_Turtwig, // 모부기
	P_Piplup, // 팽도리
	P_Pikachu, // 피카츄
	P_Gible, // 딥상어동
	P_Starly, // 찌르꼬
	P_Giratina // 기라티나
};

enum PokemonType {
	Fire = 1, // 불
	Grass, // 풀
	Water, // 물
	Lighting, // 번개
	Dragon, // 드래곤
	Flight, // 비행
	Ghost // 고스트
};

class Pokemon {
protected:
	int id; // 이거.. 왜 만들었지..?
	int type;
	int hp;
	int MAX_HP;
	int attack;
	int defence;
	int speed;
	string name;
public:
	wchar_t backImage[7][14];
	wchar_t frontImage[7][14];
	Skill* skiiList[4]; // 추후 구현 일단 변수만...
public:
	int GetId();
	int GetHP();
	int GetMaxHP();
	int GetAttack();
	int GetDefence();
	int GetSpeed();
	int GetType();
	string GetName();
	void Heal(int amount);
	void Damage(int amount);
	//Pokemon() : id(0), type(0), hp(0), MAX_HP(0), attack(0), defence(0), speed(0) {
	//	//image[0][0] = NULL;
	//	for (int i = 0; i < 7; i++) {
	//		for (int j = 0; j < 14; j++) {
	//			backImage[i][j] = NULL ;
	//		}
	//	}

	//	for (int i = 0; i < 7; i++) {
	//		for (int j = 0; j < 14; j++) {
	//			frontImage[i][j] = NULL;
	//		}
	//	}
	//	
	//	for (int i = 0; i < 4; i++) {
	//		skiiList[i] = NULL;
	//	}
	//}
	Pokemon(int id, int type) : id(id), type(type), hp(0), MAX_HP(0), attack(0), defence(0), speed(0) {
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

		skiiList[0] = new Scratching();
		skiiList[1] = new FlameBaptism();
		skiiList[2] = new GrowPunch();
		skiiList[3] = new FlameCar();
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

		skiiList[0] = new Bumping();
		skiiList[1] = new LeafBlade();
		skiiList[2] = new Gnaw();
		skiiList[3] = new Megadrain();
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

		skiiList[0] = new Scuffle();
		skiiList[1] = new WaterCannon();
		skiiList[2] = new Peck();
		skiiList[3] = new BubbleBeam();
	}
};

/// <summary>
/// 피카추 클래스
/// </summary>
class Pikachu : public Pokemon {
public:
	Pikachu() : Pokemon(P_Pikachu, Lighting) {
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
	}
};

/// <summary>
/// 찌르꼬 클래스
/// </summary>
class Starly : public Pokemon {
public:
	Starly() : Pokemon(P_Starly, Flight) {
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
	}
};