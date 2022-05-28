#include "Player.h"
#include<conio.h>
#include <Windows.h>

void Player::MoveUp()
{
	if(pos.y > 0)
		--pos.y;
}

void Player::MoveDown()
{
	if(pos.y < 29)
		++pos.y;
}

void Player::MoveLeft()
{
	if(pos.x > 0)
		--pos.x;
}

void Player::MoveRight()
{
	if(pos.x < 29)
		++pos.x;
}

void Player::MovePlayer()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		MoveUp();
		Sleep(50);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		MoveDown();
		Sleep(50);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		MoveLeft();
		Sleep(50);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		MoveRight();
		Sleep(50);
	}
}