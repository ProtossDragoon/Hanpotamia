#include "master.h"
#include "player.h"

// extern master
extern Master game_master;

///Creator

Player::Player(string player_name, int current_control_time, int max_control_time) {
    _player_name=player_name;
    _current_control_time=current_control_time;
    _max_control_time=max_control_time;
    _my_resource.set_resource_food(0);
    _my_resource.set_resource_gold(0);
    _my_resource.set_resource_water(0);
}
////setter

void Player::set_maxControlCnt(int user_max_control_cnt) {
    _max_control_time=user_max_control_cnt;
}

void Player::set_currentControlCnt(int user_current_control_cnt) {
    _current_control_time=user_current_control_cnt;
}

void Player::set_player_name(string name) {
    _player_name=name;
}

void Player::discount_currentControlCnt() {
    if(get_currentControlCnt()>0)
        _current_control_time--;

    if(_current_control_time<=0)
        cout << "조작 가능 횟수를 초과했습니다." << endl;
}

void Player::set_my_resource(int Food, int Gold, int Water) {
    this->_my_resource.set_resource_food(Food);
    this->_my_resource.set_resource_gold(Gold);
    this->_my_resource.set_resource_water(Water);
}

////getter
Resource* Player::get_myResource() {
    return &_my_resource;
}

int * Player::get_myPlace() {
    Map *searching = game_master.get_gameMap();
    int *myPlace=searching->get_wholeArea(this);
    return myPlace; ////int 형 배열로 자신이 소유하는 전체 지역 반환
}

int Player::get_maxControlCnt() {
    return _max_control_time;
}

int Player::get_currentControlCnt() {
    return _current_control_time;
}

string  Player::get_player_name() {
    return this->_player_name;
}

//// game function
void Player::selectAction() {
    Resource *research;
    //// produce_unit
    string tendency; int product_count; string area;

    ////move or attack
    string from, to;

    ////Upgrade area
    int command;


    ////searching Unit

    // 보유 성을 기본으로 출력하게 해주세요.
    cout << this->get_player_name() << " >> 남은 동작 횟수 : " << get_currentControlCnt() << "/" << get_maxControlCnt() << endl;
    cout << "=========== 동작을 선택하세요 =============" << endl;
    cout << "0. [turn -1] 지역점령 " <<endl;
    cout << "1. [turn -1] 유닛생산 " <<endl;
    cout << "2. [turn -1] 이동 및 공격 "<<endl;
    cout << "3. [turn -1] 지역 업그레이드 " <<endl;
    cout << "4. 보유 지역 조회 " << endl;
    cout << "5. 보유 자원 조회 " << endl;
    cout << "6. 보유 병력 조회 " << endl;

    cin >> command;
    if(command == 0 ) {
        // fixme : 점령받을 지역을 선택하기 이전에 
        // 먼저 내가 가지고 있는 병력이 어디있는지부터 확인해야하는 것 아님?
        // 동작 수정 요청 : 나의 병력이 존재하는 곳들을 확인하고,
        // 나의 병력이 존재하는 곳들의 지역이 아무의 소유도 되지 않은 지역임을 확인
        // 아무도 점령하지 않은 지역이면, 해당 지역 목록을 화면에 출력
        cout << " 점령 할 지역을 선택하세요 " << endl;
        cin >> area;
        conquerArea(area);
    }

    if(command == 1 ) {
        // fixme : 내가 가지고 있는 지역에서 병력을 생산할 수 있는 것이니까
        // 내가 가지고 있는 지역을 먼저 display 하고, 해당 목록에서 번호를 선택해서
        // 하는 방식이 맞을것같은데, 병력 병과부터 먼저 고르면 안된다고봄.

        cout << " 병과를 선택하세요 " << endl ; // 예시 보여주기
        cin >> tendency;
        cout << " 생산할 병력의 수를 입력하세요 " << endl;
        cin >> product_count;
        cout << " 배치 할 지역을 입력하세요 " << endl;
        cin >> area;
        produce_unit(tendency, product_count, area);
    }

    if(command == 2 ){
        // 이동 가능 지역 Display 해주자 !!
        // fixme : 이것도 마찬가지로, 내가 가지고 있는 병력들이 먼저 떠야할듯
        // ex. 
        // 1. [보병 500] : 노원
        // 2. [궁병 1000] : 마포대교
        // 그 중에서 이동가능 지역을 선택할 수 있게 해주는 것이 더 옳을듯?
        cout << " 이동 가능 지역 " << endl;
        display_movableArea();
        cout << " 병력을 이동 시킬 지역을 입력하세요 " << endl;
        cout << " From : " ;
        cin >> from;
        cout << " To : ";
        cin >> to;
        MoveOrAttack_unit(from,to);
    }

    if(command==3){
        // fixme : 업그레이드 할 수 있는 지역 목록을 먼저 보여주고,
        // 해당 목록에서 업그레이드할 지역을 선택하는 것이 맞을듯.

        cout << "업그레이드 할 지역을 입력하세요 " << endl;
        cin >> area;
        upgradeArea(area);
    }

    if(command== 4 ){
        cout << " 1. 전체 지역 정보 조회    2. 단일 지역 정보 조회 " <<endl;
        cin >> command;
        if(command == 1 ){
            show_myWholePlace(game_master.get_gameMap()->get_wholeArea(this));
        }
        if(command == 2){
            cout << "지역이름을 입력하세요 :" ;
            cin >> area;
            game_master.get_gameMap()->showAreaInformation(area);
        }
    }

    if(command == 5){
        cout << "보유하고 있는 자원 " <<endl;
        show_myResource();
    }

    if(command == 6){
        Map *searching = game_master.get_gameMap();
        Army army;
        cout << "1. 전체 보유 병력 조회     2. 단일 지역 병력 조회" <<endl;
        cin >> command ;
        if(command ==1 ){
            army=searching->get_unitWhole(this);
            cout << " 보병 : " << army.Infantrycount << endl;
            cout << " 수군 : " << army.Navycount << endl;
            cout << " 기병 : " << army.Cavalrycount << endl;
            cout << " 궁병 : " << army.Archercount << endl;
            //unitWhole 에서 병종 구분 필요
        }

        if(command == 2) {
            cin >> area;
            //지역이름으로 해당 지역 정보 가져와서 해당 지역 병력 정보 Display
            if(is_yourArea(area)){
                army=searching->get_unit(area,this);
                cout << " 보병 : " << army.Infantrycount<< endl;
                cout << " 수군 : " <<  army.Navycount << endl;
                cout << " 기병 : " << army.Cavalrycount<<endl;
                cout << " 궁병 : " << army.Navycount << endl;
            }
            else
                cout << area << "지역은 " << this->get_player_name() << "가 소유한 땅이 아닙니다."<< endl;
        }
    }
}


void Player::produce_unit(string tendency, int product_count, string area) {
    Resource *research = NULL;
    areainformation set_product;
    set_product=game_master.get_gameMap()->get_areaInformation(area);

   if(research->check_resource(this->get_myResource(),research->calculate_produce_unit(tendency,product_count))){
       ////자원확인
       if (research->check_resource(this->get_myResource(), this->get_myResource())) {
           if (this->is_yourArea(area)) {
               if (tendency == "Navy")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Navycount + product_count);

               if (tendency == "Infantry")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Infantrycount + product_count);

               if (tendency == "cabalry")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Cavalrycount + product_count);

               if (tendency == "Archer")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Archercount + product_count);

               success_procedure("유닛생산완료");
               discount_currentControlCnt();
           }
       }
   }
   else cout << tendency << "유닛을 생산할 수 없습니다. ( SYS : 자원부족 )" << endl;
}

void Player::MoveOrAttack_unit(string from, string to) {
    if(!game_master.get_gameMap()->get_occupationPlayer(to).empty()) {
        fight(from, to);
    } else move(from,to);
}

bool Player::fight(string from_area, string to_area) {
    int sum_HP;
    Unit *fightUnit=NULL;
    int count_attacker;
    string attack_Unit, under_attack_Unit;
    //공격하려는 Unit 과 공격당하는 Unit 의 공격력을 더해서 서로 차감하고
    //해당 체력에 관해 modulo 연산으로 남은 유닛을 반영한다.

    while(attack_Unit.data() && under_attack_Unit.data()) { //string 함수중 Data , c_str Data 함수 사용 오류나면 c_str 함수 사용해보자
        cout << "자신의 공격 할 병과를 입력하세요" << endl;
        cin >> attack_Unit;
        cout << "공격 할 병력의 수를 입력하세요 " << endl;
        cin >> count_attacker;

        if(is_attackableArea(attack_Unit,from_area,to_area)) {
            cout << "해당 지역의 공격 대상을 입력하세요" << endl;
            cin >> under_attack_Unit;
            fightUnit->calculate_unit(to_area,under_attack_Unit,attack_Unit,count_attacker);
            ////유닛함수에서 작성하기로 햇음. -> set_Unit 까지.
            discount_currentControlCnt();
            return true;
        }
        else
            cout << "선택한 유닛은 해당 지역을 공격할 수 없습니다. (SYS : 사거리 부족 )" << endl;
    }
    return false;
}

void Player::move(string from, string to) {
    string tendency;
    int count;

    //움직일 병과를 입력하세요
    cin >> tendency;
    //움직일 병력의 수를 입력하세요
    cin >> count;

    if(is_movableArea(tendency,from,to)){
        game_master.get_gameMap()->set_unit(to,tendency,count);
        cout << count << " 명의 " << tendency << " (이)가 " << to << " 지역에 주둔합니다. " << endl;
        cout << "===========>> 지역의 소유권을 얻기 위해서 Conquer 하십시오 <<=============" <<endl;
        discount_currentControlCnt();
    } else cout << "선택한 유닛은 해당 지역으로 움직일 수 없습니다. (SYS : 이동 거리 부족 )" << endl;

}


void Player::upgradeArea(string area) {
    // 지역업그레이드 함수
    Resource upgradecost;
    areainformation levelTest=game_master.get_gameMap()->get_areaInformation(area);

    upgradecost.set_resource_water(100);
    upgradecost.set_resource_gold(100);
    upgradecost.set_resource_food(100);

    if(levelTest.arealevel==1) {
        ////자원확인
        if(upgradecost.check_resource(this->get_myResource(),&upgradecost)) {
            game_master.get_gameMap()->upgrade_Area(area);
            discount_currentControlCnt();
            success_procedure("지역 업그레이드");
        }
    }else cout << "업그레이드 실패 . (SYS : 자원 부족 ) " << endl;
    if(levelTest.arealevel==2){
        if(upgradecost.check_resource(this->get_myResource(),&upgradecost)) {
            game_master.get_gameMap()->upgrade_Area(area);
            discount_currentControlCnt();
            success_procedure("지역 업그레이드");
        }
    }else cout << "업그레이드 실패 . (SYS : 자원 부족 ) " << endl;

    if(levelTest.arealevel==3){
       cout << "업그레이드 실패 . (SYS : 이미 최대 레벨 입니다. )" << endl;
    }
}


// void conquerArea() : 플레이어가 특정 지역 점령을 명령했을 때 수행되는 함수.
// fixme : 얘가 어디서부터 어디까지 할건데?
void Player::conquerArea(string areaName) {
    Resource research= this->_my_resource;
    areainformation setting;
    //areaName 으로 단일 지역에 대해 this 포인터로 지역 소유권 확립
    
    // fixme : 지역 점령 시 로직 구현
    // 지역 점령 명령 동작을 이용자로부터 입력받았을 때,
    // 이용자의 병력이 존재하는 지역 중 점령당하지 않은 지역을 반환해야 함.
    // 그런데, 지금은 그냥 나의 병력이 존재하지 않는 지역도 입력을 받고 봄.

    if(is_yourArea(areaName)) {
        ////자원확인
        if(research.check_resource(this->get_myResource(),game_master.get_gameMap()->get_occupationCost(areaName))) {
            setting = game_master.get_gameMap()->get_areaInformation(areaName);
            setting.areahost = this->get_player_name();
            success_procedure("지역 정복");
            cout << "이제부터 " << areaName << " 지역을 " << this->get_player_name() << "님이 소유 합니다." << endl;
            discount_currentControlCnt();
            ////자원획득
            this->set_my_resource(
                    this->get_myResource()->get_resource_food() + setting.arearesource->get_resource_food(),
                    this->get_myResource()->get_resource_gold() + setting.arearesource->get_resource_gold(),
                    this->get_myResource()->get_resource_water() + setting.arearesource->get_resource_water());
            show_myResource();
        }
    }else cout << " 지역 점령에 실패 했습니다. (SYS : 자 원 부 족 ) " << endl ;
}


void Player::display_movableArea() {

    string area;
    string *movableArea=nullptr;

    //while 문으로 보여주기
    cout << "이동가능한 지역을 조회 할 지역을 입력하세요  :";
    cin >> area;

    if(game_master.get_gameMap()->get_occupationPlayer(area)!=this->_player_name)
        cout << "자신의 지역이 아닙니다. " << endl;

    else {
        movableArea = game_master.get_gameMap()->get_movableArea(area);
        if (movableArea) {
            cout << *movableArea << endl;
            movableArea++;
        }
    }
}

bool Player::is_yourArea(string area) {

    if(game_master.get_gameMap()->get_occupationPlayer(area)!=this->_player_name) {
        cout << "자신의 지역이 아닙니다. " << endl;
        return false;
    }

    if(game_master.get_gameMap()->get_occupationPlayer(area)!=this->_player_name) {
        cout << "자신의 지역이 아닙니다. " << endl;
        return false;
    }
    return true;
}

////attackableArea(string attack_unit , string attack_area); 이런식으로 해야할 것 같은데
////attack_area 에서 attack_unit 으로 공격할 수 있는 지역 Display. 사거리 n 으로.
////이동함수에서도 작성 가능 함.

bool Player::is_attackableArea(string attack_Unit, string from_area, string to_area) {
    if(attack_Unit == "Archer" /*Unit_Archer*/)
    {
        Unit_Archer infor;

        if(infor.get_attack_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    else if(attack_Unit == "Navy") /*Unit_Navy*/{
        Unit_Navy infor;

        if(infor.get_attack_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    else if(attack_Unit == "Cavalry")/*Unit_Cavalry)*/{
        Unit_Cavalry infor;

        if(infor.get_attack_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    else if(attack_Unit == "Infantry")/*Unit_Infantry)*/{
        Unit_Infantry infor;

        if(infor.get_attack_range()>=game_master.get_gameMap()->attackable(from_area, to_area))

            return true;
        else
            return false;

    }
    return false;
}

void Player::success_procedure(string type) {
    cout << type << " 작업을 성공적으로 수행 했습니다." << endl;
}

void Player::show_myResource() {
    cout << " 물 : " << get_myResource()->get_resource_water()  <<endl ;
    cout << " 금 : " << get_myResource()->get_resource_gold() <<endl ;
    cout << "음식 : " << get_myResource()->get_resource_food() <<endl;
}

void Player::show_myWholePlace(int *place) {

    cout << this->get_player_name() << "가 소유하는 지역을 조회합니다...." << endl;
    cout << this->get_player_name() << " 님이 소유하는 지역 " << endl;
    for(int i=0; i<30; i++,place++){
        if(*place=0)
            cout <<  game_master.get_gameMap()->findArea(place[i]).areaname << endl;
    }
}

bool Player::is_movableArea(string moving_Unit, string from_area, string to_area) {
    if(moving_Unit == "Archer" /*Unit_Archer*/)
    {
        Unit_Archer infor;

        if(infor.get_moving_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    else if(moving_Unit == "Navy") /*Unit_Navy*/{
        Unit_Navy infor;

        if(infor.get_moving_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    else if(moving_Unit == "Cavalry")/*Unit_Cavalry)*/{
        Unit_Cavalry infor;

        if(infor.get_moving_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    else if(moving_Unit == "Infantry")/*Unit_Infantry)*/{
        Unit_Infantry infor;

        if(infor.get_moving_range()>=game_master.get_gameMap()->attackable(from_area,to_area))

            return true;
        else
            return false;

    }
    return false;
}


