#include "Manager.h"
#include"Console.h"
#include<iostream>

using namespace std;

void Clear() // ��ü ����
{
	Gotoxy(0, 0);
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << "  ";
		}
		cout << endl;
	}
}

void Clear(int startX, int startY, int endX, int endY) // ���� ���� ����
{
	int x = endX - startX;
	int y = endY - startY;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << "  ";
		}
		Gotoxy(startX, startY + i + 1);
	}
}
