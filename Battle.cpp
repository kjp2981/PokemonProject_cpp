#include"Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"
#include"Player.h"
#include"Console.h"
#include<math.h>

using namespace std;

void Battle::Update(Player player) {
	CreatePokemon();
	PrintBattleScreen();
	PrintPokemon(player);
	PrintPokemonHp(player);
	PrintPokemonName(player);
	PrintText(player);

	Gotoxy(0, 30);
	system("pause");
}

void Battle::CreatePokemon() {
	if (wildPokemon == nullptr) {
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
}

void Battle::PrintBattleScreen() { // 세로는 0부터 시작, 가로는 1부터 시작 2씩 카운트 해야함
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
	Gotoxy(5, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) { // 플레이어의 포켓몬 출력
		for (int j = 0; j < 14; j++) {
			if (player.FirstPokemon()->backImage[i][j] != '0')
				wcout << player.FirstPokemon()->backImage[i][j]; // 이상게 출략되면서 중단됨
		}
		Gotoxy(5, 7 + i + 1);
	}

	Gotoxy(40, 2);
	for (int i = 0; i < 7; i++) { // 야생 포켓몬 출력
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << wildPokemon->frontImage[i][j]; // 이상게 출략되면서 중단됨
		}
		Gotoxy(40, i + 3);
	}
	_setmode(_fileno(stdout), _O_TEXT);
}

void Battle::PrintPokemonHp(Player player)
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetColor(4, 0);
	Gotoxy(4, 4);
	int hp = HP_BAR * (wildPokemon->GetHP() / wildPokemon->GetMaxHP());
	for (int i = 0; i < hp; i++) {
		wcout << L"■";
	}
	for (int i = 0; i < HP_BAR - hp; i++) {
		cout << "  ";
	}
	
	hp = HP_BAR * (player.FirstPokemon()->GetHP() / player.FirstPokemon()->GetMaxHP());
	Gotoxy(36, 12);
	for (int i = 0; i < hp; i++) {
		wcout << L"■";
	}
	for (int i = 0; i < HP_BAR - hp; i++) {
		cout << "  ";
	}

	SetColor(15, 0);
	_setmode(_fileno(stdout), _O_TEXT);
}

void Battle::PrintPokemonName(Player player)
{
	Gotoxy(4, 3);
	cout << wildPokemon->GetName();

	Gotoxy(36, 11);
	cout << player.FirstPokemon()->GetName();
}

void Battle::PrintText(Player player)
{
	Gotoxy(3, 16);
	for (int i = 0; i < 6; i++) {
		if (player.pokemonList[i] != NULL) {
			cout << "⊙  ";
		}
		else {
			cout << "○  ";
		}
	}
}

Battle::~Battle()
{
	delete wildPokemon;
}
