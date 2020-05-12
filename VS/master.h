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
	Player _player[5]; 
	// max : 4 (1~4)
	// [0] : computer
	int _turn_passed;
	int _turn_available;

protected:

	/* no protected member */

public:
	
	/* Constructor */
	
	Master(int initial_player_cnt);


	/* Getter & Setter */
	
	int get_playerCnt() const { return _player_cnt; };
	Player get_player(int number) const { return _player[number]; };
	int get_trunPassed() const { return _turn_passed; };
	int get_turnAvailable() const {return _turn_available; };
	
	void set_playerCnt(); // do not use
	void set_player(); // do not use
	void set_turnPassed(bool);
	void set_turnAvailable();


	/* methods - system & alert */
	
	void consoleSend(string, bool);


	/* methods - flow management */

	void gameStart();
	void trunCycleStart();
	void playerTrunStart(Player);
	void playerTrunEnd(Player);
	void trunCycleEnd();
	void gameEnd();
};