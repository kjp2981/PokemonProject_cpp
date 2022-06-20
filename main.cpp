#include"Console.h"
#include"Map.h"
#include"Battle.h"
#include"Manager.h"

using namespace std;

int main() {
	Init();
	PrintTitleScreen();

	system("pause");
	system("cls");

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
			if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
				if (map.map[player.pos.y][player.pos.x] == '4') {
					player.AllPokemonHeal();
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