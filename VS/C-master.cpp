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

void Master::consoleSend(string data, bool client = false)
{
	/*
	** 이 함수는 string 을 console 에 출력을 하거나
	** 연산 결과를 다른 클라이언트로 보내는 역할을 합니다.
	*/

	cout << data << endl;
	if (client == true)
	{
		
	}
}