#pragma once
#include"map.h"
#include"player.h"
#include"resource.h"
#include"unit.h"

#include<iostream>
using namespace std;

class Master
{
private:
	
	string _game_state;
	int _player_cnt;
	Player _player[5];  //< 플레이어 수 최대 : 4 (1~4), [0] 은 컴퓨터
	bool _is_player_alive[5];
	int _turn_passed;
	int _turn_available;

protected:

	/* protected 멤버가 존재하지 않음. */

public:
	
	//// Constructor
	Master(int initial_player_cnt);

	//// Getter & Setter
	/// Getter
	int get_playerCnt() const { return _player_cnt; };
	Player &get_player(int number) { return _player[number]; };
	int get_trunPassed() const { return _turn_passed; };
	int get_turnAvailable() const {return _turn_available; };
	/// Setter
	// void set_playerCnt(); // do not use
	// void set_player(); // do not use
	void set_turnPassed(int turn) { _turn_passed = turn;  };
	void set_turnAvailable(int turn) { _turn_available = turn; };

	//// methods - system & alert 
	void consoleSend(string, bool);

	//// methods - flow management
	void gameStart();
	void turnCycleStart();
	int playerTrunStart(Player);
	void playerActionStart(Player);
	void playerActionEnd(Player);
	void playerTurnEnd(Player);
	void turnCycleEnd();
	void gameEnd();

	//// methods - rule management
	void calculateAllPlayersMaxCommandCnt();
	void checkAllPlayersAlive();
};