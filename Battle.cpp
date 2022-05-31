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
