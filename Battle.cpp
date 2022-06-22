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
	if (isTurn) {
		MoveCursor();
		Input();
		if (GetAsyncKeyState(VK_BACK) || GetAsyncKeyState(VK_ESCAPE)) {
			if (input != 0) {
				input = 0;
				AllPrint();
			}
		}
	}
	else {
		// TODO : 적의 차례
		//Clear(30, 16, 58, 28);
		system("cls");
		PrintBattleScreen();
		PrintPokemon();
		PrintPokemonHp();
		PrintPokemonName();
		Gotoxy(6, 19);
		cout << "야생 " << wildPokemon->GetName() << "은(는)";
		Gotoxy(6, 20);
		cout << "무엇을 할까?";
		Sleep(1000);
		EnemyAttack();
	}
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
		PrintBattleStartAnim();
		SetTurn();
		if(isTurn == true)
			AllPrint();
	}
}

void Battle::PrintBattleStartAnim()
{
	for (int k = 0; k < 2; k++) {
		Gotoxy(0, 0);
		SetColor(0, 15);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				cout << "  ";
			}
			cout << endl;
		}
		Sleep(20);
		Gotoxy(0, 0);
		SetColor(15, 0);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				cout << "  ";
			}
			cout << endl;
		}
		Sleep(20);
	}

	SetColor(0, 15);
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j += 2) {
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < 30; j += 2) {
			Gotoxy(58 - i * 2, j);
			cout << "  ";
		}
		Sleep(20);
	}
	SetColor(15, 0);
	//Sleep(3000);
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
				wcout << player->FirstPokemon()->backImage[i][j];
		}
		Gotoxy(5, 7 + i + 1);
	}

	Gotoxy(40, 2);
	for (int i = 0; i < 7; i++) { // 야생 포켓몬 출력
		for (int j = 0; j < 14; j++) {
			if (wildPokemon->frontImage[i][j] != '0')
				wcout << wildPokemon->frontImage[i][j];
		}
		Gotoxy(40, i + 3);
	}
	_setmode(_fileno(stdout), _O_TEXT);
}

void Battle::PrintPokemonHp()
{
	SetColor(4, 0);
	Gotoxy(4, 4);
	float currentHp = (float)wildPokemon->GetHP() / (float)wildPokemon->GetMaxHP();
	float hpBar = HP_BAR * currentHp;
	hpBar = ceil(hpBar);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < hpBar; i++) {
		wcout << L"■";
		//cout << "■";
	}
	//_setmode(_fileno(stdout), _O_TEXT);
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		wcout << L"  ";
	}
	
	currentHp = (float)player->FirstPokemon()->GetHP() / (float)player->FirstPokemon()->GetMaxHP();
	hpBar = HP_BAR * currentHp;
	hpBar = ceil(hpBar);
	Gotoxy(36, 12);
	//_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < hpBar; i++) {
		wcout << L"■";
//		cout << "■";

	}
	//_setmode(_fileno(stdout), _O_TEXT);
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		wcout << L"  ";
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
		//cout << "점검 중!"; // 3

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
		cout << "상처약 x " << player->bag->GetItemCount(I_Medicine);

		Gotoxy(36, 22);
		cout << "몬스터 볼 x " << player->bag->GetItemCount(I_Monsterball);
	}
	else if (input == E_Pokemon) {
		// TODO : 포켓몬 리스트 출력
		Gotoxy(36, 18);
		if (player->pokemonList[0] != NULL)
			cout << player->pokemonList[0]->GetName();

		Gotoxy(48, 18);
		if (player->pokemonList[1] != NULL)
			cout << player->pokemonList[1]->GetName();

		Gotoxy(36, 22);
		if (player->pokemonList[2] != NULL)
			cout << player->pokemonList[2]->GetName();

		Gotoxy(48, 22);
		if (player->pokemonList[3] != NULL)
			cout << player->pokemonList[3]->GetName();

		Gotoxy(36, 26);
		if (player->pokemonList[4] != NULL)
			cout << player->pokemonList[4]->GetName();

		Gotoxy(48, 26);
		if (player->pokemonList[5] != NULL)
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
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			switch (_pos.pos)
			{
			case ONE:
				break;
			case TWO:
				break;
			case THREE:
				if (player->pokemonList[ONE - 1] != NULL) {
					DeleteCursor();
					_pos.pos = ONE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case FOUR:
				if (player->pokemonList[TWO - 1] != NULL) {
					DeleteCursor();
					_pos.pos = TWO;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case FIVE:
				if (player->pokemonList[THREE - 1] != NULL) {
					DeleteCursor();
					_pos.pos = THREE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case SIX:
				if (player->pokemonList[SIX - 1] != NULL) {
					DeleteCursor();
					_pos.pos = FOUR;
					PrintCursor();
					IgnoreInput();
				}
				break;
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			switch (_pos.pos)
			{
			case ONE:
				if (player->pokemonList[THREE - 1] != NULL) {
					DeleteCursor();
					_pos.pos = THREE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case TWO:
				if (player->pokemonList[FOUR - 1] != NULL) {
					DeleteCursor();
					_pos.pos = FOUR;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case THREE:
				if (player->pokemonList[FIVE - 1] != NULL) {
					DeleteCursor();
					_pos.pos = FIVE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case FOUR:
				if (player->pokemonList[SIX - 1] != NULL) {
					DeleteCursor();
					_pos.pos = SIX;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case FIVE:
				break;
			case SIX:
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
				if (player->pokemonList[ONE - 1] != NULL) {
					DeleteCursor();
					_pos.pos = ONE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case THREE:
				break;
			case FOUR:
				if (player->pokemonList[THREE - 1] != NULL) {
					DeleteCursor();
					_pos.pos = THREE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case FIVE:
				break;
			case SIX:
				if (player->pokemonList[SIX - 1] != NULL) {
					DeleteCursor();
					_pos.pos = FIVE;
					PrintCursor();
					IgnoreInput();
				}
				break;
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			switch (_pos.pos)
			{
			case ONE:
				if (player->pokemonList[TWO - 1] != NULL) {
					DeleteCursor();
					_pos.pos = TWO;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case TWO:
				break;
			case THREE:
				if (player->pokemonList[FOUR - 1] != NULL) {
					DeleteCursor();
					_pos.pos = FOUR;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case FOUR:
				break;
			case FIVE:
				if (player->pokemonList[SIX - 1] != NULL) {
					DeleteCursor();
					_pos.pos = SIX;
					PrintCursor();
					IgnoreInput();
				}
				break;
			case SIX:
				break;
			default:
				break;
			}
		}
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
	isTurn = player->FirstPokemon()->GetSpeed() < wildPokemon->GetSpeed() ? false : true;
}

void Battle::EnemyAttack()
{
	int randomSkill = rand() % 4;
	int rate = wildPokemon->skiiList[randomSkill]->accuracyRate;
	int random = Random();
	if (random < rate) {
		Gotoxy(6, 19);
		cout << "야생 " << wildPokemon->GetName() << "은(는)";
		Gotoxy(6, 20);
		cout << wildPokemon->skiiList[randomSkill]->name << "을 사용했다.";
		player->FirstPokemon()->Damage(wildPokemon->skiiList[randomSkill]->damage, wildPokemon->skiiList[randomSkill]->type, wildPokemon->skiiList[randomSkill]->type == wildPokemon->GetType());
		if (player->FirstPokemon()->GetHP() <= 0) {
			// 월래 있던 텍스트 지우기
			Clear(4, 17, 30, 28);
			Gotoxy(6, 19);
			cout << player->FirstPokemon()->GetName() << "은(는)";
			Gotoxy(6, 20);
			cout << "쓰러졌다!";
			Sleep(1000);
			if (player->pokemonList[1] == NULL) {
				delete wildPokemon;
				wildPokemon = nullptr;
				player->isBattle = false;
				system("cls");
				map->PrintMap(map->map, &player->pos);
			}
			else if (player->pokemonList[1] != NULL) {
				int pokemonIdx = 1;
				for (int i = 1; i < 6; i++) {
					if (player->pokemonList[i]->GetHP() > 0) {
						pokemonIdx = i;
						break;
					}
				}
				player->SwapPokemon(0, pokemonIdx); // 여기 수정

			}
			return;
		}
	}
	else {
		Clear(4, 17, 30, 28);
		Gotoxy(6, 19);
		cout << "공격이";
		Gotoxy(6, 20);
		cout << "빗나갔다.";
	}
	isTurn = !isTurn;
	Sleep(1000);
	::system("cls");
	AllPrint();
	PrintText();
}

void Battle::Input()
{
	if (input == E_Choice) {
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
				DeleteCursor();
				_pos.pos = ONE;
				PrintCursor();
				PrintText();
				IgnoreInput();
				break;
			case THREE:
				// TODO : 포켓몬 교체(포켓몬 리스트 출력하기)
				input = 3;
				DeleteCursor();
				_pos.pos = ONE;
				PrintCursor();
				PrintText();
				IgnoreInput();
				break;
			case FOUR:
				// TODO : 도망치기
				player->isBattle = false;
				
				input = 0;
				Gotoxy(6, 19);
				cout << "야생 " << wildPokemon->GetName() << "에게서";
				Gotoxy(6, 20);
				cout << "무사히 도망쳤다.";
				delete wildPokemon;
				wildPokemon = nullptr;
				Sleep(1000);
				system("cls");
				map->PrintMap(map->map, &player->pos);
				break;
			}
		}
	}
	else if (input == E_Skill) { // 스킬 리스트
		// TODO : 스킬 사용(Damage주기)
		//Sleep(100);
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			if (isInput) return;
			switch (_pos.pos)
			{
			case ONE:
			{
				int rate = player->FirstPokemon()->skiiList[0]->accuracyRate;
				int random = Random();
				if (random < rate) {
					Gotoxy(6, 19);
					cout << player->FirstPokemon()->GetName() << "은(는)";
					Gotoxy(6, 20);
					cout << player->FirstPokemon()->skiiList[0]->name << "을 사용했다.";
					wildPokemon->Damage(player->FirstPokemon()->skiiList[0]->damage, player->FirstPokemon()->skiiList[0]->type, player->FirstPokemon()->skiiList[0]->type == player->FirstPokemon()->GetType());
					if (wildPokemon->GetHP() <= 0) {
						Clear(4, 17, 30, 28);
						Gotoxy(6, 19);
						cout << "야생 " << wildPokemon->GetName() << "은(는)";
						Gotoxy(6, 20);
						cout << "쓰러졌다!";
						player->bag->AddItem(I_Gold, 1000);
						Sleep(1000);
						player->isBattle = false;
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						system("cls");
						map->PrintMap(map->map, &player->pos);
						break;
					}
				}
				else {
					Clear(4, 17, 30, 28);
					Gotoxy(6, 19);
					cout << "공격이";
					Gotoxy(6, 20);
					cout << "빗나갔다.";
				}
				Sleep(1000);
				::system("cls");
				_pos.pos = ONE;
				input = 0;
				isTurn = !isTurn;
			}
				break;
			case TWO:
			{
				int rate = player->FirstPokemon()->skiiList[0]->accuracyRate;
				int random = Random();
				if (random < rate) {
					Gotoxy(6, 19);
					cout << player->FirstPokemon()->GetName() << "은(는)";
					Gotoxy(6, 20);
					cout << player->FirstPokemon()->skiiList[1]->name << "을 사용했다.";
					wildPokemon->Damage(player->FirstPokemon()->skiiList[1]->damage, player->FirstPokemon()->skiiList[1]->type, player->FirstPokemon()->skiiList[1]->type == player->FirstPokemon()->GetType());
					if (wildPokemon->GetHP() <= 0) {
						Clear(4, 17, 30, 28);
						Gotoxy(6, 19);
						cout << "야생 " << wildPokemon->GetName() << "은(는)";
						Gotoxy(6, 20);
						cout << "쓰러졌다!";
						player->bag->AddItem(I_Gold, 1000);
						Sleep(1000);
						player->isBattle = false;
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						system("cls");
						map->PrintMap(map->map, &player->pos);
						break;
					}
				}
				else {
					Clear(4, 17, 30, 28);
					Gotoxy(6, 19);
					cout << "공격이";
					Gotoxy(6, 20);
					cout << "빗나갔다.";
				}
				Sleep(1000);
				::system("cls");
				_pos.pos = ONE;
				input = 0;
				isTurn = !isTurn;
			}
				break;
			case THREE:
			{
				int rate = player->FirstPokemon()->skiiList[0]->accuracyRate;
				int random = Random();
				if (random < rate) {
					Gotoxy(6, 19);
					cout << player->FirstPokemon()->GetName() << "은(는)";
					Gotoxy(6, 20);
					cout << player->FirstPokemon()->skiiList[2]->name << "을 사용했다.";
					wildPokemon->Damage(player->FirstPokemon()->skiiList[2]->damage, player->FirstPokemon()->skiiList[2]->type, player->FirstPokemon()->skiiList[2]->type == player->FirstPokemon()->GetType());
					if (wildPokemon->GetHP() <= 0) {
						Clear(4, 17, 30, 28);
						Gotoxy(6, 19);
						cout << "야생 " << wildPokemon->GetName() << "은(는)";
						Gotoxy(6, 20);
						cout << "쓰러졌다!";
						player->bag->AddItem(I_Gold, 1000);
						Sleep(1000);
						player->isBattle = false;
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						system("cls");
						map->PrintMap(map->map, &player->pos);
						break;
					}
				}
				else {
					Clear(4, 17, 30, 28);
					Gotoxy(6, 19);
					cout << "공격이";
					Gotoxy(6, 20);
					cout << "빗나갔다.";
				}
				Sleep(1000);
				::system("cls");
				_pos.pos = ONE;
				input = 0;
				isTurn = !isTurn;
			}
				break;
			case FOUR:
			{
				int rate = player->FirstPokemon()->skiiList[0]->accuracyRate;
				int random = Random();
				if (random < rate) {
					Gotoxy(6, 19);
					cout << player->FirstPokemon()->GetName() << "은(는)";
					Gotoxy(6, 20);
					cout << player->FirstPokemon()->skiiList[3]->name << "을 사용했다.";
					wildPokemon->Damage(player->FirstPokemon()->skiiList[3]->damage, player->FirstPokemon()->skiiList[3]->type, player->FirstPokemon()->skiiList[3]->type == player->FirstPokemon()->GetType());
					if (wildPokemon->GetHP() <= 0) {
						Clear(4, 17, 30, 28);
						Gotoxy(6, 19);
						cout << "야생 " << wildPokemon->GetName() << "은(는)";
						Gotoxy(6, 20);
						cout << "쓰러졌다!";
						player->bag->AddItem(I_Gold, 1000);
						Sleep(1000);
						player->isBattle = false;
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						system("cls");
						map->PrintMap(map->map, &player->pos);
						break;
					}
				}
				else {
					Clear(4, 17, 30, 28);
					Gotoxy(6, 19);
					cout << "공격이";
					Gotoxy(6, 20);
					cout << "빗나갔다.";
				}
				Sleep(1000);
				::system("cls");
				_pos.pos = ONE;
				input = 0;
				isTurn = !isTurn;
			}
				break;
			default:
				break;
			}
		}
	}
	else if (input == E_Item) { // 아이템 사용
		if (isInput) return;
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos)
			{
			case ONE: // 상처약
				// TODO : 현재 포켓몬(배열의 0번쨰 포켓몬) 힐하기
				if (player->bag->IsUseItem(I_Medicine, 1)) {
					player->bag->UseItem(I_Medicine, 1);
					player->FirstPokemon()->Heal(10);
					Clear(2, 17, 26, 28);
					Gotoxy(6, 19);
					cout << player->FirstPokemon()->GetName() << "은(는)";
					Gotoxy(6, 20);
					cout << "상처약을 사용했다.";
					input = 0;
					Sleep(1000);
					isTurn = !isTurn;
				}
				else {
					Clear(2, 17, 26, 28);
					Gotoxy(6, 19);
					cout << "상처약이";
					Gotoxy(6, 20);
					cout << "없습니다.";
					Sleep(1000);
					isTurn = !isTurn;
				}
				break;
			case TWO:
				break;
			case THREE: // 몬스터볼
				// TODO : 몬스터볼 던지기
				// TODO : 야생포켓몬의 hp에 따라 잡기
				if (player->bag->IsUseItem(I_Monsterball, 1)) {
				player->bag->UseItem(I_Monsterball, 1);
				Clear(2, 17, 26, 28);
				Gotoxy(6, 19);
				cout << "몬스터볼을 사용했다.";
				Clear(40, 1, 56, 8);
				Gotoxy(40, 2);
				_setmode(_fileno(stdout), _O_U8TEXT);
				for (int i = 0; i < 5; i++) { // 야생 포켓몬 출력
					for (int j = 0; j < 11; j++) {
						if (monsterballImage[i][j] != '0')
							wcout << monsterballImage[i][j];
					}
					Gotoxy(40, i + 3);
				}
				_setmode(_fileno(stdout), _O_TEXT);
				Sleep(500);
				{
					int percent = 100 * ((float)wildPokemon->GetHP() / (float)wildPokemon->GetMaxHP());
					int rand = Random();
					if (rand > percent) {
						Clear(2, 17, 26, 28);
						Gotoxy(6, 19);
						cout << "신난다-!";
						Gotoxy(6, 20);
						cout << wildPokemon->GetName() << "를(을) 붙잡았다!";
						if (player->IsPokemonEmpty()) {
							player->pokemonList[player->EmptyPokemonIndex()] = wildPokemon;
						}
						else {
							// 포켓몬이 모두 차있다면 포켓몬 리스트를 띄우고 한마리를 버릴지 or 잠은 포켓몬을 포기할지 선택하게하기
							Clear(2, 17, 26, 28);
							Gotoxy(6, 19);
							cout << wildPokemon->GetName() << "은(는) 누군가의 PC";
							Gotoxy(6, 20);
							cout << "박스1로 전송되었다!";
						}
						input = 0;
						Sleep(1000);
						player->isBattle = false;
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						system("cls");
						map->PrintMap(map->map, &player->pos);
					}
					else {
						Clear(40, 1, 56, 8);
						Gotoxy(40, 2);
						_setmode(_fileno(stdout), _O_U8TEXT);
						for (int i = 0; i < 7; i++) { // 야생 포켓몬 출력
							for (int j = 0; j < 14; j++) {
								if (wildPokemon->frontImage[i][j] != '0')
									wcout << wildPokemon->frontImage[i][j];
							}
							Gotoxy(40, i + 3);
						}
						_setmode(_fileno(stdout), _O_TEXT);
						Clear(2, 17, 26, 28);
						Gotoxy(6, 19);
						cout << "아쉽다!";
						Gotoxy(6, 20);
						cout << "조금만 더하면";
						Gotoxy(6, 21);
						cout << "잡을 수 있었는데!";
						input = 0;
						Sleep(1000);
					}
					isTurn = !isTurn;
				}
				}
				break;
			case FOUR:
				break;
			default:
				break;
			}
		}
	}
	else if (input == E_Pokemon) { // 포켓몬 교체
		// 현재 : 교체할 포켓몬 두마리를 선택해서 교체하는 방식
		// 두번쨰 방식 : 한마리를 선책하면 현재 포켓몬과 그 포켓몬을 교체하는 방식
		if (isInput) return;
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos)
			{
			case ONE:
				/*if (player->pokemonList[ONE - 1]->GetHP() > 0) {
					player->SwapPokemon(0, ONE - 1);
					input = E_Choice;
					_pos.pos = ONE;
					isTurn = !isTurn;
					IgnoreInput();
				}*/
				break;
			case TWO:
				if (player->pokemonList[TWO - 1]->GetHP() > 0) {
					player->SwapPokemon(0, TWO - 1);
					input = E_Choice;
					_pos.pos = ONE;
					isTurn = !isTurn;
					IgnoreInput();
				}
				break;
			case THREE:
				if (player->pokemonList[THREE - 1]->GetHP() > 0) {
					player->SwapPokemon(0, THREE - 1);
					input = E_Choice;
					_pos.pos = ONE;
					isTurn = !isTurn;
					IgnoreInput();
				}
				break;
			case FOUR:
				if (player->pokemonList[FOUR - 1]->GetHP() > 0) {
					player->SwapPokemon(0, FOUR - 1);
					input = E_Choice;
					_pos.pos = ONE;
					isTurn = !isTurn;
					IgnoreInput();
				}
				break;
			case FIVE:
				if (player->pokemonList[FIVE - 1]->GetHP() > 0) {
					player->SwapPokemon(0, FIVE - 1);
					input = E_Choice;
					_pos.pos = ONE;
					isTurn = !isTurn;
					IgnoreInput();
				}
				break;
			case SIX:
				if (player->pokemonList[SIX - 1]->GetHP() > 0) {
					player->SwapPokemon(0, SIX - 1);
					input = E_Choice;
					_pos.pos = ONE;
					isTurn = !isTurn;
					IgnoreInput();
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
	Sleep(300);
	isInput = false;
}

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

	wcscpy_s(monsterballImage[0], L"⠀⢀⠶⠎⢉⠉⡱⠶⡀⠀");
	wcscpy_s(monsterballImage[1], L"⡸⠇⠠⢈⠀⢂⠐⠠⠹⣇");
	wcscpy_s(monsterballImage[2], L"⣟⡠⢁⣢⡈⠄⢨⠐⣱⣿");
	wcscpy_s(monsterballImage[3], L"⢹⡟⣏⠀⢸⣷⣶⡿⢻⡏");
	wcscpy_s(monsterballImage[4], L"⠀⠀⠶⢏⣉⣀⡰⠦⠁⠀");
}

Battle::~Battle()
{
	if (wildPokemon != NULL)
	{
		delete wildPokemon;
	}
}