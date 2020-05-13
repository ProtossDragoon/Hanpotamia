#include "player.h"

void Player::show_ab() {
    cout << Player::a << endl << Player::b;
}

void Player::set_ab(int a, int b) {
    Player::a=a;
    Player::b=b;
}