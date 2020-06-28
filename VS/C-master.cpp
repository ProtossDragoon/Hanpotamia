#include"master.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

//// Constructor
Master::Master()
{
	// 여기의 내용물이 다른 곳으로 이전함.
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


//// methods - Getter & Setter
bool Master::get_isPlayerAlive(Player *player)
{
	int i;
	for (i = 0; i <= get_playerCnt(); i++)
	{
		if (get_player(i) == player)
		{
			break;
		}
	}
	return get_isPlayerAlive(i);
}


//// methods - flow management
// 한 판이 시작될 때 수행
void Master::gameReady(int initial_player_cnt)
{
	// 목적 : 턴 초기화, 플레이어, 플레이어 이름 설정, 기본 자원 할당
	set_gameState("gameReady");

	_player_cnt = initial_player_cnt;
	_turn_passed = 0;
	_turn_available = 5;

	// -- 플레이어 할당
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
		_player[0] = new Player("natural", 0, 0);
		Player tempplayer = Player("temp", 0, 0);
		tempplayer.set_player_name("temp!!!");
		for (int i = 1; i <= _player_cnt; i++)
		{
			// -- 플레이어 이름 설정
			string tempname;
			cout << "player" + to_string(i) + "name : ";
			cin >> tempname;
			_player[i] = new Player(tempname, 2, 2);
			_is_player_alive[i] = true;
		}

		_player_score = new int[_player_cnt+1];
		_player_score[0] = -1;
		for (int i = 1; i <= _player_cnt; i++)
		{
			_player_score[i] = 0;
		}
	}
	else
	{
		string str = "too much player";
		consoleSend(str, false);
	}

	
	// -- 맵 생성
	_gamemap = new Map(30);
	_gamemap->set_areaInformation();
	for(int i=1; i<=_player_cnt; i++)
	    _gamemap->firstArea(_player[i],i);
	system("cls");
	showGameDiscription();
	for (int i = 3; i >= 0; i--)
	{
		cout << "start in " << i << " second(s)";
		Sleep(1000);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}

	cout << "Mission Object      " << endl;
	cout << "상대의 모든 점령지를 빼앗고, 한강 유역 문명의 주인이 되어라";

	Sleep(3000);

	system("cls");
}

//// methods - flow management
// 모든 플레이어의 턴을 준비할 때 수행
void Master::turnCycleStart()
{
	// 목적 : 모든 플레이어의 턴을 시작할 때 공통되는 로직 수행
	set_gameState("turnCycleStart");

	// -- 모든 플레이어의 가용 턴 복구
	for (int i = 1; i <= _player_cnt; i++)
	{
		_player[i]->set_currentControlCnt(_player[i]->get_maxControlCnt());
	}

	// -- 모든 플레이어 자원 지급
	int temp_food = 0;
	int temp_gold = 0;
	int temp_water = 0;	
	for (int i = 1; i <= _player_cnt; i++)
	{
		temp_food = 0;
		temp_gold = 0;
		temp_water = 0;
		_player[i]->get_myPlace();
		for (int j = 0; j < 30; j++)
		{
			temp_food += _gamemap->get_acquirableFood((_gamemap->findArea(j)).areaname);
			temp_gold += _gamemap->get_acquirableGold((_gamemap->findArea(j)).areaname);
			temp_water += _gamemap->get_acquirableWater((_gamemap->findArea(j)).areaname);
		}
		_player[i]->get_myResource()->add_resource_food(temp_food);
		_player[i]->get_myResource()->add_resource_gold(temp_gold);
		_player[i]->get_myResource()->add_resource_water(temp_water);
	}
	
}

//// methods - flow management
// 한 플레이어가 실행 권한을 부여받을 때 수행
// reutrn : 이 플레이어가 턴을 받았을 때 동작할 수 있는 회수
int Master::playerTrunStart(Player *player)
{
	// 목적 : 특정 플레이어의 턴이 시작
	set_gameState("playerTrunStart");

	/*	플레이어가 죽었을 경우 관련해서 이 함수에서 처리해줄 것.
	 	즉, Player 배열에서 데이터 빼고 버리지 말고 여기서 흐름 처리.*/


	// -- 만약 멸망한 플레이어라면 주지 않음.
	if (!get_isPlayerAlive(player))
	{
		return 0;
	}

	system("cls");
	showGameDiscription();

	return player->get_maxControlCnt();
}

//// methods - flow management
// 특정 플레이어에게 실행 권한 한 번을 부여할 때 수행
void Master::playerActionStart(Player *player)
{
	// 목적 : 여기가 Player 클래스와 직접적인 상호 작용 공간
	set_gameState("playerActionStart");

	// -- player 이 행동을 할 수 있도록 실행 권한을 부여
	player->selectAction();
}

//// methods - flow management
void Master::playerActionEnd(Player *player)
{
	// 목적 : 플레이어가 수행한 동작에 따라 갱신된 내용을 바탕으로 마스터에서 집계하고 연산.
	set_gameState("playerActionEnd");

	// -- 지역마다 잔존한 병력 점검 ? 이게 필요함?
	// -- python 에 보내줘야 할지도 모르니까...

	// -- 특정 플레이어의 남은 실행 횟수를 차감
	player->set_currentControlCnt(player->get_currentControlCnt()-1);

	// -- 지역마다 소유 정보 점검하여 최대 턴 수 조정	
	// 모든 플레이어의 자신의 최대 실행횟수 다시 연산하도록 명령
	calculateAndSetAllPlayersMaxCommandCnt();
}

//// methods - flow management
// 한 플레이어의 턴이 종료되었을 때 수행
void Master::playerTurnEnd(Player *player)
{
	// 목적 : 이 플레이어의 동작 마무리 및 갱신
	set_gameState("playerTurnEnd");

	Sleep(2000);
}

//// methods - flow management
// 모든 플레이어의 턴이 종료되었을 때 수행
void Master::turnCycleEnd()
{
	// 목적 : 모든 플레이어의 차례가 끝났을 때
	set_gameState("turnCycleEnd");

	// -- 플레이어의 멸망을 체크
	checkAllPlayersAlive();

	// -- 마스터가 보유하고 있는 턴 수 조정
	increase_turnPassed();
	reduce_turnAvailable();
}

//// methods - flow management
// 한 판이 끝났을 때 수행
void Master::gameEnd()
{
	// 목적 : 게임이 끝났을 때 동작을 처리
	set_gameState("gameEnd");	

	// -- Dashboard
	system("cls");
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "게임 종료!" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;

	// ---- Dashboard : 성 개수
	int myplace_cnt;
	int myplace_score;
	int myplace_score_weight = 1000;
	for (int i = 1; i <= _player_cnt; i++)
	{
		myplace_score = 0;
		myplace_cnt = 0;
		int* myplace_arr = _player[i]->get_myPlace();
		for (int j = 0; j < 25; j++)
		{
			if (myplace_arr[i] == 1) myplace_cnt++;
		}
		myplace_score = myplace_score_weight * myplace_cnt;
		cout << myplace_score << "점 :: " << _player[i]->get_player_name() << " 의 최종 보유 성 : " << myplace_cnt << " 개 *" << myplace_score << endl;
		_player_score[i] += myplace_score;
	}
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;
	
	// ---- Dashboard : 자원
	int myresource_score;
	int myresource_gold_weight = 3;
	for (int i = 1; i <= _player_cnt; i++)
	{
		myresource_score = 0;

		Resource* myresource = _player[i]->get_myResource();
		for (int j = 0; j < 3; j++)
		{
			myresource_score = myresource_gold_weight*(myresource->get_resource_gold()) + myresource->get_resource_food() + myresource->get_resource_water();
		}
		cout << myresource_score << "점 :: " << _player[i]->get_player_name() << " 의 최종 자원, 산출근거 : (" << myresource_gold_weight << "*금+음식+자원)" << endl;
		_player_score[i] += myresource_score;
	}
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;

	// ---- Dashboard : 자원
	for (int i = 1; i <= _player_cnt; i++)
	{
		cout << _player_score[i] << "점 :: " << _player[i]->get_player_name() << " 의 최종 점수" << endl;
	}
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;


	// ---- Dashboard : 결과 출력
	int maxindex = 0;
	int maxscore = 0;
	for (int i = 1; i <= _player_cnt; i++)
	{
		if (i == 1) maxscore = _player_score[i];
	
		if (_player_score[i] > maxscore)
		{
			maxscore = _player_score[i];
			maxindex = i;
		}
	}

	cout << "player " << _player[maxindex]->get_player_name() << "가 한강 유역의 지배자가 되었습니다!" << endl;
	cout << endl;
	cout << "hanpotamia" << endl;

	delete[] _player_score;
}


//// methods - gmae explanation
void Master::showGameDiscription()
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "남은 턴  / 총 턴 : " << get_turnAvailable() << "/" << get_turnPassed() + get_turnAvailable() << endl;
	for (int i = 1; i <= _player_cnt; i++)
	{
		cout << "player " << i << " 이름 : " << _player[i]->get_player_name() << endl;
	}
	cout << "(총 " << get_playerCnt() << " 명)" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■" << endl;
}


//// methods - rule management
void Master::readMaxCommandCntAndResetCommandCnt(Player *player)
{
	int max_command_cnt = player->get_maxControlCnt();
	player->set_currentControlCnt(max_command_cnt);
}


//// methods - rule management
// 모든 플레이어를 대상으로 그 플레이어가 최대로 플레이할 수 있는 턴을 다시 연산해서 각 플레이어의 변수에 넣어줌.
void Master::calculateAndSetAllPlayersMaxCommandCnt()
{
	int myplace_cnt;
	int user_max_control_cnt;

	for (int i = 1; i < _player_cnt; i++)
	{
		myplace_cnt = 0;
		int* myplace_arr = _player[i]->get_myPlace(); // return : [0,1,0,0,0,1,0...]
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

		_player[i]->set_maxControlCnt(user_max_control_cnt);
	}
}


//// methods - rule management
// 모든 플레이어를 대상으로 그 플레이어가 멸망하지 않았는지 확인해줌.
void Master::checkAllPlayersAlive()
{
	int myplace_cnt;
	for (int i = 1; i < _player_cnt; i++)
	{
		myplace_cnt = 0;
		int* myplace_arr = _player[i]->get_myPlace(); // return : [0,1,0,0,0,1,0...]
		for (int j = 0; j < 25; j++)
		{
			if (myplace_arr[i] == 1) myplace_cnt++;
		}
		if (myplace_cnt == 0)
		{
			set_isPlayerAlive(i, false);
		}
	}
}


//// methods - utilities
bool Master::isVaildArea(string areaname)
{
	return _gamemap->isTrue(areaname);
}