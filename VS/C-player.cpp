#include "player.h"
#include "map.h"


//setter
void Player::set_maxcontrol_time(int count) {
    max_control_time=count;
}
void Player::set_play_name(char *name) {
    player_name=name;
}

//getter
Resource* Player::get_my_resource() {
   Resource searching;

   //searching.getResource(player_name);
   //cout << searching.water, gold, food etc ....
   return searching;
}

Unit* Player::get_my_unit() {
    Unit searching;
   //searching.getUnit(player_name);
   //cout << present status on Unit
   return searching;
}


Map * Player::get_my_place() {
    Map searching;
    searching.get_occupationPlayer(); //player_name;
    return searching;
}

int Player::get_my_control_time() {
    return now_control_time;
}

// game function
Unit Player::produce_unit(char *tendency, int product_count) {
    Unit pro;
    //pro.product(tendency, product_count); 유닛 성격 ( 병과) , 생산 개수 지정
}
