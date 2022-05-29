#include"Console.h"
#include"Map.h"

using namespace std;

int main() {
	Map map;
	Player player;

	map.SetMap(map.map);

	while (true)
	{
		Gotoxy(0, 0);
		player.MovePlayer(map.map);
		map.PrintMap(map.map, &player.pos);
		if (map.CheckGrass(map.map, &player.pos)) {
			// TODO : 랜덤한 확률로 포켓몬 출현
		}
	}
}