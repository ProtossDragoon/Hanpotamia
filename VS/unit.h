#include "resource.h"
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
	int _unit_type;//병종 infantry(보병)=0, Archer(궁수)=1, Cavalry(기병)=2, Navy(수군)=3
	int _attack_damage;//공격 infantry(보병)=10, Archer(궁수)=10, Cavalry(기병)=20, Navy(수군)=20
	int _hit_point;//체력 infantry(보병)=50, Archer(궁수)=30, Cavalry(기병)=100, Navy(수군)=20
	int _resource_gold;//금 infantry(보병)=10, Archer(궁수)=10, Cavalry(기병)=20, Navy(수군)=10
	int _resource_water;//물 infantry(보병)=10, Archer(궁수)=5, Cavalry(기병)=10, Navy(수군)=20
	int _resource_food;//음식 infantry(보병)=10, Archer(궁수)=5, Cavalry(기병)=10, Navy(수군)=20
	int _troop_production;//한턴생산병력 infantry(보병)=50, Archer(궁수)=3, Cavalry(기병)=2, Navy(수군)=2
	int _moving_range;//한턴이동범위 infantry(보병)=2, Archer(궁수)=1, Cavalry(기병)=3, Navy(수군)=2
	int _moving_area_type;//이동할 수 있는 지역 특성	--수정필요--	땅=0, 물=1, 땅+물=2		infantry(보병)=0(수정사항-upgrade to 2), Archer(궁수)=0, Cavalry(기병)=0, Navy(수군)=2
	int _attack_range;//공격가능범위 infantry(보병)=0, Archer(궁수)=1, Cavalry(기병)=0, Navy(수군)=2

public:
	//constructor

	Unit();
	//Unit(int);

	//소멸자

	//~Unit();

	/*Unit::Unit(int new_UnitType, int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_MovingAreaType, int new_AttackRange){
		UnitType=new_UnitType;
		AttackDamage=new_AttackDamage;
		HitPoint=new_HitPoint;
		Resource_Gold=new_Resource_Gold;
		Resource_Water=new_Resource_Water;
		Resource_Food=new_Resource_Food;
		TroopProduction=new_TroopProduction;
		MovingRange=new_MovingRange;
		MovingAreaType=new_MovingAreaType;
		AttackRange=new_AttackRange;
	}*/ //생성자들은 나중에 수정

	//setter 사실상 필요없을듯
	void set_unit_type(int type);
	void set_attack_damage(int attackdamage);
	void set_hit_point(int hp);
	void set_resource_gold(int gold);
	void set_resource_water(int water);
	void set_resource_food(int food);
	void set_troop_production(int troopproduction);
	void set_moving_range(int movingrange);
	void set_moving_area_type(int movingareatype);//보병이 물에서 다닐수 있게 한다면 사용
	void set_attack_range(int attackrange);

	//getter
	int get_unit_type() { return _unit_type; };
	int get_attack_damage() { return _attack_damage; };
	int get_hit_point() { return _hit_point; };
	int get_resource_gold() { return _resource_gold; };
	int get_resource_water() { return _resource_water; };
	int get_resource_food() { return _resource_food; };
	int get_troop_production() { return _troop_production; };
	int get_moving_range() { return _moving_range; };
	int get_moving_area_type() { return _moving_area_type; };
	int get_attack_range() { return _attack_range; };

	//함수
	//void pro.product(tendency, product_count);//병과, 생산 개수 인자로->palyer정보 조회해서 생산가능한지 검사
};


//보병
class Unit_Infantry : public Unit{
private:
	//int UnitType=0;
protected:

public:
	//생성자
	//Unit_Infantry(int new_unit_type, int new_attack_damage, int new_hit_point, int new_resource_gold, int new_resource_water, int new_resource_food, int new_troop_production, int new_moving_range, int new_moving_area_type, int new_attack_range) :Unit(new_unit_type, new_attack_damage, new_hit_point, new_resource_gold, new_resource_water, new_resource_food, new_troop_production, new_moving_range, new_moving_area_type, new_attack_range) {};
	Unit_Infantry();
};

//궁수
class Unit_Archer : public Unit{
private:
	
protected:

public:
	//생성자
	Unit_Archer();
};

//기병
class Unit_Cavalry : public Unit{
private:
	
protected:

public:
	//생성자
	Unit_Cavalry();
};

//수군
class Unit_Navy : public Unit{
private:

protected:

public:
	//생성자
	Unit_Navy();
};