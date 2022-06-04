#include "Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"
#include"Player.h"
#include"Console.h"

using namespace std;

void Battle::Update(Player player) {
	CreatePokemon();
	PrintBattleScreen();
	PrintPokemon(player);

	_getch();
}

void Battle::CreatePokemon() {
	int percent = Random();
	if (percent < 1) { // 기라티나
		wildPokemon = new Giratina();
	}
	else if (percent < 10) {
		percent = Random();
		if (percent < 33) { // 모부기
			wildPokemon = new Turtwig();
		}
		else if (percent < 66) { // 팽도리
			wildPokemon = new Piplup();
		}
		else { // 불꽃숭이
			wildPokemon = new Chimchar();
		}
	}
	else if (percent < 30) { // 피카츄
		wildPokemon = new Pikachu();
	}
	else if (percent < 60) { // 딥상어동
		wildPokemon = new Gible();
	}
	else { // 찌르꼬
		wildPokemon = new Starly();
	}
}

void Battle::PrintBattleScreen() {
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■■■■■■■■■■■■■                                ■" << endl;
	cout << "■                        ■                              ■" << endl;
	cout << "■                          ■                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■                          ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                ■■■■■■■■■■■■■" << endl; // 10
	cout << "■                              ■                        ■" << endl;
	cout << "■                            ■                          ■" << endl;
	cout << "■                          ■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                        ■" << endl; // 14
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}

void Battle::PrintPokemon(Player player) {
	Gotoxy(2, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << player.ReturnPokemon()->backImage[i][j]; // 이상게 출략되면서 중단됨
		}
		Gotoxy(2, 7 + i + 1);
	}

	Gotoxy(40, 2);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << wildPokemon->frontImage[i][j]; // 이상게 출략되면서 중단됨
		}
		Gotoxy(40, i + 3);
	}
	_setmode(_fileno(stdout), _O_TEXT);
}

Battle::~Battle()
{
	delete wildPokemon;
}
