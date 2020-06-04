#include"master.h"
#include"player.h"

int main()
{
	// select player	
	Master game_master = Master(3);

	game_master.gameStart();

	// 게임이 끝났는지 끝나지 않았는지 최대 턴을 보고 판단
	while (game_master.get_turnAvailable())
	{
		game_master.turnCycleStart();
		// 일부 플레이어가 멸망해도 _player_cnt 는 초깃값에서 변하지 않습니다.
		for (int i = 0; i < game_master.get_playerCnt(); i++)
		{
			Player *player = game_master.get_player(i);
			if (game_master.playerTrunStart(player))
			{
				int action_available = 0;
				while (action_available = player->get_currentControlCnt())
				{
					game_master.playerActionStart(player);
					game_master.playerActionEnd(player);
				}
			}
			game_master.playerTurnEnd(game_master.get_player(i));
		}
		game_master.turnCycleEnd();
		////system("cls"); << 콘솔 클리어 명령어 이거 맞나 ("clear") 이건가 쨌든 있으면 좋을 듯 ㅇㅇ
	}

	game_master.gameEnd();
}
