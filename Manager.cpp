#include "Manager.h"
#include"Console.h"
#include<iostream>

using namespace std;

void Clear() // 전체 삭제
{
	Gotoxy(0, 0);
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << "  ";
		}
		cout << endl;
	}
}

void Clear(int startX, int startY, int endX, int endY) // 일정 범뷔 삭제
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
	//system("mode con: cols=60 lines=29"); // 콘솔 창 사이즈 조절

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO consoleCursor; // 
	consoleCursor.bVisible = 0;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);
}
