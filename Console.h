#pragma once
#include<Windows.h>
#include<conio.h>
#include<tchar.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>

using namespace std;

void Gotoxy(int x, int y);
void SetColor(int color, int bgColor);
void FullScreen();