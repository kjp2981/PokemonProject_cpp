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

	while (true)
	{
		Gotoxy(0, 0);
		if (!player.isBattle) {
			player.MovePlayer(map);
			map.PrintMap(map.map, &player.pos); // MovePlayer�Լ� ������ �ȱ��
		}
		else {
			// ��Ʋ
			//battle.PrintBattleScreen();
			battle.Update();
		}
	}
}