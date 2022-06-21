#pragma once
#include"Pokemon.h"

const int HP_BAR = 10;

enum CursorPos
{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
};

enum InputType {
	E_Choice = 0,
	E_Skill,
	E_Item,
	E_Pokemon
};

typedef struct Cousorpos {
	int pos;
} CORSORPOS;

class Player;
class Map;

class Battle {
private:
	CORSORPOS _pos;
	int input;
	bool isInput;
	bool isTurn; // 내턴인지 상대천인지 구별하는 불값 변수, 내턴이면 True
public:
	Pokemon* wildPokemon;
	Player* player;
	Map* map;
public:
	void Update();
	void CreatePokemon();
	void PrintBattleStartAnim();
	void AllPrint();
	void PrintBattleScreen();
	void PrintPokemon();
	void PrintPokemonHp();
	void PrintPokemonName();
	void PrintText();
	void MoveCursor();
	void PrintCursor();
	void DeleteCursor();
	void SetTurn();
	void EnemyAttack();
	void Input();
	void IgnoreInput();
	//void MouseClick();
	Battle(Player* player, Map* map);
	~Battle();
};