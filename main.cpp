#include"Console.h"
#include"Map.h"
#include"Battle.h"
#include"Manager.h"
#include"SoundManager.h"

using namespace std;

int main() {
	Init();
	PrintTitleScreen();
	PlayingBgm(Opening);

	//system("pause");
	_getch();
	system("cls");
	PlayingBgm(Lake);

	Map map;
	Player player;
	map.SetMap();
	map.PrintMap(map.map, &player.pos);
	Battle battle(&player, &map);

	while (true)
	{
		Gotoxy(0, 0);
		if (player.isBattle == false) {
			player.MovePlayer(map);
			// 옆에 포켓몬 정보 띠우기
			if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
				if (map.map[player.pos.y][player.pos.x] == '4') {
					player.AllPokemonHeal();
					Gotoxy(player.pos.x, player.pos.y + 1);
					cout << "포켓몬이 모두 건강해졌습니다.";
				}
			}
		}
		else {
			// 배틀
			//battle.PrintBattleScreen();
			battle.Update();
		}
	}
}