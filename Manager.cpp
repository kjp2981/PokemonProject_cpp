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
	int x = endX - startX;
	int y = endY - startY;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << "  ";
		}
		Gotoxy(startX, startY + i + 1);
	}
}
