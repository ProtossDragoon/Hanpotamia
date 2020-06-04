#include "unit.h"
#include "player.h"
#include "string.h""


//constructor
Unit::Unit()
{
	_unit_type = 0;
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
	_unit_type = 0;
	_attack_damage = 10;
	_hit_point = 50;
	_resource_gold = 10;
	_resource_water = 10;
	_resource_food = 10;
	_troop_production = 5;
	_moving_range = 2;
	_moving_area_type = 0;//수정
	_attack_range = 0;
	_unit_cnt = 0;
}

Unit_Infantry::~Unit_Infantry() {}

Unit_Archer::Unit_Archer() : Unit() 
{
	_unit_type = 1;
	_attack_damage = 10;
	_hit_point = 30;
	_resource_gold = 10;
	_resource_water = 5;
	_resource_food = 5;
	_troop_production = 3;
	_moving_range = 1;
	_moving_area_type = 0;//수정
	_attack_range = 1;
	_unit_cnt = 0;
}

Unit_Archer::~Unit_Archer() {}

Unit_Cavalry::Unit_Cavalry() : Unit() 
{
	_unit_type = 2;
	_attack_damage = 10;
	_hit_point = 50;
	_resource_gold = 10;
	_resource_water = 10;
	_resource_food = 10;
	_troop_production = 5;
	_moving_range = 2;
	_moving_area_type = 0;//수정
	_attack_range = 0;
	_unit_cnt = 0;
}

Unit_Cavalry::~Unit_Cavalry() {}

Unit_Navy::Unit_Navy() : Unit() 
{
	_unit_type = 3;
	_attack_damage = 20;
	_hit_point = 20;
	_resource_gold = 10;
	_resource_water = 20;
	_resource_food = 20;
	_troop_production = 2;
	_moving_range = 2;
	_moving_area_type = 2;//수정
	_attack_range = 2;
	_unit_cnt = 0;
}

Unit_Navy::~Unit_Navy() {}

//Unit setter
void Unit::set_unit_type(int type)
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
void Unit::set_moving_area_type(int movingareatype)//보병이 물에서 다닐수 있게 한다면 사용
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

//func

void AddUnit()
{
	
}

void UnitProduct(string *tendency, int product_count)
{
	if (tendency=="Cavalry") {
		
	}
}