#include "Manager.h"
#include"Console.h"
#include<iostream>

using namespace std;

void Clear()
{
	Gotoxy(0, 0);
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << "  ";
		}
		cout << endl;
	}
}
