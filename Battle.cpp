#include"Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"
#include"Player.h"
#include"Console.h"
#include<math.h>

using namespace std;

void Battle::Update(Player player) {
	CreatePokemon(player);
	MoveCursor(player);

	/*Gotoxy(61, 0);
	system("pause");*/
	//_getch();
}

void Battle::CreatePokemon(Player player) {
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
		PrintBattleScreen();
		PrintPokemon(player);
		PrintPokemonHp(player);
		PrintPokemonName(player);
		PrintText(player);
		PrintCursor();
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
	Gotoxy(4, 16);
	for (int i = 0; i < 6; i++) {
		if (player.pokemonList[i] != NULL) {
			cout << "⊙  ";
		}
		else {
			cout << "○  ";
		}
	}

	Gotoxy(6, 19);
	cout << player.FirstPokemon()->GetName() << "은(는)";
	Gotoxy(6, 20);
	cout << "무엇을 할까?";

	Gotoxy(34, 20);
	cout << "배틀"; // 1
	
	Gotoxy(48, 20);
	cout << "가방"; // 2

	Gotoxy(34, 24);
	cout << "포켓몬"; // 3

	Gotoxy(48, 24);
	cout << "도망"; // 4
}

void Battle::MoveCursor(Player player)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		switch (_pos.pos)
		{
		case ONE:
			break;
		case TWO:
			break;
		case THREE:
			DeleteCursor();
			_pos.pos = ONE;
			PrintCursor();
			break;
		case FOUR:
			DeleteCursor();
			_pos.pos = TWO;
			PrintCursor();
			break;
		default:
			break;
		}
		/*PrintBattleScreen();
		PrintPokemon(player);
		PrintPokemonHp(player);
		PrintPokemonName(player);
		PrintText(player);*/
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		switch (_pos.pos)
		{
		case ONE:
			DeleteCursor();
			_pos.pos = THREE;
			PrintCursor();
			break;
		case TWO:
			DeleteCursor();
			_pos.pos = FOUR;
			PrintCursor();
			break;
		case THREE:
			break;
		case FOUR:
			break;
		default:
			break;
		}
		/*PrintBattleScreen();
		PrintPokemon(player);
		PrintPokemonHp(player);
		PrintPokemonName(player);
		PrintText(player);*/
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		
		switch (_pos.pos)
		{
		case ONE:
			break;
		case TWO:
			DeleteCursor();
			_pos.pos = ONE;
			PrintCursor();
			break;
		case THREE:
			break;
		case FOUR:
			DeleteCursor();
			_pos.pos = THREE;
			PrintCursor();
			break;
		default:
			break;
		}
		/*PrintBattleScreen();
		PrintPokemon(player);
		PrintPokemonHp(player);
		PrintPokemonName(player);
		PrintText(player);*/
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		switch (_pos.pos)
		{
		case ONE:
			DeleteCursor();
			_pos.pos = TWO;
			PrintCursor();
			break;
		case TWO:
			break;
		case THREE:
			DeleteCursor();
			_pos.pos = FOUR;
			PrintCursor();
			break;
		case FOUR:
			break;
		default:
			break;
		}
		/*PrintBattleScreen();
		PrintPokemon(player);
		PrintPokemonHp(player);
		PrintPokemonName(player);
		PrintText(player);*/
	}
}

void Battle::PrintCursor()
{
	switch (_pos.pos)
	{
	case ONE:
		Gotoxy(30, 20);
		break;
	case TWO:
		Gotoxy(44, 20);
		break;
	case THREE:
		Gotoxy(30, 24);
		break;
	case FOUR:
		Gotoxy(44, 24);
		break;
	default:
		break;
	}
	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"▶";
	_setmode(_fileno(stdout), _O_TEXT);
}

void Battle::DeleteCursor()
{
	switch (_pos.pos)
	{
	case ONE:
		Gotoxy(30, 20);
		break;
	case TWO:
		Gotoxy(44, 20);
		break;
	case THREE:
		Gotoxy(30, 24);
		break;
	case FOUR:
		Gotoxy(44, 24);
		break;
	default:
		break;
	}
	cout << "  ";
}

Battle::Battle()
{
	_pos.pos = 1;
}

Battle::~Battle()
{
	delete wildPokemon;
}