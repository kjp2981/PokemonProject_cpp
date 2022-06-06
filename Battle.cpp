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
		PrintPokemon(player);
		PrintPokemonHp(player);
		PrintPokemonName(player);
		PrintText(player);
		PrintCursor();
	}
}

void Battle::PrintBattleScreen() { // ���δ� 0���� ����, ���δ� 1���� ���� 2�� ī��Ʈ �ؾ���
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

void Battle::PrintPokemon(Player player) {
	Gotoxy(5, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) { // �÷��̾��� ���ϸ� ���
		for (int j = 0; j < 14; j++) {
			if (player.FirstPokemon()->backImage[i][j] != '0')
				wcout << player.FirstPokemon()->backImage[i][j]; // �̻�� �ⷫ�Ǹ鼭 �ߴܵ�
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

void Battle::PrintPokemonHp(Player player)
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetColor(4, 0);
	Gotoxy(4, 4);
	int hp = HP_BAR * (wildPokemon->GetHP() / wildPokemon->GetMaxHP());
	for (int i = 0; i < hp; i++) {
		wcout << L"��";
	}
	for (int i = 0; i < HP_BAR - hp; i++) {
		cout << "  ";
	}
	
	hp = HP_BAR * (player.FirstPokemon()->GetHP() / player.FirstPokemon()->GetMaxHP());
	Gotoxy(36, 12);
	for (int i = 0; i < hp; i++) {
		wcout << L"��";
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
			cout << "��  ";
		}
		else {
			cout << "��  ";
		}
	}

	Gotoxy(6, 19);
	cout << player.FirstPokemon()->GetName() << "��(��)";
	Gotoxy(6, 20);
	cout << "������ �ұ�?";

	Gotoxy(34, 20);
	cout << "��Ʋ"; // 1
	
	Gotoxy(48, 20);
	cout << "����"; // 2

	Gotoxy(34, 24);
	cout << "���ϸ�"; // 3

	Gotoxy(48, 24);
	cout << "����"; // 4
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

Battle::Battle()
{
	_pos.pos = 1;
}

Battle::~Battle()
{
	delete wildPokemon;
}