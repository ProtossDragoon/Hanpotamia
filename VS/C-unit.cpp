#include <iostream>
#include "master.h"
#include "unit.h"
#include "player.h"
#include "string.h"
#include "map.h"

// extern master
extern Master game_master;

//constructor
Unit::Unit()
{
    _unit_type = " ";
    _attack_damage = 0;
    _hit_point = 0;
    _resource_gold = 0;
    _resource_water = 0;
    _resource_food = 0;
    _troop_production = 0;
    _moving_range = 0;
    _moving_area_type = 0;
    _attack_range = 0;
    _unit_cnt = 0;
}

Unit::~Unit() {}

Unit_Infantry::Unit_Infantry() : Unit()
{
    _unit_type = "Infantry";
    _attack_damage = 10;
    _hit_point = 50;
    _resource_gold = 10;
    _resource_water = 10;
    _resource_food = 10;
    _troop_production = 5;
    _moving_range = 2;
    _moving_area_type = 0;
    _attack_range = 1;
    _unit_cnt = 0;
}

Unit_Infantry::~Unit_Infantry() {}

Unit_Archer::Unit_Archer() : Unit()
{
    _unit_type = "Archer";
    _attack_damage = 10;
    _hit_point = 30;
    _resource_gold = 10;
    _resource_water = 5;
    _resource_food = 5;
    _troop_production = 3;
    _moving_range = 1;
    _moving_area_type = 0;
    _attack_range = 2;
    _unit_cnt = 0;
}

Unit_Archer::~Unit_Archer() {}

Unit_Cavalry::Unit_Cavalry() : Unit()
{
    _unit_type = "Cavalry";
    _attack_damage = 10;
    _hit_point = 50;
    _resource_gold = 10;
    _resource_water = 10;
    _resource_food = 10;
    _troop_production = 5;
    _moving_range = 2;
    _moving_area_type = 0;
    _attack_range = 1;
    _unit_cnt = 0;
}

Unit_Cavalry::~Unit_Cavalry() {}

Unit_Navy::Unit_Navy() : Unit()
{
    _unit_type = "Navy";
    _attack_damage = 20;
    _hit_point = 20;
    _resource_gold = 10;
    _resource_water = 20;
    _resource_food = 20;
    _troop_production = 2;
    _moving_range = 2;
    _moving_area_type = 2;
    _attack_range = 3;
    _unit_cnt = 0;
}

Unit_Navy::~Unit_Navy() {}

//Unit setter
void Unit::set_unit_type(string type)
{
    _unit_type = type;
}
void Unit::set_attack_damage(int attackdamage)
{
    _attack_damage = attackdamage;
}
void Unit::set_hit_point(int hp)
{
    _hit_point = hp;
}
void Unit::set_resource_gold(int gold)
{
    _resource_gold = gold;
}
void Unit::set_resource_water(int water)
{
    _resource_water = water;
}
void Unit::set_resource_food(int food)
{
    _resource_food = food;
}
void Unit::set_troop_production(int troopproduction)
{
    _troop_production = troopproduction;
}
void Unit::set_moving_range(int movingrange)
{
    _moving_range = movingrange;
}
void Unit::set_moving_area_type(int movingareatype)
{
    _moving_area_type = movingareatype;
}
void Unit::set_attack_range(int attackrange)
{
    _attack_range = attackrange;
}
void Unit::set_unit_cnt(int cnt)
{
    _unit_cnt = cnt;
}





void Unit::calculate_unit(string to, string underattack_tendency, string attack_tendency, int cnt)//전투계산은 공격하는 병종의 공격력과 인원수의 곱(totalattackdamage)를 상대방의 전체체력(totalhp)에서
{                                                                                                 //뺀 후에 남은 int를 상대방의 한 기당 체력과 인원수로 나누어 남은 인원수를 구하는 방식으로 함
    Map* searching=game_master.get_gameMap();
    int totalattackdamage;
    int totalhp;
    int leftcnt;
    Army army = searching->get_areaInformation(to).areaunit;//to의병력정보


    //공격대상의 총 공격력
    if (attack_tendency == "Archer")
    {
        Unit_Archer a;
        totalattackdamage = a.get_attack_damage() * cnt;
    }
    else if (attack_tendency == "Infantry")
    {
        Unit_Infantry a;
        totalattackdamage = a.get_attack_damage() * cnt;
    }
    else if (attack_tendency == "Cavalry")
    {
        Unit_Cavalry a;
        totalattackdamage = a.get_attack_damage() * cnt;
    }
    else if (attack_tendency == "Navy")
    {
        Unit_Navy a;
        totalattackdamage = a.get_attack_damage() * cnt;
    }

    //공격받는 대상의 체력 + calculate
    if (underattack_tendency == "Archer")
    {
        Unit_Archer archer;
        totalhp = (archer.get_hit_point()) * army.Archercount;
        totalhp -= totalattackdamage;
        leftcnt = totalhp /army.Archercount;
        leftcnt = totalhp / archer.get_hit_point();
        searching->set_unit(to, underattack_tendency, leftcnt);
    }
    else if (underattack_tendency == "Cavalry")
    {
        Unit_Cavalry cavalry;
        totalhp = (cavalry.get_hit_point()) * army.Cavalrycount;
        totalhp -= totalattackdamage;
        leftcnt = totalhp /army.Cavalrycount;
        leftcnt = totalhp / cavalry.get_hit_point();
        searching->set_unit(to, underattack_tendency, leftcnt);
    }
    else if (underattack_tendency == "Infantry")
    {
        Unit_Infantry infantry;
        totalhp = (infantry.get_hit_point()) * army.Infantrycount;
        totalhp -= totalattackdamage;
        leftcnt = totalhp /army.Infantrycount;
        leftcnt = totalhp / infantry.get_hit_point();
        searching->set_unit(to, underattack_tendency, leftcnt);
    }
    else if (underattack_tendency == "Navy")
    {
        Unit_Navy navy;
        totalhp = (navy.get_hit_point()) * army.Navycount;
        totalhp -= totalattackdamage;
        leftcnt = totalhp /army.Navycount;
        leftcnt = totalhp / navy.get_hit_point();
        searching->set_unit(to, underattack_tendency, leftcnt);
    }
}
