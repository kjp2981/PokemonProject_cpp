#include"Console.h"
#include"Map.h"
#include"Battle.h"

using namespace std;

int main() {
	SetConsoleTitle(L"POKEMON GAME");

	Map map;
	Player player;
	Battle battle;

	player.SetFirstPokemon();

	map.SetMap();
	map.PrintMap(map.map, &player.pos);

	while (true)
	{
		Gotoxy(0, 0);
		if (!player.isBattle) {
			player.MovePlayer(map);
		}
		else {
			// 배틀
			//battle.PrintBattleScreen();
			battle.Update(player);
		}
	}
}