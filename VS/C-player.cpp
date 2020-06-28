#include "master.h"
#include "player.h"
#include <string>
#include <iostream>

// extern master
extern Master game_master;

///Creator

Player::Player(string player_name, int current_control_time, int max_control_time) {
    _player_name=player_name;
    _current_control_time=current_control_time;
    _max_control_time=max_control_time;
    _my_resource.set_resource_food(200);
    _my_resource.set_resource_gold(200);
    _my_resource.set_resource_water(200);
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

int *Player::get_myPlace() {
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
    string tendency;
    int product_count;
    string area;

    ////move or attack
    string from, to;

    ////Upgrade area
    int command;
    bool command_notcompleted;


    ////searching Unit

    // 보유 성을 기본으로 출력하게 해주세요.
    cout << endl;
    cout << endl;
    cout << "=========== 부족장 상세 =============" << endl;
    cout << "부족장 " << this->get_player_name() << " >> 남은 동작 횟수 : " << get_currentControlCnt() << "/" << get_maxControlCnt() << endl;
  
    cout << "=========== 점령지 목록 =============" << endl;
    show_myWholePlace(game_master.get_gameMap()->get_wholeArea(this));

    cout << "=========== 자원   목록 =============" << endl;
    this->show_myResource();

    cout << "=========== 동작을 선택하세요 =============" << endl;
    cout << "0. [동작횟수 -1] 지역점령 " << endl;
    cout << "1. [동작횟수 -1] 유닛생산 " << endl;
    cout << "2. [동작횟수 -1] 이동 및 공격 " << endl;
    cout << "3. [동작횟수 -1] 지역 업그레이드 " << endl;
    cout << "4. 보유 지역 조회 " << endl;
    cout << "5. 보유 자원 조회 " << endl;
    cout << "6. 보유 병력 조회 " << endl;
    cout << "9. [동작횟수 -1] 실행 1회 넘기기" << endl;
    cout << endl;

    bool unitname_valid;
    bool areaname_valid;
        
    command = -1;
    command_notcompleted = true;
    while (command == -1 || command_notcompleted) {
        
        command_notcompleted = false;
        try
        {
            command = inputWrapper<int>("동작 선택");

            /*
            if (cin.fail())
            {
                std::cin.ignore(INT_MAX, '\n');
                cin.clear();
                rewind(stdin);
                command = -1;
            }
            */

            // command 0 : 
            if (command == 0) {
                if (game_master.get_gameMap()->show_conquerAbleArea(this->get_player_name()))
                {
                    area = inputWrapper<int>("점령 할 지역을 선택하세요");
                    command_notcompleted = conquerArea(area);
                }
                else
                {
                    cout << "책사 : 병력이 존재하지 않아 점령 가능한 지역이 없습니다. " << endl;
                    command_notcompleted = true;
                }
            }
            else if (command == 1)
            {
                cout << this->get_player_name() << "족장님이 소유하고 있는 지역 목록 ( 유닛 생산 가능 지역 목록 )" << endl;
                cout << "====================================================================" << endl;
                show_myWholePlace(game_master.get_gameMap()->get_wholeArea(this));
                cout << "====================================================================" << endl;

                cout << "[보병] Infantry  [궁병] Archery    [기병] Cavalry    [해병] Navy" << endl;

                tendency = inputWrapper<string>("책사 : 병과를 선택하세요");
                unitname_valid = game_master.isValidUnitTendency(tendency);

                if (unitname_valid)
                {
                    area = inputWrapper<string>("책사 : 배치 할 지역을 입력하세요");
                    areaname_valid = this->is_yourArea(area, false);
                    if (areaname_valid)
                    {
                        product_count = inputWrapper<int>("책사 : 생산할 병력의 수를 입력하세요");
                        command_notcompleted = produce_unit(tendency, product_count, area);
                    }
                    else
                    {
                        cout << "책사 : 족장님의 땅이 아니거나, 유효한 땅이 아닙니다!" << endl;
                        command_notcompleted = true;
                    }
                }
                else
                {
                    command_notcompleted = true;
                }
            }
            else if (command == 2)
            {
                cout << "이동 가능한 지역" << endl;
                cout << "====================================================================" << endl;
                display_movableArea();
                cout << "====================================================================" << endl;

                from = inputWrapper<string>("책사 : 어느 지역의 병력을 이동하시나요?");
                if (game_master.isVaildArea(from))
                {
                    to = inputWrapper<string>("책사 : 어디로 병력을 이동하시나요?");
                    if (game_master.isVaildArea(to))
                    {
                        // command_notcompleted = 
                        MoveOrAttack_unit(from, to);
                    }
                    else
                    {
                        command_notcompleted = true;
                    }
                }
                else
                {
                    command_notcompleted = true;
                }
            }
            else if (command == 3)
            {
                area = inputWrapper<string>("책사 : 업그레이드 할 지역명이 무엇인가요?");
                command_notcompleted = upgradeArea(area);
            }
            else if (command == 4)
            {
                command = inputWrapper<int>("1. 전체 지역 정보 조회    2. 단일 지역 정보 조회");
                if (command == 1)
                {
                    show_myWholePlace(game_master.get_gameMap()->get_wholeArea(this));
                }
                if (command == 2)
                {
                    area = inputWrapper<string>("정보를 조회할 지역명");
                    game_master.get_gameMap()->showAreaInformation(area);
                }
                command_notcompleted = true;
            }
            else if (command == 5)
            {
                cout << "보유하고 있는 자원 " << endl;
                show_myResource();
                command_notcompleted = true;
            }
            else if (command == 6)
            {
                Map* searching = game_master.get_gameMap();
                command = inputWrapper<int>("1. 전체 보유 병력 조회   2. 단일 지역 병력 조회");
                if (command == 1)
                {
                    Army army;
                    army = searching->get_unitWhole(this);
                    cout << " 보병 : " << army.Infantrycount << endl;
                    cout << " 수군 : " << army.Navycount << endl;
                    cout << " 기병 : " << army.Cavalrycount << endl;
                    cout << " 궁병 : " << army.Archercount << endl;
                    //unitWhole 에서 병종 구분 필요
                }
                if (command == 2)
                {
                    area = inputWrapper<string>("정보를 조회할 지역명");
                    if (is_yourArea(area))
                    {
                        Army army;
                        army = searching->get_unit(area, this);
                        cout << " 보병 : " << army.Infantrycount << endl;
                        cout << " 수군 : " << army.Navycount << endl;
                        cout << " 기병 : " << army.Cavalrycount << endl;
                        cout << " 궁병 : " << army.Navycount << endl;
                    }
                    else
                    {
                        cout << area << "지역은 " << this->get_player_name() << "가 소유한 땅이 아닙니다." << endl;
                    }
                }
                command_notcompleted = true;
            }
            else if (command == 9)
            {
                cout << "턴 넘기기" << endl;
            }
            else
            {
                command = -1;
                cout << "잘못된 입력입니다." << endl;
                command_notcompleted = true;
            }
        }
        catch (int e)
        {
            cin.ignore(INT_MAX, '\n');
            cin.clear();
            rewind(stdin);
            command_notcompleted = true;
            command = -1;
        }
    }
}




bool Player::produce_unit(string tendency, int product_count, string area) {
    Resource research = this->_my_resource;
    areainformation set_product;
    set_product=game_master.get_gameMap()->get_areaInformation(area);

   if(research.check_resource(this->get_myResource(),research.calculate_produce_unit(tendency,product_count))){
       ////자원확인
           if (this->is_yourArea(area)) {
               if (tendency == "Navy")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Navycount + product_count);
               else if (tendency == "Infantry")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Infantrycount + product_count);
               else if (tendency == "Cabalry")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Cavalrycount + product_count);
               else if (tendency == "Archer")
                   game_master.get_gameMap()->set_unit(area, tendency, set_product.areaunit.Archercount + product_count);
               else
               {
                   cout << "책사 : 족장님, 그게 무슨 유닛입니까?" << endl;
                   return true;
               }
               success_procedure("유닛생산완료");
               return false;
               //discount_currentControlCnt();
           }
           else
           {
               cout << "책사 : 족장님, 그곳은 저희 땅이 아닙니다!" << endl;
               return true;
           }
       }
   else 
   {
       cout << "책사 : 자원이 부족하여 " << tendency << " 를 생산할 수 없습니다!" << endl;
       return true;
   }
}

// fixme : 이거 유닛 없으면 우찌되는거임?
void Player::MoveOrAttack_unit(string from, string to) {
    if (game_master.get_gameMap()->get_occupationPlayer(to)!="\0") 
    {
        fight(from, to);
    } 
    else
    {
        move(from, to);
    }
}

bool Player::fight(string from_area, string to_area) {
    int sum_HP;
    Unit *fightUnit=NULL;
    int count_attacker;
    string attack_Unit, under_attack_Unit;
    //공격하려는 Unit 과 공격당하는 Unit 의 공격력을 더해서 서로 차감하고
    //해당 체력에 관해 modulo 연산으로 남은 유닛을 반영한다.

    while(attack_Unit.data() && under_attack_Unit.data()) 
    { //string 함수중 Data , c_str Data 함수 사용 오류나면 c_str 함수 사용해보자
        cout << "자신의 공격 할 병과를 입력하세요" << endl;
        cin >> attack_Unit;
        cout << "공격 할 병력의 수를 입력하세요 " << endl;
        cin >> count_attacker;

        if(is_attackableArea(attack_Unit,from_area,to_area)) 
        {
            cout << "해당 지역의 공격 대상을 입력하세요" << endl;
            cin >> under_attack_Unit;
            fightUnit->calculate_unit(to_area,under_attack_Unit,attack_Unit,count_attacker);
            ////유닛함수에서 작성하기로 햇음. -> set_Unit 까지.
            
            return true;
        }
        else
        {
            cout << "선택한 유닛은 해당 지역을 공격할 수 없습니다. (SYS : 사거리 부족 )" << endl;
        }
    }
    return false;
}

void Player::move(string from, string to) {
    string tendency;
    int count;
    int from_areaTendencyCount;


    if (this->is_yourArea(from)) {
        game_master.get_gameMap()->showAreaInformation(from);
        cout << endl << " 움직일 병과를 입력하세요 " << endl;
        cin >> tendency;
        cout << " 움직일 병력의 수를 입력하세요 " << endl;
        cin >> count;
        if (is_movableArea(tendency, from, to)) {

            game_master.get_gameMap()->set_unit(to, tendency, count);
            if (tendency == "Infantry")
                from_areaTendencyCount = game_master.get_gameMap()->get_areaInformation(from).areaunit.Infantrycount;

            if (tendency == "Archer")
                from_areaTendencyCount = game_master.get_gameMap()->get_areaInformation(from).areaunit.Archercount;

            if (tendency == "Cavalry")
                from_areaTendencyCount = game_master.get_gameMap()->get_areaInformation(from).areaunit.Cavalrycount;

            if (tendency == "Navy")
                from_areaTendencyCount = game_master.get_gameMap()->get_areaInformation(from).areaunit.Navycount;

            cout << count << " 명의 " << tendency << " (이)가 " << to << " 지역에 주둔합니다. " << endl;
            cout << "===========>> 지역의 소유권을 얻기 위해서 Conquer 하십시오 <<=============" << endl;
            game_master.get_gameMap()->set_unit(from, tendency, from_areaTendencyCount - count);
            game_master.get_gameMap()->set_SemiareaHost(this,to);

        } else cout << "선택한 유닛은 해당 지역으로 움직일 수 없습니다. (SYS : 이동 거리 부족 )" << endl;
    } else cout << "해당 지역의 유닛을 컨트롤 할 수 없습니다. (SYS : 지역의 호스트가 아닙니다. )" << endl;

}
bool Player::upgradeArea(string area) {
    // 지역업그레이드 함수
    Resource upgradecost;
    areainformation levelTest=game_master.get_gameMap()->get_areaInformation(area);

    upgradecost.set_resource_water(100);
    upgradecost.set_resource_gold(100);
    upgradecost.set_resource_food(100);

    if (levelTest.arealevel == 1) {
        ////자원확인
        if(upgradecost.check_resource(this->get_myResource(),&upgradecost)) 
        {
            game_master.get_gameMap()->upgrade_Area(area);
            success_procedure("지역 업그레이드");
            return false;
        }
        else
        {
            cout << "업그레이드 실패 . (SYS : 자원 부족 ) " << endl;
            return true;
        }

    }

    if(levelTest.arealevel == 2)
    {
        if(upgradecost.check_resource(this->get_myResource(),&upgradecost)) 
        {
            game_master.get_gameMap()->upgrade_Area(area);
            success_procedure("지역 업그레이드");
            return false;
        }
        else
        {
            cout << "업그레이드 실패 . (SYS : 자원 부족 ) " << endl;
            return true;
        }
    }

    if(levelTest.arealevel == 3)
    {
        cout << "업그레이드 실패 . (SYS : 이미 최대 레벨 입니다. )" << endl;
        return true;
    }
}


// void conquerArea() : 플레이어가 특정 지역 점령을 명령했을 때 수행되는 함수.
// fixme : 얘가 어디서부터 어디까지 할건데?
bool Player::conquerArea(string areaName) {
    Resource research= this->_my_resource;
    areainformation setting;
    //areaName 으로 단일 지역에 대해 this 포인터로 지역 소유권 확립
    
    // fixme : 지역 점령 시 로직 구현
    // 지역 점령 명령 동작을 이용자로부터 입력받았을 때,
    // 이용자의 병력이 존재하는 지역 중 점령당하지 않은 지역을 반환해야 함.
    // 그런데, 지금은 그냥 나의 병력이 존재하지 않는 지역도 입력을 받고 봄.


        if (game_master.get_gameMap()->get_areaInformation(areaName).areahost==this->get_player_name()+"(Semi)") {
            ////자원확인
            if (research.check_resource(this->get_myResource(),
                                        game_master.get_gameMap()->get_occupationCost(areaName))) {
                game_master.get_gameMap()->set_areaHost(this,areaName);
                success_procedure("지역 정복");
                cout << "이제부터 " << areaName << " 지역을 " << this->get_player_name() << "님이 소유 합니다." << endl;
                ////자원획득
                cout << endl << "============점령 한 지역으로 부터 자원을 획득합니다. ===============" << endl;
                this->set_my_resource(
                        this->get_myResource()->get_resource_food() + 100,
                        this->get_myResource()->get_resource_gold() +100,
                        this->get_myResource()->get_resource_water() + 100);
                show_myResource();
            } else {
                cout << "책사 : 자원이 부족하여 지역 점령을 하지 못합니다." << endl;
                return true; // 미완료 flag 세우기.
            }
        } else {
            cout << "책사 : 족장님의 병력이 주둔하는 지역이 아닙니다." << endl;
            return true; // 미완료 flag 세우기
        }

}


void Player::display_movableArea() {

    string area;
    string *movableArea;

    //while 문으로 보여주기
    cout << "이동가능한 지역을 조회 할 지역을 입력하세요  :";
    cin >> area;

    if(game_master.get_gameMap()->get_occupationPlayer(area)!=this->_player_name)
        cout << "자신의 지역이 아닙니다. " << endl;

    else {
        movableArea = game_master.get_gameMap()->get_movableArea(area);
       for(int i=0; i<30; i++){
           if(movableArea[i]=="NO")
               break;
           cout << movableArea[i] << endl;
       }
    }
}

bool Player::is_yourArea(string area, bool vervose) {

    if (!game_master.isVaildArea(area))
    {
        if (vervose == true) cout << "존재하지 않는 지역입니다." << endl;
        return false;
    }

    if(game_master.get_gameMap()->get_occupationPlayer(area)!=this->_player_name) {
        if (vervose == true) cout << "자신의 지역이 아닙니다. " << endl;
        return false;
    }
    if(game_master.get_gameMap()->get_occupationPlayer(area)!=this->_player_name) {
        if (vervose == true) cout << "자신의 지역이 아닙니다. " << endl;
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
    cout << "금  : " << get_myResource()->get_resource_gold() << endl;
    cout << "음식 : " << get_myResource()->get_resource_food() <<endl;
    cout << "물  : " << get_myResource()->get_resource_water() << endl;
}

void Player::show_myWholePlace(int *place) {

    cout << this->get_player_name() << " 가 소유하는 지역을 조회합니다...." << endl;
    cout << this->get_player_name() << " 님이 소유하는 지역 " << endl;
    for(int i=0; i<30; i++){
        if(place[i]==1)
            cout <<  game_master.get_gameMap()->findArea(i).areaname << endl;
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


