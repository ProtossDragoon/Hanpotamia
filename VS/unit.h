#include "resource.h"
#include <iostream>
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
    string _unit_type;//병종 Infantry=0, Archer=1, Cavalry=2, Navy=3
    int _attack_damage;//공격력 infantry=10, Archer=10, Cavalry=20, Navy=20
    int _hit_point;//체력 infantry=50, Archer=30, Cavalry=100, Navy=20
    int _resource_gold;//자원 금 infantry=10, Archer=10, Cavalry=20, Navy=10
    int _resource_water;//자원 물 infantry=10, Archer=5, Cavalry=10, Navy=20
    int _resource_food;//자원 음식 infantry=10, Archer=5, Cavalry=10, Navy=20
    int _troop_production;//한번에 생산할 수 있는 병수 infantry=50, Archer=3, Cavalry=2, Navy=2
    int _moving_range;//최대이동거리 infantry=2, Archer=1, Cavalry=3, Navy=2
    int _moving_area_type;//이동할 수있는지역
    int _attack_range;//공격사거리 infantry=1, Archer=2, Cavalry=1, Navy=3
    int _unit_cnt;//인원수
public:
    //constructor
    Unit();

    //소멸자   
	~Unit();


    //setter
    void set_unit_type(string type);
    void set_attack_damage(int attackdamage);
    void set_hit_point(int hp);
    void set_resource_gold(int gold);
    void set_resource_water(int water);
    void set_resource_food(int food);
    void set_troop_production(int troopproduction);
    void set_moving_range(int movingrange);
    void set_moving_area_type(int movingareatype);
    void set_attack_range(int attackrange);
    void set_unit_cnt(int cnt);

    //getter
    string get_unit_type() { return _unit_type; };
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

    //func
    //병력이 공격해서 변화하는 상대병력의 수를 계산   
	void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
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
    //병력이 공격해서 변화하는 상대병력의 수를 계산   
    void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
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
    //병력이 공격해서 변화하는 상대병력의 수를 계산   
    void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
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
    //병력이 공격해서 변화하는 상대병력의 수를 계산   
    void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//해군
class Unit_Navy : public Unit{
private:

protected:

public:
    //생성자    
	Unit_Navy();
    //소멸자  
	~Unit_Navy();
    //병력이 공격해서 변화하는 상대병력의 수를 계산   
    void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};