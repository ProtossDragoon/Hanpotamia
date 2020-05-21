#include"master.h"
#include"player.h"
int main()
{
	// select player	
	Master game_master = Master(3);

	// 턴 초기화, 플레이어 기본 자원 할당,
	game_master.gameStart();

	while (game_master.get_turnAvailable())
	{
		game_master.turnCycleStart();
		// 일부 플레이어가 멸망해도 _player_cnt 는 초깃값에서 변하지 않습니다.
		for (int i = 0; i < game_master.get_playerCnt(); i++)
		{
			Player player = game_master.get_player(i);
			game_master.playerTrunStart(player);
			int action_available = 0;
			while (action_available = player.get_availabeControlCnt())
			{
				game_master.playerActionStart(player);
				game_master.playerActionEnd(player);
			}
			game_master.playerTurnEnd(game_master.get_player(i));
		}
		game_master.turnCycleEnd();
	}

	game_master.gameEnd();
}