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
	int x = (endX - startX) / 2;
	int y = endY - startY;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << "  ";
		}
		Gotoxy(startX, startY + i + 1);
	}
}

void Init()
{
	SetConsoleTitle(L"POKEMON GAME");
	//system("mode con: cols=60 lines=29"); // �ܼ� â ������ ����

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	CONSOLE_CURSOR_INFO consoleCursor; // 
	consoleCursor.bVisible = 0;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);
}
