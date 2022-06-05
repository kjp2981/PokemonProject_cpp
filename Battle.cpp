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
	Gotoxy(3, 16);
	for (int i = 0; i < 6; i++) {
		if (player.pokemonList[i] != NULL) {
			cout << "��  ";
		}
		else {
			cout << "��  ";
		}
	}
}

Battle::~Battle()
{
	delete wildPokemon;
}
