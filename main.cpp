#include"Console.h"
#include"Map.h"
#include"Battle.h"
#include"Manager.h"

using namespace std;

int main() {
	SetConsoleTitle(L"POKEMON GAME");
	//system("mode con: cols=60 lines=29"); // 콘솔 창 사이즈 조절


	Map map;
	Player player;
	player.SetFirstPokemon();
	Battle battle;
	battle.SetPlayer(&player);


	map.SetMap();
	map.PrintMap(map.map, &player.pos);

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