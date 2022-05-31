#include "Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"

using namespace std;

void Battle::Update() {
	PrintBattleScreen();
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
