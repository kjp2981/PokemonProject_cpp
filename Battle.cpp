#include "Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"
#include"Player.h"
#include"Console.h"

using namespace std;

void Battle::Update(Player player) {
	PrintBattleScreen();
	PrintPokemon(player);
}

void Battle::CreatePokemon() {
	int percent = Random();
	if (percent < 1) { // ±â¶óÆ¼³ª
		wildPokemon = new Giratina();
	}
	else if (percent < 10) {
		percent = Random();
		if (percent < 33) { // ¸ðºÎ±â
			wildPokemon = new Turtwig();
		}
		else if (percent < 66) { // ÆØµµ¸®
			wildPokemon = new Piplup();
		}
		else { // ºÒ²É¼þÀÌ
			wildPokemon = new Chimchar();
		}
	}
	else if (percent < 30) { // ÇÇÄ«Ãò
		wildPokemon = new Pikachu();
	}
	else if (percent < 60) { // µö»ó¾îµ¿
		wildPokemon = new Gible();
	}
	else { // Âî¸£²¿
		wildPokemon = new Starly();
	}
}

void Battle::PrintBattleScreen() {
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á                                ¡á" << endl;
	cout << "¡á                        ¡á                              ¡á" << endl;
	cout << "¡á                          ¡á                            ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á                          ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl; // 10
	cout << "¡á                              ¡á                        ¡á" << endl;
	cout << "¡á                            ¡á                          ¡á" << endl;
	cout << "¡á                          ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á                                                        ¡á" << endl; // 14
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á                                                        ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
}

void Battle::PrintPokemon(Player player) {
	Gotoxy(1, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << player.ReturnPokemon()->backImage[i][j]; // ÀÌ»ó°Ô Ãâ·«µÇ¸é¼­ Áß´ÜµÊ
		}
		cout << endl;
	}
	_setmode(_fileno(stdout), _O_TEXT);
}
