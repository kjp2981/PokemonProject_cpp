#include "Battle.h"
#include"Pokemon.h"
#include<random>
#include"Random.h"
#include"Player.h"
#include"Console.h"

using namespace std;

void Battle::Update(Player player) {
	CreatePokemon();
	PrintBattleScreen();
	PrintPokemon(player);

	_getch();
}

void Battle::CreatePokemon() {
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

void Battle::PrintBattleScreen() {
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
	Gotoxy(2, 7);
	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << player.ReturnPokemon()->backImage[i][j]; // �̻�� �ⷫ�Ǹ鼭 �ߴܵ�
		}
		Gotoxy(2, 7 + i + 1);
	}

	Gotoxy(40, 2);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 14; j++) {
			//if (player.ReturnPokemon()->backImage[i][j] != NULL)
			wcout << wildPokemon->frontImage[i][j]; // �̻�� �ⷫ�Ǹ鼭 �ߴܵ�
		}
		Gotoxy(40, i + 3);
	}
	_setmode(_fileno(stdout), _O_TEXT);
}

Battle::~Battle()
{
	delete wildPokemon;
}
