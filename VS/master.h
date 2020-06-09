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
	static Map *gamemap;	
	string _game_state;
	int _player_cnt;
	Player *_player[5];  //< 플레이어 수 최대 : 4 (1~4), [0] 은 컴퓨터
	bool _is_player_alive[5];
	int _turn_passed;
	int _turn_available;

protected:

	/* protected 멤버가 존재하지 않음. */

public:
	
	//// Constructor & Destructor
	Master();
	~Master()
	{
		delete gamemap;
		delete[] _player; 	
	};

	//// Getter & Setter
	/// Getter
	string get_gameState() const { return _game_state; };
	int get_playerCnt() const { return _player_cnt; };
	Player* get_player(int number) { return _player[number]; };
	int get_trunPassed() const { return _turn_passed; };
	int get_turnAvailable() const {return _turn_available; };
	bool get_isPlayerAlive(int player) const { return _is_player_alive[player]; };
	bool get_isPlayerAlive(Player *player);

	/// Setter
	// void set_playerCnt(); // do not use
	// void set_player(); // do not use
	void set_gameState(string statename) { _game_state = statename; };
	void set_turnPassed(int turn) { _turn_passed = turn; };
	void set_turnAvailable(int turn) { _turn_available = turn; };
	void increase_turnPassed() { _turn_passed++; };
	void reduce_turnAvailable() { _turn_available--; };
	void set_isPlayerAlive(int player, bool isalive) { _is_player_alive[player] = isalive; };

	//// methods - system & alert 
	void consoleSend(string, bool);

	//// methods - flow management
	void gameReady(int initial_player_cnt);
	void turnCycleStart();
	int playerTrunStart(Player*);
	void playerActionStart(Player*);
	void playerActionEnd(Player*);
	void playerTurnEnd(Player*);
	void turnCycleEnd();
	void gameEnd();

	//// methods - gmae explanation
	void showGameDiscription();


	//// methods - rule management
	void readMaxCommandCntAndResetCommandCnt(Player*);
	void calculateAndSetAllPlayersMaxCommandCnt();
	void checkAllPlayersAlive();
};