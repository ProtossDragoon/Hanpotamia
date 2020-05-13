#include"master.h"

#include<iostream>
#include<stdlib.h>
using namespace std;

Master::Master(int initial_player_cnt)
{
	_player_cnt = initial_player_cnt;
	_turn_passed = 0;
	_turn_available = 100;
	if (initial_player_cnt <= 0)
	{
		string str = "error";
		consoleSend(str);
	}
	else if (initial_player_cnt == 1)
	{
		string str = "cannot play alone";
		consoleSend(str);
	}
	else if (initial_player_cnt <= 4)
	{

	}
	else
	{
		string str = "too much player";
		consoleSend(str);
	}
}

/// string 을 console 에 출력하거나, 연산 결과를 다른 클라이언트로 전송함.
void Master::consoleSend(string data, bool client = false)
{

	cout << data << endl;
	if (client == true)
	{
		
	}
}

// 한 판이 시작될 때 수행
void Master::gameStart()
{

}

// 모든 플레이어의 턴을 준비할 때 수행
void Master::turnCycleStart()
{

}

// 한 플레이어가 실행 권한을 부여받을 때 수행
// reutrn : 이 플레이어가 턴을 받았을 때 동작할 수 있는 회수
int Master::playerTrunStart(Player player)
{
	// 플레이어가 죽었을 경우 관련해서
	// 이 함수에서 처리해줄 것.
	// 즉, Player 배열에서 데이터 빼고 버리지 말고 여기서 흐름 처리.

	// 이 플레이어가 가질 수 있는 동작회수
	int actions_left = 0;


	while (actions_left)
	{
		
		playerActionEnd();
	}
}

// 플레이어의 행동이 끝났을 때 수행
void Master::playerActionEnd()
{
	// 플레이어가 수행한 동작에 따라 갱신된 내용을 바탕으로
	// 마스터에서 집계하고 연산.
}

// 플레이어의 턴이 종료되었을 때 수행
void Master::playerTrunEnd(Player player)
{
	// 이 플레이어의 동작 마무리, 


}

// 플레이어의 턴이 종료되었을 때 수행
void Master::turnCycleEnd()
{


}

// 한 판이 끝났을 때 수행
void Master::gameEnd()
{


}