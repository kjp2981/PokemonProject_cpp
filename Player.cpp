#include "Player.h"
#include <Windows.h>
#include"Manager.h"
#include"Map.h"
#include"Random.h"
#include "Console.h"

Player::Player() {
	for (int i = 0; i < 6; i++)
		pokemonList[i] = NULL;

	SetPlayerPos();
	SetFirstPokemon();
	/*pokemonList[0] = new Piplup();
	pokemonList[1] = new Chimchar();
	pokemonList[2] = new Giratina();
	pokemonList[3] = new Turtwig();
	pokemonList[4] = new Pikachu();
	pokemonList[5] = new Gible();*/
	pokemonList[1] = new Giratina();
	walkCnt = 0;
	isBattle = false;
	isGiratina = false;
	bag = new Bag();
}

Player::~Player()
{

}

Pokemon* Player::FirstPokemon()
{
	return pokemonList[0];
}

void Player::MoveUp(char map[MAX_X][MAX_Y])
{
	if (pos.y > 0) {
		if ((map[pos.y - 1][pos.x] != '1') && (map[pos.y - 1][pos.x] != '2')) {
			--pos.y;
		}
	}
}

void Player::MoveDown(char map[MAX_X][MAX_Y])
{
	if (pos.y < 29) {
		if ((map[pos.y + 1][pos.x] != '1') && (map[pos.y + 1][pos.x] != '2')) {
			++pos.y;
		}
	}
}

void Player::MoveLeft(char map[MAX_X][MAX_Y])
{
	if (pos.x > 0) {
		if (map[pos.y][pos.x - 1] != '2') {
			--pos.x;
		}
	}
}

void Player::MoveRight(char map[MAX_X][MAX_Y])
{
	if (pos.x < 29) {
		if (map[pos.y][pos.x + 1] == '2') {
			pos.x += 2;
		}
		else {
			++pos.x;
		}
	}
}

void Player::MovePlayer(Map mapClass)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		MoveUp(mapClass.map);
		Sleep(50);
		if (mapClass.CheckGrass(mapClass.map, &pos))
			walkCnt++;
		else
			walkCnt = 0;
		if (mapClass.CheckGrass(mapClass.map, &pos) && walkCnt > 3) {
			int random = Random();
			if (random < 0) {
				walkCnt = 0;
				isGiratina = false;
				isBattle = true;
				//system("cls");
				Clear();
			}
			else {
				random = Random();
				if (random < 30) {
					// TODO : 아이템 출현
					random = Random();
					if (random < 50) {
						// 몬스터 볼
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "몬스터볼을 발견했다!";
						bag->AddItem(I_Monsterball, 1);
					}
					else {
						// 상처약
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "상처약을 발견했다!";
						bag->AddItem(I_Medicine, 1);
					}
				}
			}
		}
		else
			mapClass.PrintMap(mapClass.map, &pos);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		MoveDown(mapClass.map);
		Sleep(50);
		if (mapClass.CheckGrass(mapClass.map, &pos))
			walkCnt++;
		else
			walkCnt = 0;
		if (mapClass.CheckGrass(mapClass.map, &pos) && walkCnt > 3) {
			int random = Random();
			if (random < 40) {
				walkCnt = 0;
				isGiratina = false;
				isBattle = true;
				//system("cls");
				Clear();
			}
			else {
				random = Random();
				if (random < 30) {
					// TODO : 아이템 출현
					random = Random();
					if (random < 50) {
						// 몬스터 볼
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "몬스터볼을 발견했다!";
						bag->AddItem(I_Monsterball, 1);
					}
					else {
						// 상처약
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "상처약을 발견했다!";
						bag->AddItem(I_Medicine, 1);
					}
				}
			}
		}
		else
			mapClass.PrintMap(mapClass.map, &pos);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		MoveLeft(mapClass.map);
		Sleep(50);
		if (mapClass.CheckGrass(mapClass.map, &pos))
			walkCnt++;
		else
			walkCnt = 0;
		if (mapClass.CheckGrass(mapClass.map, &pos) && walkCnt > 3) {
			int random = Random();
			if (random < 40) {
				walkCnt = 0;
				isGiratina = false;
				isBattle = true;
				//system("cls");
				Clear();
			}
			else {
				random = Random();
				if (random < 30) {
					// TODO : 아이템 출현
					random = Random();
					if (random < 50) {
						// 몬스터 볼
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "몬스터볼을 발견했다!";
						bag->AddItem(I_Monsterball, 1);
					}
					else {
						// 상처약
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "상처약을 발견했다!";
						bag->AddItem(I_Medicine, 1);
					}
				}
			}
		}
		else
			mapClass.PrintMap(mapClass.map, &pos);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		MoveRight(mapClass.map);
		Sleep(50);
		if (mapClass.CheckGrass(mapClass.map, &pos))
			walkCnt++;
		else
			walkCnt = 0;
		if (mapClass.CheckGrass(mapClass.map, &pos) && walkCnt > 3) {
			int random = Random();
			if (random < 40) {
				walkCnt = 0;
				isGiratina = false;
				isBattle = true;
				//system("cls");
				Clear();
			}
			else {
				random = Random();
				if (random < 30) {
					// TODO : 아이템 출현
					random = Random();
					if (random < 50) {
						// 몬스터 볼
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "몬스터볼을 발견했다!";
						bag->AddItem(I_Monsterball, 1);
					}
					else {
						// 상처약
						mapClass.PrintMap(mapClass.map, &pos);
						Gotoxy(26, 14);
						cout << "상처약을 발견했다!";
						bag->AddItem(I_Medicine, 1);
					}
				}
			}
		}
		else
			mapClass.PrintMap(mapClass.map, &pos);
	}
}

void Player::SetPlayerPos() {
	pos.x = 15;
	pos.y = 15;
}

void Player::SetFirstPokemon() {
	switch (rand() % 3 + 1)
	{
	case P_Chimchar:
		pokemonList[0] = new Chimchar();
		break;
	case P_Turtwig:
		pokemonList[0] = new Turtwig();
		break;
	case P_Piplup:
		pokemonList[0] = new Piplup();
		break;
	default:
		break;
	}
}

void Player::SwapPokemon(int fIdx, int sIdx)
{
	if (fIdx == sIdx) return;
	Pokemon* temp;
	temp = pokemonList[fIdx];
	pokemonList[fIdx] = pokemonList[sIdx];
	pokemonList[sIdx] = temp;
}

void Player::AllPokemonHeal()
{
	for (int i = 0; i < 6; i++) {
		if(pokemonList[i] != NULL)
			pokemonList[i]->Heal(pokemonList[i]->GetMaxHP());
	}
}

bool Player::IsPokemonEmpty()
{
	for (int i = 0; i < 6; i++) {
		if (pokemonList[i] == NULL)
			return true;
	}
	return false;
}

bool Player::IsPokemonFull()
{
	for (int i = 0; i < 6; i++) {
		if (pokemonList[i] == NULL)
			return false;
	}

	return true;
}

int Player::EmptyPokemonIndex()
{
	for (int i = 0; i < 6; i++) {
		if (pokemonList[i] == NULL)
			return i;
	}
	return -1;
}
