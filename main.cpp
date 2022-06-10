#include"Console.h"
#include"Map.h"
#include"Battle.h"
#include"Manager.h"

using namespace std;

int main() {
	Init();

	Map map;
	Player player;
	player.SetFirstPokemon();
	map.SetMap();
	map.PrintMap(map.map, &player.pos);
	Battle battle(&player, &map);
	//battle.SetPlayer(&player);

	while (true)
	{
		Gotoxy(0, 0);
		if (player.isBattle == false) {
			player.MovePlayer(map);
		}
		else {
			// 배틀
			//battle.PrintBattleScreen();
			battle.Update();
		}
	}
}