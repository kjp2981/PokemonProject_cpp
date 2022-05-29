#include "Player.h"
#include <Windows.h>
#include"Manager.h"

void Player::MoveUp(char map[MAX_X][MAX_Y])
{
	if (pos.y > 0) {
		if ((map[pos.y - 1][pos.x] != '1') && (map[pos.y - 1][pos.x] != '2')) {
			--pos.y;
		}
	}
}

void Player::MoveDown(char map[MAX_X][MAX_Y])
{
	if (pos.y < 29) {
		if ((map[pos.y + 1][pos.x] != '1') && (map[pos.y + 1][pos.x] != '2')) {
			++pos.y;
		}
	}
}

void Player::MoveLeft(char map[MAX_X][MAX_Y])
{
	if (pos.x > 0) {
		if (map[pos.y][pos.x - 1] != '2') {
			--pos.x;
		}
	}
}

void Player::MoveRight(char map[MAX_X][MAX_Y])
{
	if (pos.x < 29) {
		if (map[pos.y][pos.x + 1] != '2') {
			++pos.x;
		}
	}
}

void Player::MovePlayer(char map[MAX_X][MAX_Y])
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		MoveUp(map);
		Sleep(50);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		MoveDown(map);
		Sleep(50);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		MoveLeft(map);
		Sleep(50);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		MoveRight(map);
		Sleep(50);
	}
}