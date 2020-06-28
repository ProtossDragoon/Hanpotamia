#include <iostream>
#include "resource.h"
#include "unit.h"
#include "map.h"
#pragma once


#define INTEGER 0 
#define CHARACTER '0'
#define STRING "str"

using namespace std;

class Player
{
private:
    string _player_name;
    int _max_control_time;
    int _current_control_time;
    Resource _my_resource;

public :
    Player(){_player_name = "입력필요" ; _max_control_time=0; _current_control_time=0;};
    Player(string player_name, int current_control_time ,int max_control_time);

    //setter
    void set_player_name(string name);
    void set_maxControlCnt(int user_max_control_cnt);
    void set_currentControlCnt(int user_current_control_cnt);
    void set_my_resource(int Food , int Gold, int Water);
    void discount_currentControlCnt();

    //getter
    //Output �??�래?�별 배열 ( 배열??�?번�? 주소 Return)
    int *get_myPlace();
    void show_myWholePlace(int place[]);

    Resource *get_myResource();
    void show_myResource();
    string get_player_name();
    //Turn getter
    int get_maxControlCnt();
    int get_currentControlCnt();

    //Control Function
    //병과, ?�산 ???�자�??��?
    template <typename inputtype>    
    inputtype inputWrapper(string);
    void selectAction();
    bool produce_unit(string tendency, int product_count,string area);
    void MoveOrAttack_unit(string from, string to);
    bool fight(string from_area, string to_area);
    void move(string from_area, string to_area);
    bool upgradeArea(string area);
    bool conquerArea(string areaName);
    void display_movableArea();
    bool is_yourArea(string area, bool vervose = true);
    static bool is_attackableArea(string attack_Unit, string from_area,string to_area);
    static bool is_movableArea(string moving_Unit, string from_area, string to_area);
    static void success_procedure(string type);
};

//// game function 에서 입력을 예쁘게 받기 위한 함수
template <typename inputtype>
inputtype Player::inputWrapper(string comment)
{
    inputtype input;
    cout << endl;
    cout << comment << " >>> ";
    cin >> input;
    cout << endl;
    return input;
}