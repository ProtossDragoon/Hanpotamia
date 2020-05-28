#include <iostream>
#include "resource.h"
#include "unit.h"
#include "map.h"


#pragma once

using namespace std;

class Player
{
private:
    string player_name;
    int _max_control_time;
    int _now_control_time;
    Resource _my_resource;

public :
    Player();
    Player(string player_name, int _now_control_time,int _max_control_time);

    //setter
    void set_player_name(string name);
    void set_maxControlCnt(int user_max_control_cnt);
    void set_nowControlCnt(int user_now_control_cnt);
    void set_my_resource(int Food , int Gold, int Water);
    void discount_nowControlCnt();

    //getter
    //Output 각 클래스별 배열 ( 배열의 첫 번쨰 주소 Return)
    int *get_myPlace();
    Resource *get_myResource();
    Unit *get_myUnit();
    string get_player_name();
    //Turn getter
    int get_maxControlCnt();
    int get_nowControlCnt();

    //Control Function
    //병과, 생산 수 인자로 넘김
    void selectAction();
    static Unit produce_unit(string tendency, int product_count,string area, string playername);
    void MoveOrAttack_unit(string from, string to);
    void fight(string from_area, string to_area);
    void move(string from_area, string to_area);
    void calculate_Unit(int sum_HP, string Unit_tendency, string area);
    void upgradeArea(string area);
};

// 추가요청
// player.get_myPlace(); // return : [0,1,0,0,0,1,0...
// player.get_maxControlCnt();
// player.get_nowControlCnt();
