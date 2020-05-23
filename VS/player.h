#include <iostream>
#include "resource.h"
#include "unit.h"
#pragma once

using namespace std;
class Player
{
private:
    char *player_name;
    int _max_control_time;
    int _now_control_time;


public :
    //setter
    void set_player_name(char *name);
    void set_maxControlCnt(int user_max_control_cnt);
    void set_nowControlCnt(int user_now_control_cnt);
    //getter
    //Output 각 클래스별 배열 ( 배열의 첫 번쨰 주소 Return)
    int *get_my_place();
    Resource *get_my_resource();
    Unit *get_my_unit();
    char *get_player_name();
    //Turn getter
    int get_my_control_time();

    //Control Function
    //병과, 생산 수 인자로 넘김
    Unit produce_unit(char *tendency, int product_count,char *area, char *playername);
    void MoveOrAttack_unit(char *from, char *to);
    void fight(char *from_area, char *to_area);
    void move(char *from_area, char *to_area);
    void calculate_Unit(int sum_HP, char *Unit_tendency, char *area);
};

// 추가요청
// player.get_myPlace(); // return : [0,1,0,0,0,1,0...
// player.get_maxControlCnt();
// player.get_nowControlCnt();
