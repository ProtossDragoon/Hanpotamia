#include "player.h"


///Creator
Player::Player(string player_name, int _now_control_time, int _max_control_time) {
    player_name=player_name;
    _now_control_time=_now_control_time;
    _max_control_time=_max_control_time;
}
////setter
void Player::set_maxControlCnt(int user_max_control_cnt) {
    _max_control_time=user_max_control_cnt;
}

void Player::set_nowControlCnt(int user_now_control_cnt) {
    _now_control_time=user_now_control_cnt;
}
void Player::set_player_name(string name) {
    player_name=name;

}
void Player::discount_nowControlCnt() {
    if(_now_control_time>0)
        _now_control_time--;
    if(_now_control_time<=0)
        cout << "조작 가능 횟수를 초과했습니다." << endl;
}

void Player::set_my_resource(int Food, int Gold, int Water) {
    this->_my_resource.setFood();
    this->_my_resource.setGold();
    this->_my_resource.setWater();
}

////getter
Resource* Player::get_my_resource() {
  return &_my_resource;
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

int Player::get_maxControlCnt() {
    return _max_control_time;
}

int Player::get_nowControlCnt() {
    return _now_control_time;
}

string  Player::get_player_name() {
    return this->player_name;
}

//// game function
void Player::selectAction() {
    //// produce_unit
    string tendency; int product_count; string area;

    ////move or attack
    string from, to;

    ////Upgrade area


    int command;
    cout << "=========== 동작을 선택하세요 =============" << endl;

    cout << " 1. 유닛생산 " <<endl;
    cout << " 2. 이동 및 공격 "<<endl;
    cout << " 3. 지역 업그레이드 " <<endl;
    cout << " 4. 보유 지역 조회 " << endl;
    cout << " 5. 보유 자원 조회 " << endl;
    cout << " 6. 보유 병력 조회 " << endl;

    cin >> command;

    if(command == 1 ) {
        cout << " 병과를 선택하세요 " << endl ; //예시 보여주기
        cin >> tendency;
        cout << " 생산할 병력의 수를 입력하세요 " << endl;
        cin >> product_count;
        cout << " 배치 할 지역을 입력하세요 " << endl;
        cin >> area;
        produce_unit(tendency, product_count, area, this->player_name);
    }

    if(command == 2 ){
        cout << " 병력을 이동 시킬 지역을 입력하세요 " << endl;
        cout << " From : " ;
        cin >> from;
        cout << " To : ";
        cin >> to;
        MoveOrAttack_unit(from,to);
    }

    if(command==3){
        cout << "업그레이드 할 지역을 입력하세요 " << endl;
        cin >> area;
        upgradeArea(area);
    }

    if(command== 4 ){
        cout << " 1. 전체 지역 정보 조회    2. 단일 지역 정보 조회 " <<endl;
        cin >> command;
        if(command == 1 ){

        }
        if(command == 2){

        }
    }

    if(command == 5){
        get_my_resource();
    }

    if(command == 6){
        cout << "1. 전체 보유 병력 조회     2. 단일 지역 병력 조회" <<endl;

    }
}


Unit Player::produce_unit(string tendency, int product_count, string area,string playername) {
    Unit pro;
    //pro.product(tendency, product_count); 유닛 성격 ( 병과) , 생산 개수 지정 => Player 정보 조회해서 생산가능한지 검사
    //pro 객체에 생산 된 Unit 정보 있음.
    ////Map 함수에 생산한 병력 배치할 함수 필요 (Unit product, string  area) 인자 => Player Name 검사해서 병력 생산 가능 구역인지 확인
    //set_Unit()
    return pro;
}

void Player::MoveOrAttack_unit(string from, string to) {
    Map searching;
    //모든 클래스에서 get_player_name 이 존재해야할 것 같다.

    //Player name 을 인자로 모든 지역의 병력 조회 가능해야 함
    ////Player name , area name  을 인자로 해당 지역의 병력 조회(어떤 병사가 있는지, 몇 명 있는지) 가능해야함

    //to 지역의 Player 정보(병력 정보 , 지역 레벨 ) 조회 => 다른 Player 가 존재하면 공격
    fight(from,to);
    //싸우지 않았다면 해당 지역에서 병력 차감하고, 다른 지역에 병력 추가
    move(from,to);
}

void Player::fight(string from_area, string to_area) {
    Map searching();
    Unit fight;
    int sum_HP;
    int count_attacker;
    string attack_Unit, *under_attack_Unit;
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
    ////*------------------------------------------------------------*/////

    //sum_HP = 공격하는 유닛 총 체력 - 공격 당하는 유닛 총 공격력
    //Map 함수에서 해당 지역이 소유하고 있는 병력 정보 get 가능해야 함.
    //Map 에서 병력 정보에 관한 데이터 필요 함.
    calculate_Unit(10000,attack_Unit,from_area);
    //sum_HP = 공격당하는 유닛 총 체력 - 공격하는 유닛 총 공격력
    calculate_Unit(10000,under_attack_Unit,to_area);
}

void Player::calculate_Unit(int sum_HP, string Unit_tendency, string area) {

    //area name, Unit tendency, Unit_count 를 인자로 해당 지역의 병력 변경 가능해야함
    if(sum_HP<0)
        cout << "해당 병력을 몰살 했습니다." <<endl;
    else{
       //Unit_tendency 에 따라서 if 문으로 sum_HP 를 modulo 연산하고
       ////set_Unit(area, tendency, count) 로 병력 set
    }
}

void Player::move(string from, string to) {
    Map searching();
    string tendency;
    int count;

    //움직일 병과를 입력하세요
    cin >> tendency;
    //움직일 병력의 수를 입력하세요
    cin >> count;

    ////searching.set_Unit(from, tendency , 원래있던 병과의 수 - count);
    ////searching.set_Unit(to, tendency , count);
}


void Player::upgradeArea(string area) {
    // 지역업그레이드 함수

}