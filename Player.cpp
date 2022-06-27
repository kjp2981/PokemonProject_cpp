#include "Player.h"
#include <Windows.h>
#include"Manager.h"
#include"Map.h"
#include"Random.h"
#include "Console.h"
#include "SoundManager.h"

using namespace std;

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
			if (random < 40) {
				walkCnt = 0;
				isGiratina = false;
				isBattle = true;
				//system("cls");
				Clear();
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

void Player::PrintPokemon()
{
	for (int i = 0; i < 6; i++) {
		switch (i)
		{
		case 0:
			if (pokemonList[i] != NULL) {
				_setmode(_fileno(stdout), _O_U8TEXT);
				Gotoxy(70, 1);
				for (int v = 0; v < 7; v++) {
					for (int h = 0; h < 14; h++) {
						wcout << pokemonList[i]->frontImage[v][h];
					}
					Gotoxy(70, 2 + v);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Gotoxy(70, 9);
				cout << pokemonList[i]->GetName();
			}
			break;
		case 1:
			if (pokemonList[i] != NULL) {
				_setmode(_fileno(stdout), _O_U8TEXT);
				Gotoxy(100, 1);
				for (int v = 0; v < 7; v++) {
					for (int h = 0; h < 14; h++) {
						wcout << pokemonList[i]->frontImage[v][h];
					}
					Gotoxy(100, 2 + v);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Gotoxy(100, 9);
				cout << pokemonList[i]->GetName();
			}
			break;
		case 2:
			if (pokemonList[i] != NULL) {
				_setmode(_fileno(stdout), _O_U8TEXT);
				Gotoxy(70, 11);
				for (int v = 0; v < 7; v++) {
					for (int h = 0; h < 14; h++) {
						wcout << pokemonList[i]->frontImage[v][h];
					}
					Gotoxy(70, 12 + v);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Gotoxy(70, 19);
				cout << pokemonList[i]->GetName();
			}
			break;
		case 3:
			if (pokemonList[i] != NULL) {
				_setmode(_fileno(stdout), _O_U8TEXT);
				Gotoxy(100, 11);
				for (int v = 0; v < 7; v++) {
					for (int h = 0; h < 14; h++) {
						wcout << pokemonList[i]->frontImage[v][h];
					}
					Gotoxy(100, 12 + v);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Gotoxy(100, 19);
				cout << pokemonList[i]->GetName();
			}
			break;
		case 4:
			if (pokemonList[i] != NULL) {
				_setmode(_fileno(stdout), _O_U8TEXT);
				Gotoxy(70, 21);
				for (int v = 0; v < 7; v++) {
					for (int h = 0; h < 14; h++) {
						wcout << pokemonList[i]->frontImage[v][h];
					}
					Gotoxy(70, 22 + v);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Gotoxy(70, 29);
				cout << pokemonList[i]->GetName();
			}
			break;
		case 5:
			if (pokemonList[i] != NULL) {
				_setmode(_fileno(stdout), _O_U8TEXT);
				Gotoxy(100, 21);
				for (int v = 0; v < 7; v++) {
					for (int h = 0; h < 14; h++) {
						wcout << pokemonList[i]->frontImage[v][h];
					}
					Gotoxy(100, 22 + v);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Gotoxy(100, 29);
				cout << pokemonList[i]->GetName();
			}
			break;
		default:
			break;
		}
	}
	_setmode(_fileno(stdout), _O_TEXT);
}
