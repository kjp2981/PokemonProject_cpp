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
	//	// TODO : ���� ����
	//}
	MoveCursor();
	Input();
}

void Battle::CreatePokemon() {
	if (wildPokemon == nullptr) {
		int percent = Random();
		if (percent < 1) { // ���Ƽ��
			wildPokemon = new Giratina();
		}
		else if (percent < 10) {
			percent = Random();
			if (percent < 33) { // ��α�
				wildPokemon = new Turtwig();
			}
			else if (percent < 66) { // �ص���
				wildPokemon = new Piplup();
			}
			else { // �Ҳɼ���
				wildPokemon = new Chimchar();
			}
		}
		else if (percent < 30) { // ��ī��
			wildPokemon = new Pikachu();
		}
		else if (percent < 60) { // ����
			wildPokemon = new Gible();
		}
		else { // ���
			wildPokemon = new Starly();
		}
		AllPrint();
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

void Battle::PrintBattleScreen() { // ���δ� 0���� ����, ���δ� 1���� ���� 2�� ī��Ʈ �ؾ���
	Gotoxy(0, 0);
	cout << "�������������������������������" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��������������                                ��" << endl;
	cout << "��                        ��                              ��" << endl;
	cout << "��                          ��                            ��" << endl;
	cout << "�����������������                          ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                ��������������" << endl; // 10
	cout << "��                              ��                        ��" << endl;
	cout << "��                            ��                          ��" << endl;
	cout << "��                          �����������������" << endl;
	cout << "��                                                        ��" << endl; // 14
	cout << "�������������������������������" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "��                                                        ��" << endl;
	cout << "�������������������������������" << endl;
}

void Battle::PrintPokemon() {
	Gotoxy(5, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) { // �÷��̾��� ���ϸ� ���
		for (int j = 0; j < 14; j++) {
			if (player->FirstPokemon()->backImage[i][j] != '0')
				wcout << player->FirstPokemon()->backImage[i][j]; // �̻�� �ⷫ�Ǹ鼭 �ߴܵ�
		}
		Gotoxy(5, 7 + i + 1);
	}

	Gotoxy(40, 2);
	for (int i = 0; i < 7; i++) { // �߻� ���ϸ� ���
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << wildPokemon->frontImage[i][j]; // �̻�� �ⷫ�Ǹ鼭 �ߴܵ�
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
		wcout << L"��";
	}
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		cout << "  ";
	}
	
	hpBar = HP_BAR * (player->FirstPokemon()->GetHP() / player->FirstPokemon()->GetMaxHP());
	Gotoxy(36, 12);
	for (int i = 0; i < hpBar; i++) {
		wcout << L"��";
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
			cout << "��  ";
		}
		else {
			cout << "��  ";
		}
	}

	Clear(2, 16, 58, 28);

	Gotoxy(6, 19);
	cout << player->FirstPokemon()->GetName() << "��(��)";
	Gotoxy(6, 20);
	cout << "������ �ұ�?";

	if (input == E_Choice) {
		Gotoxy(36, 18);
		cout << "��Ʋ"; // 1

		Gotoxy(48, 18);
		cout << "����"; // 2

		Gotoxy(36, 22);
		cout << "���ϸ�"; // 3

		Gotoxy(48, 22);
		cout << "����"; // 4
	}
	else if (input == E_Skill) {
		// TODO : ��� ����Ʈ ���
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
		// TODO : ������ ����Ʈ ���
		Gotoxy(36, 18);
		cout << "��ó�� x " << player->bag->medicineCnt;

		Gotoxy(36, 22);
		cout << "���� �� x " << player->bag->monsterballCnt;
	}
	else if (input == E_Pokemon) {
		// TODO : ���ϸ� ����Ʈ ���
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
			case FIVE:
				DeleteCursor();
				_pos.pos = THREE;
				PrintCursor();
				break;
			case SIX:
				DeleteCursor();
				_pos.pos = FOUR;
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
				DeleteCursor();
				_pos.pos = FIVE;
				PrintCursor();
				break;
			case FOUR:
				DeleteCursor();
				_pos.pos = SIX;
				PrintCursor();
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
			case FIVE:
				break;
			case SIX:
				DeleteCursor();
				_pos.pos = FIVE;
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
			case FIVE:
				DeleteCursor();
				_pos.pos = SIX;
				PrintCursor();
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
	wcout << L"��";
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
	if (input == E_Choice) {
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			if (isInput) return;
			switch (_pos.pos) {
			case ONE:
				// TODO : ��Ʋ�ϱ�
				input = 1;
				PrintText();
				IgnoreInput();
				break;
			case TWO:
				// TODO : ����(������ ����Ʈ ����ϱ�)
				//Clear();
				input = 2;
				DeleteCursor();
				_pos.pos = ONE;
				PrintCursor();
				PrintText();
				IgnoreInput();
				break;
			case THREE:
				// TODO : ���ϸ� ��ü(���ϸ� ����Ʈ ����ϱ�)
				input = 3;
				DeleteCursor();
				_pos.pos = ONE;
				PrintCursor();
				PrintText();
				IgnoreInput();
				break;
			case FOUR:
				// TODO : ����ġ��
				player->isBattle = false;
				delete wildPokemon;
				wildPokemon = nullptr;
				input = 0;
				Clear();
				map->PrintMap(map->map, &player->pos);
				// ��µǱ��ϴµ� �ٷ� ������... ����...
				break;
			}
		}
	}
	else if (input == E_Skill) { // ��ų ����Ʈ
		// TODO : ��ų ���(Damage�ֱ�)
		//Sleep(100);
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			if (isInput) return;
			switch (_pos.pos)
			{
			case ONE:
				Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "��(��)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[0]->name << "�� ����ߴ�.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[0]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : �� �ޱ�
					Clear();
					// ���� ��½�Ű��
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
				cout << player->FirstPokemon()->GetName() << "��(��)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[1]->name << "�� ����ߴ�.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[1]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : �� �ޱ�
					Clear();
					// ���� ��½�Ű��
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
				cout << player->FirstPokemon()->GetName() << "��(��)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[2]->name << "�� ����ߴ�.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[2]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : �� �ޱ�
					Clear();
					// ���� ��½�Ű��
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
				cout << player->FirstPokemon()->GetName() << "��(��)";
				Gotoxy(6, 20);
				cout << player->FirstPokemon()->skiiList[3]->name << "�� ����ߴ�.";
				wildPokemon->Damage(player->FirstPokemon()->skiiList[3]->damage);
				if (wildPokemon->GetHP() <= 0) {
					player->isBattle = false;
					delete wildPokemon;
					wildPokemon = nullptr;
					input = 0;
					// TODO : �� �ޱ�
					Clear();
					// ���� ��½�Ű��
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
	else if (input == E_Item) { // ������ ���
		if (isInput) return;
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos)
			{
			case ONE: // ��ó��
				// TODO : ���� ���ϸ�(�迭�� 0���� ���ϸ�) ���ϱ�
				player->bag->UseItem(I_Medicine);
				player->FirstPokemon()->Heal(10);
				Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "��(��)";
				Gotoxy(6, 20);
				cout << "��ó���� ����ߴ�.";
				input = 0;
				Sleep(1000);
				AllPrint();
				break;
			case TWO:
				break;
			case THREE: // ���ͺ�
				// TODO : ���ͺ� ������
				// TODO : �߻����ϸ��� hp�� ���� ���
				Gotoxy(6, 19);
				cout << "���ͺ��� ����ߴ�.";
				// TODO : �߻� ���ϸ� ��¡�� ���� ���� �ٲٱ�
				Sleep(500);
				{
					int percent = 100 * (wildPokemon->GetHP() / wildPokemon->GetMaxHP());
					int rand = Random();

					if (rand > percent) {
						Gotoxy(6, 19);
						cout << "�ų���-!";
						Gotoxy(6, 20);
						cout << wildPokemon->GetName() << "��(��) ����Ҵ�!";
						// TODO : �� ���ϸ� �迭 �� ��� �ִ� ������ ù��°�� �߻� ���ϸ� �ֱ�
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						Sleep(1000);
						player->isBattle = false;
						delete wildPokemon;
						wildPokemon = nullptr;
						input = 0;
						Clear();
						// TODO : �� ����ϱ�
					}
					else {
						Gotoxy(6, 19);
						cout << "�ƽ���!";
						Gotoxy(6, 20);
						cout << "���׸� ���ϸ�";
						Gotoxy(6, 21);
						cout << "���� �� �־��µ�!";
						input = 0;
						Sleep(1000);
						AllPrint();
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
	else if (input == E_Pokemon) { // ���ϸ� ��ü
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
//				// Ŭ���� ���� �ؽ�Ʈ�� �ؽ�Ʈ�� �´� �ൿ�ϱ�
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
	fIdx = -1;
	sIdx = -1;
}

Battle::~Battle()
{
	if (wildPokemon != NULL)
	{
		delete wildPokemon;
	}
}