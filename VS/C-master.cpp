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

/// string �� console �� ����ϰų�, ���� ����� �ٸ� Ŭ���̾�Ʈ�� ������.
void Master::consoleSend(string data, bool client = false)
{

	cout << data << endl;
	if (client == true)
	{
		
	}
}

// �� ���� ���۵� �� ����
void Master::gameStart()
{

}

// ��� �÷��̾��� ���� �غ��� �� ����
void Master::turnCycleStart()
{

}

// �� �÷��̾ ���� ������ �ο����� �� ����
// reutrn : �� �÷��̾ ���� �޾��� �� ������ �� �ִ� ȸ��
int Master::playerTrunStart(Player player)
{
	// �÷��̾ �׾��� ��� �����ؼ�
	// �� �Լ����� ó������ ��.
	// ��, Player �迭���� ������ ���� ������ ���� ���⼭ �帧 ó��.

	// �� �÷��̾ ���� �� �ִ� ����ȸ��
	int actions_left = 0;


	while (actions_left)
	{
		
		playerActionEnd();
	}
}

// �÷��̾��� �ൿ�� ������ �� ����
void Master::playerActionEnd()
{
	// �÷��̾ ������ ���ۿ� ���� ���ŵ� ������ ��������
	// �����Ϳ��� �����ϰ� ����.
}

// �÷��̾��� ���� ����Ǿ��� �� ����
void Master::playerTrunEnd(Player player)
{
	// �� �÷��̾��� ���� ������, 


}

// �÷��̾��� ���� ����Ǿ��� �� ����
void Master::turnCycleEnd()
{


}

// �� ���� ������ �� ����
void Master::gameEnd()
{


}