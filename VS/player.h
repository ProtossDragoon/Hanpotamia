#include <iostream>
#include "resource.h"
#include "unit.h"
#pragma once

using namespace std;
class Player
{
private:
    char *player_name;
    int max_control_time;
    int now_control_time;


public :
    //setter
    void set_play_name(char *name);
    void set_maxcontrol_time(int count);

    //getter
    //Output 각 클래스별 배열 ( 배열의 첫 번쨰 주소 Return)
    Map *get_my_place();
    Resource *get_my_resource();
    Unit *get_my_unit();

    //Turn getter
    int get_my_control_time();

    //Control Function
    //병과, 생산 수 인자로 넘김
    Unit produce_unit(char *tendency, int product_count);
    void move_unit(char *from, char *to);
};



