#include "resource.h"
#include <iostream>
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
    string _unit_type;//병종 Infantry(보병)=0, Archer(궁수)=1, Cavalry(기병)=2, Navy(?�군)=3
    int _attack_damage;//공격 infantry(보병)=10, Archer(궁수)=10, Cavalry(기병)=20, Navy(?�군)=20
    int _hit_point;//체력 infantry(보병)=50, Archer(궁수)=30, Cavalry(기병)=100, Navy(?�군)=20
    int _resource_gold;//�?infantry(보병)=10, Archer(궁수)=10, Cavalry(기병)=20, Navy(?�군)=10
    int _resource_water;//�?infantry(보병)=10, Archer(궁수)=5, Cavalry(기병)=10, Navy(?�군)=20
    int _resource_food;//?�식 infantry(보병)=10, Archer(궁수)=5, Cavalry(기병)=10, Navy(?�군)=20
    int _troop_production;//?�턴?�산병력 infantry(보병)=50, Archer(궁수)=3, Cavalry(기병)=2, Navy(?�군)=2
    int _moving_range;//?�턴?�동범위 infantry(보병)=2, Archer(궁수)=1, Cavalry(기병)=3, Navy(?�군)=2
    int _moving_area_type;//?�동?????�는 지???�성	--?�정?�요--	??0, �?1, ??�?2		infantry(보병)=0(?�정?�항-upgrade to 2), Archer(궁수)=0, Cavalry(기병)=0, Navy(?�군)=2
    int _attack_range;//공격가?�범??infantry(보병)=1, Archer(궁수)=2, Cavalry(기병)=1, Navy(?�군)=3
    int _unit_cnt;//?�닛??
public:
    //constructor

    Unit();
    //Unit(int);

    //?�멸??    
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
    void set_moving_area_type(int movingareatype);//보병??물에???�닐???�게 ?�다�??�용
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

    //?�수

 

    //������ �����ؼ� ��ȭ�ϴ� ��뺴���� ���� ���   
	virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);

};


//보병
class Unit_Infantry : public Unit{
private:

protected:

public:
    //?�성??    
	Unit_Infantry();
    //?�멸??    
	~Unit_Infantry();
    //������ �����ؼ� ��ȭ�ϴ� ��뺴���� ���� ���   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//궁수
class Unit_Archer : public Unit{
private:

protected:

public:
    //?�성??    
	Unit_Archer();
    //?�멸??    
	~Unit_Archer();
    //������ �����ؼ� ��ȭ�ϴ� ��뺴���� ���� ���   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//기병
class Unit_Cavalry : public Unit{
private:

protected:

public:
    //?�성??    
	Unit_Cavalry();
    //?�멸??    
	~Unit_Cavalry();
    //������ �����ؼ� ��ȭ�ϴ� ��뺴���� ���� ���   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//?�군
class Unit_Navy : public Unit{
private:

protected:

public:
    //?�성??    
	Unit_Navy();
    //?�멸??    
	~Unit_Navy();
    //������ �����ؼ� ��ȭ�ϴ� ��뺴���� ���� ���   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};