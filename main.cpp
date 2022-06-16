#include"Console.h"
#include"Map.h"
#include"Battle.h"
#include"Manager.h"

using namespace std;

int main() {
	Init();

	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L"█████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗" << endl;
	wcout << L"██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║" << endl;
	wcout << L"██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║" << endl;
	wcout << L"██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║" << endl;
	wcout << L"██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║" << endl;
	wcout << L"╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝" << endl;
	wcout << endl;
	wcout << L"██████╗ ██╗██████╗  █████╗ ████████╗██╗███╗   ██╗ █████╗" << endl;
	wcout << L"██╔════╝ ██║██╔══██╗██╔══██╗╚══██╔══╝██║████╗  ██║██╔══██╗" << endl;
	wcout << L"██║  ███╗██║██████╔╝███████║   ██║   ██║██╔██╗ ██║███████║" << endl;
	wcout << L"██║   ██║██║██╔══██╗██╔══██║   ██║   ██║██║╚██╗██║██╔══██║" << endl;
	wcout << L"╚██████╔╝██║██║  ██║██║  ██║   ██║   ██║██║ ╚████║██║  ██║" << endl;
	wcout << L"╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝" << endl;
	cout << endl;
	cout << "아무키나 누르세요!" << endl;
	_setmode(_fileno(stdout), _O_TEXT);

	char a = _getch(); // 버그 있음!! 중단됨

	Map map;
	Player player;
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