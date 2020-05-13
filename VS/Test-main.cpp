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
			int action_available = game_master.playerTrunStart(game_master.get_player(i));
			for (int j = 0; j < action_available; j++)
			{
				// 각 플레이어의 행동 명령은 해당 객체에서 선택지 보여주고 제어

				game_master.playerActionEnd();
			}
			game_master.playerTrunEnd(game_master.get_player(i));
		}
		game_master.turnCycleEnd();
	}

	game_master.gameEnd();
}

void masterTester()
{

}