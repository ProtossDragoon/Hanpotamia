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
	** �� �Լ��� string �� console �� ����� �ϰų�
	** ���� ����� �ٸ� Ŭ���̾�Ʈ�� ������ ������ �մϴ�.
	*/

	cout << data << endl;
	if (client == true)
	{
		
	}
}