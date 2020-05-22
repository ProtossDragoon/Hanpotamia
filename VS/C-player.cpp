#include "player.h"
#include "map.h"


//setter
void Player::set_maxControlCnt(int user_max_control_cnt) {
    _max_control_time=user_max_control_cnt;
}

void Player::set_nowControlCnt(int user_now_control_cnt) {
    _now_control_time=user_now_control_cnt;
}
void Player::set_player_name(char *name) {
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


int * Player::get_my_place() {
    Map searching;
    return searching.get_occupationPlayer(this->player_name); //player_name;
}

int Player::get_my_control_time() {
    return _now_control_time;
}

char* Player::get_player_name() {
    return this->player_name;
}

// game function
Unit Player::produce_unit(char *tendency, int product_count, char *area,char *playername) {
    Unit pro;
    Map collocate;
    //pro.product(tendency, product_count); 유닛 성격 ( 병과) , 생산 개수 지정 => Player 정보 조회해서 생산가능한지 검사
    //pro 객체에 생산 된 Unit 정보 있음.
    //Map 함수에 생산한 병력 배치할 함수 필요 (Unit product, char * area) 인자 => Player Name 검사해서 병력 생산 가능 구역인지 확인
    return pro;
}

void Player::MoveOrAttack_unit(char *from, char *to) {
    Map searching;
    //모든 클래스에서 get_player_name 이 존재해야할 것 같다.

    //myplace.moveUnit(from,to); => 이동가능 구역인지 검사 필요.
    //Player name 을 인자로 모든 지역의 병력 조회 가능해야 함
    //Player name , area name  을 인자로 해당 지역의 병력 조회(어떤 병사가 있는지, 몇 명 있는지) 가능해야함

    //to 지역의 Player 정보(병력 정보 , 지역 레벨 ) 조회 => 다른 Player 가 존재하면 공격
    fight(from,to);
    //싸우지 않았다면 해당 지역에서 병력 차감하고, 다른 지역에 병력 추가
    move(from,to);
}

void Player::fight(char *from_area, char *to_area) {
    int sum_HP;
    int count_attacker;
    char *attack_Unit, *under_attack_Unit;
    //공격하려는 Unit 과 공격당하는 Unit 의 공격력을 더해서 서로 차감하고
    //해당 체력에 관해 modulo 연산으로 남은 유닛을 반영한다.
    while(attack_Unit != NULL && under_attack_Unit != NULL ) {
        cout << "공격 할 병과를 입력하세요" << endl;
        cin >> attack_Unit;
        cout << "공격 할 병력의 수를 입력하세요 " << endl;
        cin >> count_attacker;

        cout << "공격 대상을 입력하세요" << endl;
        cin >> under_attack_Unit;
    }
    //player name 과 area name, Unit_tendency, Unit_count 가 모두 필요함.
    //sum_HP 만 fight 함수에서 계산해서 넘겨준다. //
    /*------------------------------------------------------------*/
    calculate_Unit(10000,attack_Unit,from_area);
    calculate_Unit(10000,under_attack_Unit,to_area);
}

void Player::calculate_Unit(int sum_HP, char *Unit_tendency, char *area) {

    //area name, Unit tendency, Unit_count 를 인자로 해당 지역의 병력 변경 가능해야함
    if(sum_HP<0)
        cout << "해당 병력을 몰살 했습니다." <<endl;
    else{
       //Unit_tendency 에 따라서 if 문으로 sum_HP 를 modulo 연산하고
       //set_Unit(area, tendency, count) 로 병력 set
    }
}

void Player::move(char *from, char *to) {
    Map searching;
    char *tendency;
    int count;

    //움직일 병과를 입력하세요
    cin >> tendency;
    //움직일 병력의 수를 입력하세요
    cin >> count;

    //searching.set_Unit(from, tendency , 원래있던 병과의 수 - count);
    //searching.set_Unit(to, tendency , count);
}