#include"master.h"

#include<iostream>
#include<stdlib.h>
using namespace std;

//// Constructor
Master::Master(int initial_player_cnt)
{
	_player_cnt = initial_player_cnt;
	_turn_passed = 0;
	_turn_available = 100;

	if (initial_player_cnt <= 0)
	{
		string str = "error";
		consoleSend(str, false);
	}
	else if (initial_player_cnt == 1)
	{
		string str = "cannot play alone";
		consoleSend(str, false);
	}
	else if (initial_player_cnt <= 4)
	{
		string str = "game start";
		consoleSend(str, false);

		// 중립 플레이어는 죽은 플레이어라고 상정
		_is_player_alive[0] = false;
		for (int i = 1; i < _player_cnt; i++)
		{
			_is_player_alive[i] = true;
		}
	}
	else
	{
		string str = "too much player";
		consoleSend(str, false);
	}
}

//// methods - system & alert
// string 을 console 에 출력하거나, 연산 결과를 다른 클라이언트로 전송함.
void Master::consoleSend(string data, bool client = false)
{
	cout << data << endl;
	if (client == true)
	{

	}
}

//// methods - flow management
// 한 판이 시작될 때 수행
void Master::gameStart()
{

}

//// methods - flow management
// 모든 플레이어의 턴을 준비할 때 수행
void Master::turnCycleStart()
{

}

//// methods - flow management
// 한 플레이어가 실행 권한을 부여받을 때 수행
// reutrn : 이 플레이어가 턴을 받았을 때 동작할 수 있는 회수
int Master::playerTrunStart(Player player)
{
	// 플레이어가 죽었을 경우 관련해서
	// 이 함수에서 처리해줄 것.
	// 즉, Player 배열에서 데이터 빼고 버리지 말고 여기서 흐름 처리.

}

//// methods - flow management
// 특정 플레이어에게 실행 권한 한 번을 부여할 때 수행
void Master::playerActionStart(Player player)
{
	// 목적 : 여기가 Player 클래스와 직접적인 상호 작용 공간
	
	// e.g 
	player.selectAction();
}

//// methods - flow management
void Master::playerActionEnd(Player player)
{
	// 목적 : 플레이어가 수행한 동작에 따라 갱신된 내용을 바탕으로 마스터에서 집계하고 연산.
	// -- 지역마다 잔존한 병력 점검
	// -- 지역마다 소유 정보 점검


	// 모든 플레이어의 자신의 최대 실행횟수 다시 연산하도록 명령
	calculateAllPlayersMaxCommandCnt();
}

//// methods - flow management
// 한 플레이어의 턴이 종료되었을 때 수행
void Master::playerTurnEnd(Player player)
{
	// 목적 : 이 플레이어의 동작 마무리 및 갱신
	// -- 지역마다 소유 정보 점검하여 최대 턴 수 조정


}

//// methods - flow management
// 모든 플레이어의 턴이 종료되었을 때 수행
void Master::turnCycleEnd()
{
	// -- 플레이어의 멸망을 체크.

}

//// methods - flow management
// 한 판이 끝났을 때 수행
void Master::gameEnd()
{


}

//// methods - rule management
// 모든 플레이어를 대상으로 그 플레이어가 최대로 플레이할 수 있는 턴을 다시 연산해서 각 플레이어의 변수에 넣어줌.
void Master::calculateAllPlayersMaxCommandCnt()
{
	int myplace_cnt = 0;
	int user_max_control_cnt;

	for (int i = 1; i < _player_cnt; i++)
	{
		int* myplace_arr = _player[i].get_myPlace(); // return : [0,1,0,0,0,1,0...]
		for (int j = 0; j < 25; j++)
		{
			if (myplace_arr[i] == 1) myplace_cnt++;
		}

		// 소유하고 있는 지역의 개수에 따라 정해짐
		if (myplace_cnt <= 3)
		{
			user_max_control_cnt = 2;
		}
		else if (myplace_cnt < 5)
		{
			user_max_control_cnt = 3;
		}
		else if (myplace_cnt < 7)
		{
			user_max_control_cnt = 4;
		}
		else if (myplace_cnt < 11)
		{
			user_max_control_cnt = 5;
		}
		else 
		{
			user_max_control_cnt = 6;
		}

		_player[i].set_maxControlCnt(user_max_control_cnt);
		delete[] myplace_arr;
	}
}


//// methods - rule management
// 모든 플레이어를 대상으로 그 플레이어가 멸망하지 않았는지 확인해줌.
void Master::checkAllPlayersAlive()
{
	for (int i = 1; i < _player_cnt; i++)
	{
	
	}
}