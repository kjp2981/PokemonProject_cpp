#include<iostream>
#include"Console.h"
#include"Map.h"

using namespace std;

// 0: 길, 1, 돌 벽(〓), 2: 돌 벽{ ) }, 3, 풀(포켓몬 나오는곳), 4, 회복해주는 곳
void Map::SetMap(char map[MAX_X][MAX_Y]) {
	strcpy_s(map[0],  "400000000000000000003333333333");
	strcpy_s(map[1],  "000000000000000000003333333333");
	strcpy_s(map[2],  "000000000000000000003333333333");
	strcpy_s(map[3],  "000000000000000000003333333333");
	strcpy_s(map[4],  "000000000000000000000000000000");
	strcpy_s(map[5],  "000000000000000000000000000000");
	strcpy_s(map[6],  "000000000000000000003333333333");
	strcpy_s(map[7],  "000000000000000000003333333333");
	strcpy_s(map[8],  "000000000000000000003333333333");
	strcpy_s(map[9],  "000000000000000000003333333300");
	strcpy_s(map[10], "000000000000000000003333333300");
	strcpy_s(map[11], "000000000000000000003333333333");
	strcpy_s(map[12], "000000000000000000003333333333");
	strcpy_s(map[13], "111111120000000000003333333333");
	strcpy_s(map[14], "000000020000000000000000000000");
	strcpy_s(map[15], "333330020000000000000000000000");
	strcpy_s(map[16], "333330020000000000000000000000");
	strcpy_s(map[17], "333330020000000000000000000000");
	strcpy_s(map[18], "333330020000000000000000000000");
	strcpy_s(map[19], "000000020000000000000000000000");
	strcpy_s(map[20], "111111120000000000000000000000");
	strcpy_s(map[21], "000000000000000000000000000000");
	strcpy_s(map[22], "000000000000000000000000000000");
	strcpy_s(map[23], "000000000000000000000000000000");
	strcpy_s(map[24], "333333300000000000000000000000");
	strcpy_s(map[25], "333333300000000000000000000000");
	strcpy_s(map[26], "333333333000000000000000000000");
	strcpy_s(map[27], "333333333000000000000000000000");
	strcpy_s(map[28], "333333333330000000000000000000");
	strcpy_s(map[29], "333333333330000000000000000004");
}

void Map::PrintMap(char map[MAX_X][MAX_Y], PPOS playerPos) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (playerPos->x == j && playerPos->y == i) // 진짜
			{
				SetColor(15, 8);
				cout << "☆";
				SetColor(15, 0);
			}
			else if (map[i][j] == '0') {
				SetColor(15, 8);
				cout << "  ";
				SetColor(15, 0);
			}
			else if (map[i][j] == '1') {
				SetColor(6, 8);
				cout << "〓";
				SetColor(15, 0);
			}
			else if (map[i][j] == '2') {
				SetColor(6, 8);
				cout << "))";
				SetColor(15, 0);
			}
			else if (map[i][j] == '3') {
				SetColor(2, 8);
				cout << "※";
				SetColor(15, 0);
			}
			else if (map[i][j] == '4') {
				SetColor(15, 8);
				cout << "§";
				SetColor(15, 0);
			}
		}
		cout << endl;
	}
}

bool Map::CheckGrass(char map[MAX_X][MAX_Y], PPOS playerPos) {
	if (map[playerPos->x][playerPos->y] == '3') {
		return true;
	}
	return false;
}
