#include "resource.h"
#include <iostream>
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
	int _unit_type;//병종 Infantry(보병)=0, Archer(궁수)=1, Cavalry(기병)=2, Navy(수군)=3
	int _attack_damage;//공격 infantry(보병)=10, Archer(궁수)=10, Cavalry(기병)=20, Navy(수군)=20
	int _hit_point;//체력 infantry(보병)=50, Archer(궁수)=30, Cavalry(기병)=100, Navy(수군)=20
	int _resource_gold;//금 infantry(보병)=10, Archer(궁수)=10, Cavalry(기병)=20, Navy(수군)=10
	int _resource_water;//물 infantry(보병)=10, Archer(궁수)=5, Cavalry(기병)=10, Navy(수군)=20
	int _resource_food;//음식 infantry(보병)=10, Archer(궁수)=5, Cavalry(기병)=10, Navy(수군)=20
	int _troop_production;//한턴생산병력 infantry(보병)=50, Archer(궁수)=3, Cavalry(기병)=2, Navy(수군)=2
	int _moving_range;//한턴이동범위 infantry(보병)=2, Archer(궁수)=1, Cavalry(기병)=3, Navy(수군)=2
	int _moving_area_type;//이동할 수 있는 지역 특성	--수정필요--	땅=0, 물=1, 땅+물=2		infantry(보병)=0(수정사항-upgrade to 2), Archer(궁수)=0, Cavalry(기병)=0, Navy(수군)=2
	int _attack_range;//공격가능범위 infantry(보병)=0, Archer(궁수)=1, Cavalry(기병)=0, Navy(수군)=2
	int _unit_cnt;//유닛수

public:
	//constructor

	Unit();
	//Unit(int);

	//소멸자
	~Unit();


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
	void set_unit_cnt(int cnt);

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
	int get_unit_cnt() { return _unit_cnt; };

	//함수

	//병종과 수를 받아서 map에 함수추가
	void UnitProduct(string tendency, int product_count);


	//Unit객체들이 합쳤을 때 함수
	void AddUnit();

	//전투결과반영함수 총체력, 공격유닛, 지역이름
	void calcualte_unit();

};


//보병
class Unit_Infantry : public Unit{
private:
	
protected:

public:
	//생성자
	Unit_Infantry();
	//소멸자
	~Unit_Infantry();
};

//궁수
class Unit_Archer : public Unit{
private:
	
protected:

public:
	//생성자
	Unit_Archer();
	//소멸자
	~Unit_Archer();
};

//기병
class Unit_Cavalry : public Unit{
private:
	
protected:

public:
	//생성자
	Unit_Cavalry();
	//소멸자
	~Unit_Cavalry();
};

//수군
class Unit_Navy : public Unit{
private:

protected:

public:
	//생성자
	Unit_Navy();
	//소멸자
	~Unit_Navy();
};