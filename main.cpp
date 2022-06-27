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
	map.map[0][15] = '0';
	map.PrintMap(map.map, &player.pos);
	Battle battle(&player, &map);

	while (true)
	{
		if (player.IsPokemonFull()) {
			map.map[0][15] = '5';
		}
		Gotoxy(0, 0);
		if (player.isBattle == false) {
			player.MovePlayer(map);
			player.PrintPokemon();
			if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
				if (map.map[player.pos.y][player.pos.x] == '4') {
					player.AllPokemonHeal();
					PlayingEffect(Recorvery);
					Gotoxy(player.pos.x * 2, player.pos.y + 1);
					cout << "포켓몬이 모두 건강해졌습니다.";
				}
				else if (map.map[player.pos.y][player.pos.x] == '5') {
					// TODO : 기라티나 출현
					// 1. 가라티나 포효
					// 2. 기라티나 출현
					Gotoxy(26, 14);
					PlayingEffect(GiratinaCries);
					cout << "크아아아!";
					player.isGiratina = true;
					player.isBattle = true;
					Sleep(1000);
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