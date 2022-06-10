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
	MoveCursor();
	Input();

	/*Gotoxy(61, 0);
	system("pause");*/
	//_getch();
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
	_setmode(_fileno(stdout), _O_TEXT);
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		cout << "  ";
	}
	
	hpBar = HP_BAR * (player->FirstPokemon()->GetHP() / player->FirstPokemon()->GetMaxHP());
	Gotoxy(36, 12);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < hpBar; i++) {
		wcout << L"��";
	}
	_setmode(_fileno(stdout), _O_TEXT);
	for (int i = 0; i < HP_BAR - hpBar; i++) {
		cout << "  ";
	}

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
	//Clear(32, 19, 50, 26);

	Gotoxy(4, 16);
	for (int i = 0; i < 6; i++) {
		if (player->pokemonList[i] != NULL) {
			cout << "��  ";
		}
		else {
			cout << "��  ";
		}
	}

	Gotoxy(6, 19);
	cout << player->FirstPokemon()->GetName() << "��(��)";
	Gotoxy(6, 20);
	cout << "������ �ұ�?";

	if (input == 0) {
		Gotoxy(34, 20);
		cout << "��Ʋ"; // 1

		Gotoxy(48, 20);
		cout << "����"; // 2

		Gotoxy(34, 24);
		cout << "���ϸ�"; // 3

		Gotoxy(48, 24);
		cout << "����"; // 4
		PrintCursor();
	}
	else if (input == 1) {
		// TODO : ��� ����Ʈ ���
		Gotoxy(34, 20);
		cout << player->FirstPokemon()->skiiList[0]->name;

		Gotoxy(48, 20);
		cout << player->FirstPokemon()->skiiList[1]->name;

		Gotoxy(34, 24);
		cout << player->FirstPokemon()->skiiList[2]->name;

		Gotoxy(48, 24);
		cout << player->FirstPokemon()->skiiList[3]->name;
		PrintCursor();
	}
	else if (input == 2) {
		// TODO : ������ ����Ʈ ���
		Gotoxy(32, 21);
		cout << "��ó�� x " << player->bag->medicineCnt;

		Gotoxy(32, 25);
		cout << "���� �� x " << player->bag->monsterballCnt;
	}
	else if (input == 3) {
		// TODO : ���ϸ� ����Ʈ ���
		Gotoxy(32, 19);
		cout << player->pokemonList[0]->GetName();

		Gotoxy(44, 19);
		cout << player->pokemonList[1]->GetName();

		Gotoxy(32, 23);
		cout << player->pokemonList[2]->GetName();

		Gotoxy(44, 23);
		cout << player->pokemonList[3]->GetName();

		Gotoxy(32, 27);
		cout << player->pokemonList[4]->GetName();

		Gotoxy(44, 27);
		cout << player->pokemonList[5]->GetName();
	}
}

void Battle::MoveCursor()
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
	wcout << L"��";
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

void Battle::Input()
{
	if (input == 0) {
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos) {
			case ONE:
				// TODO : ��Ʋ�ϱ�
				input = 1;
				PrintText();
				break;
			case TWO:
				// TODO : ����(������ ����Ʈ ����ϱ�)
				//Clear();
				input = 2;
				PrintText();
				break;
			case THREE:
				// TODO : ���ϸ� ��ü(���ϸ� ����Ʈ ����ϱ�)
				input = 3;
				PrintText();
				break;
			case FOUR:
				// TODO : ����ġ��
				player->isBattle = false;
				delete wildPokemon;
				wildPokemon = nullptr;
				input = 0;
				Clear();
				// ���� ��½�Ű��
				break;
			}
		}
	}
	else if (input == 1) { // ��ų ����Ʈ
		// TODO : ��ų ���(Damage�ֱ�)
		Sleep(100);
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) || (GetAsyncKeyState(VK_RETURN) & 0x8000)) {
			switch (_pos.pos)
			{
			case ONE:
				//Clear(6, 19, )k
				//Gotoxy(6, 19);
				cout << player->FirstPokemon()->GetName() << "��(��)";
				Gotoxy(6, 20);
				cout << "������ �ұ�?";
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
				system("cls");
				AllPrint();
				input = 0;
				PrintText();
				break;
			case TWO:
				wildPokemon->Damage(player->FirstPokemon()->skiiList[1]->damage);
				PrintPokemonHp();
				input = 0;
				PrintText();
				break;
			case THREE:
				wildPokemon->Damage(player->FirstPokemon()->skiiList[2]->damage);
				PrintPokemonHp();
				input = 0;
				PrintText();
				break;
			case FOUR:
				wildPokemon->Damage(player->FirstPokemon()->skiiList[3]->damage);
				PrintPokemonHp();
				input = 0;
				PrintText();
				break;
			default:
				break;
			}
		}
	}
	else if (input == 2) { // ������ ���
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
	else if (input == 3) { // ���ϸ� ��ü
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
}

Battle::~Battle()
{
	if (wildPokemon != NULL)
	{
		delete wildPokemon;
	}
}