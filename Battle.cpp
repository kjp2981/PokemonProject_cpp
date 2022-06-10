#include"Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"
#include"Player.h"
#include"Console.h"
#include<math.h>
#include"Map.h"
#include<WindowsX.h>

using namespace std;

void Battle::Update() {
	CreatePokemon();
	//if (isTurn) {
	//	MoveCursor();
	//	Input();
	//}
	//else {
	//	// TODO : 적의 차례
	//}
	MoveCursor();
	Input();

	/*Gotoxy(61, 0);
	system("pause");*/
	//_getch();
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
		PrintBattleScreen();
		PrintPokemon();
		PrintPokemonHp();
		PrintPokemonName();
		PrintText();
		PrintCursor();
	}
}

void Battle::AllPrint()
{
	system("cls");
	PrintBattleScreen();
	PrintPokemon();
	PrintPokemonHp();
	PrintPokemonName();
	PrintText();
	PrintCursor();
}

void Battle::PrintBattleScreen() { // 세로는 0부터 시작, 가로는 1부터 시작 2씩 카운트 해야함
	Gotoxy(0, 0);
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

void Battle::PrintPokemon() {
	Gotoxy(5, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) { // 플레이어의 포켓몬 출력
		for (int j = 0; j < 14; j++) {
			if (player->FirstPokemon()->backImage[i][j] != '0')
				wcout << player->FirstPokemon()->backImage[i][j]; // 이상게 출략되면서 중단됨
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

void Battle::PrintPokemonHp()
{
	SetColor(4, 0);
	Gotoxy(4, 4);
	int hpBar = HP_BAR * (wildPokemon->GetHP() / wildPokemon->GetMaxHP());
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < hpBar; i++) {
		wcout << L"■";
	}
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		cout << "  ";
	}
	
	hpBar = HP_BAR * (player->FirstPokemon()->GetHP() / player->FirstPokemon()->GetMaxHP());
	Gotoxy(36, 12);
	for (int i = 0; i < hpBar; i++) {
		wcout << L"■";
	}
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		cout << "  ";
	}

	_setmode(_fileno(stdout), _O_TEXT);
	SetColor(15, 0);
	
}

void Battle::PrintPokemonName()
{
	Gotoxy(4, 3);
	cout << wildPokemon->GetName();

	Gotoxy(36, 11);
	cout << player->FirstPokemon()->GetName();
}

void Battle::PrintText()
{
	Gotoxy(4, 16);
	for (int i = 0; i < 6; i++) {
		if (player->pokemonList[i] != NULL) {
			cout << "⊙  ";
		}
		else {
			cout << "○  ";
		}
	}

	Clear(2, 16, 58, 28);

	Gotoxy(6, 19);
	cout << player->FirstPokemon()->GetName() << "은(는)";
	Gotoxy(6, 20);
	cout << "무엇을 할까?";

	if (input == E_Choice) {
		Gotoxy(36, 18);
		cout << "배틀"; // 1

		Gotoxy(48, 18);
		cout << "가방"; // 2

		Gotoxy(36, 22);
		cout << "포켓몬"; // 3

		Gotoxy(48, 22);
		cout << "도망"; // 4
	}
	else if (input == E_Skill) {
		// TODO : 기술 리스트 출력
		Gotoxy(36, 18);
		cout << player->FirstPokemon()->skiiList[0]->name;

		Gotoxy(48, 18);
		cout << player->FirstPokemon()->skiiList[1]->name;

		Gotoxy(36, 22);
		cout << player->FirstPokemon()->skiiList[2]->name;

		Gotoxy(48, 22);
		cout << player->FirstPokemon()->skiiList[3]->name;
	}
	else if (input == E_Item) {
		// TODO : 아이템 리스트 출력
		Gotoxy(36, 18);
		cout << "상처약 x " << player->bag->medicineCnt;

		Gotoxy(36, 22);
		cout << "몬스터 볼 x " << player->bag->monsterballCnt;
	}
	else if (input == E_Pokemon) {
		// TODO : 포켓몬 리스트 출력
		Gotoxy(36, 18);
		cout << player->pokemonList[0]->GetName();

		Gotoxy(48, 18);
		cout << player->pokemonList[1]->GetName();

		Gotoxy(36, 22);
		cout << player->pokemonList[2]->GetName();

		Gotoxy(48, 22);
		cout << player->pokemonList[3]->GetName();

		Gotoxy(36, 26);
		cout << player->pokemonList[4]->GetName();

		Gotoxy(48, 26);
		cout << player->pokemonList[5]->GetName();
	}
	PrintCursor();
}

void Battle::MoveCursor()
{
	if (input == E_Choice) {
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
		}
	}
	else if (input == E_Skill) {
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
		}
	}
	else if (input == E_Item) { // ONE and THREE
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			switch (_pos.pos)
			{
			case ONE:
				break;
			case THREE:
			case FOUR:
				DeleteCursor();
				_pos.pos = ONE;
				PrintCursor();
				break;
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			switch (_pos.pos)
			{
			case ONE:
			case TWO:
				DeleteCursor();
				_pos.pos = THREE;
				PrintCursor();
				break;
			case THREE:
				break;
			default:
				break;
			}
		}
	}
	else if (input == E_Pokemon) {
		
	}
}

void Battle::PrintCursor()
{
	if (input == E_Choice) {
		switch (_pos.pos)
		{
		case ONE:
			Gotoxy(34, 18);
			break;
		case TWO:
			Gotoxy(46, 18);
			break;
		case THREE:
			Gotoxy(34, 22);
			break;
		case FOUR:
			Gotoxy(46, 22);
			break;
		default:
			break;
		}
	}
	else if (input == E_Skill) {
		switch (_pos.pos)
		{
		case ONE:
			Gotoxy(34, 18);
			break;
		case TWO:
			Gotoxy(46, 18);
			break;
		case THREE:
			Gotoxy(34, 22);
			break;
		case FOUR:
			Gotoxy(46, 22);
			break;
		default:
			break;
		}
	}
	else if (input == E_Item) {
		switch (_pos.pos)
		{
		case ONE:
		case TWO:
			Gotoxy(34, 18);
			break;
		case THREE:
		case FOUR:
			Gotoxy(34, 22);
			break;
		default:
			break;
		}
	}
	else if (input == E_Pokemon) {
		switch (_pos.pos)
		{
		case ONE:
			Gotoxy(34, 18);
			break;
		case TWO:
			Gotoxy(46, 18);
			break;
		case THREE:
			Gotoxy(34, 22);
			break;
		case FOUR:
			Gotoxy(46, 22);
			break;
		case FIVE:
			Gotoxy(34, 26);
			break;
		case SIX:
			Gotoxy(46, 26);
			break;
		default:
			break;
		}
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
		Gotoxy(34, 18);
		break;
	case TWO:
		Gotoxy(46, 18);
		break;
	case THREE:
		Gotoxy(34, 22);
		break;
	case FOUR:
		Gotoxy(46, 22);
		break;
	case FIVE:
		Gotoxy(34, 26);
		break;
	case SIX:
		Gotoxy(46, 26);
		break;
	default:
		break;
	}
	cout << "  ";
}

void Battle::SetTurn()
{
	isTurn = player->FirstPokemon()->GetSpeed() < wildPokemon->GetSpeed()
		? wildPokemon->GetSpeed()
		: player->FirstPokemon()->GetSpeed();
}

void Battle::Input()
{
	if (input == 0) {
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			if (isInput) return;
			switch (_pos.pos) {
			case ONE:
				// TODO : 배틀하기
				input = 1;
				PrintText();
				IgnoreInput();
				break;
			case TWO:
				// TODO : 가방(아이템 리스트 출력하기)
				//Clear();
				input = 2;
				PrintText();
				break;
			case THREE:
				// TODO : 포켓몬 교체(포켓몬 리스트 출력하기)
				input = 3;
				PrintText();
				break;
			case FOUR:
				// TODO : 도망치기
				player->isBattle = false;
				delete wildPokemon;
				wildPokemon = nullptr;
				input = 0;
				Clear();
				// 맵을 출력시키기
				break;
			}
		}
	}
	else if (input == 1) { // 스킬 리스트
		// TODO : 스킬 사용(Damage주기)
		Sleep(100);
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			if (isInput) return;
			switch (_pos.pos)
			{
			case ONE:
				Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "은(는)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[0]->name << "을 사용했다.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[0]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : 돈 받기
					Clear();
					// 맵을 출력시키기
					break;
				}
				Sleep(1000);
				::system("cls");
				AllPrint();
				input = 0;
				PrintText();
				break;
			case TWO:
				Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "은(는)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[1]->name << "을 사용했다.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[1]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : 돈 받기
					Clear();
					// 맵을 출력시키기
					break;
				}
				Sleep(1000);
				::system("cls");
				AllPrint();
				input = 0;
				PrintText();
				break;
			case THREE:
				Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "은(는)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[2]->name << "을 사용했다.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[2]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : 돈 받기
					Clear();
					// 맵을 출력시키기
					break;
				}
				Sleep(1000);
				::system("cls");
				AllPrint();
				input = 0;
				PrintText();
				break;
			case FOUR:
				Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "은(는)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[3]->name << "을 사용했다.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[3]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : 돈 받기
					Clear();
					// 맵을 출력시키기
					break;
				}
				Sleep(1000);
				::system("cls");
				AllPrint();
				input = 0;
				PrintText();
				break;
			default:
				break;
			}
		}
	}
	else if (input == 2) { // 아이템 사용
		if (isInput) return;
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos)
			{
			case ONE:
				break;
			case TWO:
				break;
			case THREE:
				break;
			case FOUR:
				break;
			default:
				break;
			}
		}
	}
	else if (input == 3) { // 포켓몬 교체
		if (isInput) return;
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos)
			{
			case ONE:
				if (fIdx == -1) {
					fIdx = ONE - 1;
				}
				else if (sIdx == -1) {
					sIdx = ONE - 1;
					player->SwapPokemon(fIdx, sIdx);
					fIdx = sIdx = -1;
					input = 0;
				}
				break;
			case TWO:
				if (fIdx == -1) {
					fIdx = TWO - 1;
				}
				else if (sIdx == -1) {
					sIdx = TWO - 1;
					player->SwapPokemon(fIdx, sIdx);
					fIdx = sIdx = -1;
					input = 0;
				}
				break;
			case THREE:
				if (fIdx == -1) {
					fIdx = THREE - 1;
				}
				else if (sIdx == -1) {
					sIdx = THREE - 1;
					player->SwapPokemon(fIdx, sIdx);
					fIdx = sIdx = -1;
					input = 0;
				}
				break;
			case FOUR:
				if (fIdx == -1) {
					fIdx = FOUR - 1;
				}
				else if (sIdx == -1) {
					sIdx = FOUR - 1;
					player->SwapPokemon(fIdx, sIdx);
					fIdx = sIdx = -1;
					input = 0;
				}
				break;
			case FIVE:
				if (fIdx == -1) {
					fIdx = ONE - 1;
				}
				else if (sIdx == -1) {
					sIdx = ONE - 1;
					player->SwapPokemon(fIdx, sIdx);
					fIdx = sIdx = -1;
					input = 0;
				}
				break;
			case SIX:
				if (fIdx == -1) {
					fIdx = ONE - 1;
				}
				else if (sIdx == -1) {
					sIdx = ONE - 1;
					player->SwapPokemon(fIdx, sIdx);
					fIdx = sIdx = -1;
					input = 0;
				}
				break;
			default:
				break;
			}
		}
	}
}

void Battle::IgnoreInput()
{
	isInput = true;
	Sleep(1000);
	isInput = false;
	isTurn = true;
	fIdx = -1;
	sIdx = -1;
}

//void Battle::SetPlayer(Player* player)
//{
//	this->player = player;
//}

//void Battle::MouseClick()
//{
//	INPUT_RECORD rec;
//	DWORD dwRead;
//
//	HANDLE hCout = GetStdHandle(STD_OUTPUT_HANDLE);
//	HANDLE hCin = GetStdHandle(STD_INPUT_HANDLE);
//
//	if (ReadConsoleInput(hCin, &rec, 1, &dwRead)) {
//		if (rec.EventType == MOUSE_EVENT) {
//			if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
//				// 클릭된 곳이 텍스트면 텍스트에 맞는 행동하기
//			}
//		}
//	}
//}

Battle::Battle(Player* player, Map* map) : player(player), map(map)
{
	wildPokemon = nullptr;
	_pos.pos = 1;
	input = 0;
	isInput = false;
	isTurn = false;
}

Battle::~Battle()
{
	if (wildPokemon != NULL)
	{
		delete wildPokemon;
	}
}