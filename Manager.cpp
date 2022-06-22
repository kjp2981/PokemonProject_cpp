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
	system("mode con lines=31 cols=120"); // 콘솔 창 사이즈 조절

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = false;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);
}

void PrintTitleScreen()
{
	Gotoxy(0, 0);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl; // 10
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl; // 14
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■                                                        ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	/*_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"█████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗" << endl;
	wcout << L"██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║" << endl;
	wcout << L"██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║" << endl;
	wcout << L"██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║" << endl;
	wcout << L"██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║" << endl;
	wcout << L"╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝" << endl;
	_setmode(_fileno(stdout), _O_TEXT);
	cout << endl;
	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"██████╗ ██╗██████╗  █████╗ ████████╗██╗███╗   ██╗ █████╗" << endl;
	wcout << L"██╔════╝ ██║██╔══██╗██╔══██╗╚══██╔══╝██║████╗  ██║██╔══██╗" << endl;
	wcout << L"██║  ███╗██║██████╔╝███████║   ██║   ██║██╔██╗ ██║███████║" << endl;
	wcout << L"██║   ██║██║██╔══██╗██╔══██║   ██║   ██║██║╚██╗██║██╔══██║" << endl;
	wcout << L"╚██████╔╝██║██║  ██║██║  ██║   ██║   ██║██║ ╚████║██║  ██║" << endl;
	wcout << L"╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝" << endl;*/

	_setmode(_fileno(stdout), _O_U8TEXT);
	Gotoxy(15, 5);
	wcout << L"█▀█ █▀█ █▄▀ █▀▀ █▀▄▀█ █▀█ █▄░█";
	Gotoxy(15, 6);
	wcout << L"█▀▀ █▄█ █░█ ██▄ █░▀░█ █▄█ █░▀█";
	Gotoxy(16, 8);
	wcout << L"█▀▀ █ █▀█ ▄▀█ ▀█▀ █ █▄░█ ▄▀█";
	Gotoxy(16, 9);
	wcout << L"█▄█ █ █▀▄ █▀█ ░█░ █ █░▀█ █▀█";

	_setmode(_fileno(stdout), _O_TEXT);
	// 게임의 목표 적기
	Gotoxy(15, 19);
	cout << "전설의 포켓몬 기라티나를 잡아라!";
	// 도움말 적기
	Gotoxy(10, 21);
	cout << "이동 : →↑←↓, 상호작용 : Space or Enter";
	Gotoxy(15, 23); // 위치 더 아래쪽 으로 옴기기
	cout << "아무 키나 눌러주세요.";
}
