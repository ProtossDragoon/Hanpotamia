#include"master.h"
#include"player.h"
int main()
{
	// select player	
	Master game_master = Master(3);

	game_master.gameStart();

	while (game_master.get_turnAvailable())
	{
		game_master.turnCycleStart();
		for (int i = 0; i < game_master.get_playerCnt(); i++)
		{
			Player player = game_master.get_player(i);
			int action_available = game_master.playerTrunStart(player);
			for (int j = action_available; j > 0; j--)
			{
				// 각 플레이어의 행동 명령은 해당 객체에서 선택지 보여주고 제어
				game_master.playerActionStart(player, action_available);
				game_master.playerActionEnd(player);
			}
			game_master.playerTrunEnd(game_master.get_player(i));
		}
		game_master.turnCycleEnd();
	}

	game_master.gameEnd();
}